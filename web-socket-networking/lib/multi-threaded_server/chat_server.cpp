#include "chat_server.h"
#include "LocalMessages.h"
using boost::asio::ip::tcp;
using namespace boost::placeholders;
using namespace std;

namespace
{
std::string getTimestamp()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime(&t);
    std::stringstream ss;
    ss << '[' << (now->tm_year + 1900) << '-' << std::setfill('0')
       << std::setw(2) << (now->tm_mon + 1) << '-' << std::setfill('0')
       << std::setw(2) << now->tm_mday << ' ' << std::setfill('0')
       << std::setw(2) << now->tm_hour << ":" << std::setfill('0')
       << std::setw(2) << now->tm_min << ":" << std::setfill('0')
       << std::setw(2) << now->tm_sec << "] ";

    return ss.str();
}

void workerThread::run(std::shared_ptr<boost::asio::io_service> io_service)
{
    {
        std::lock_guard < std::mutex > lock(m);
        std::cout << "[" << std::this_thread::get_id() << "] Thread starts" << std::endl;
    }

    io_service->run();

    {
        std::lock_guard < std::mutex > lock(m);
        std::cout << "[" << std::this_thread::get_id() << "] Thread ends" << std::endl;
    }

}
}

void chatRoom::enter(std::shared_ptr<participant> participant, const std::string & nickname)
{
    participants_.insert(participant);
    name_table_[participant] = nickname;
    name_table_reverse[nickname] = participant;
    std::for_each(recent_msgs_.begin(), recent_msgs_.end(),
                    boost::bind(&participant::onMessage, participant, _1));
}

void chatRoom::leave(std::shared_ptr<participant> participant)
{
    participants_.erase(participant);
    name_table_.erase(participant);
}
//general broadcast used from client-client communication
void chatRoom::broadcast(std::array<char, MAX_IP_PACK_SIZE>& msg, std::shared_ptr<participant> participant)
{
    std::string timestamp = getTimestamp();
    std::string nickname = getNickname(participant);
    std::array<char, MAX_IP_PACK_SIZE> formatted_msg;

    // boundary correctness is guarded by protocol.hpp
    strcpy(formatted_msg.data(), timestamp.c_str());
    strcat(formatted_msg.data(), nickname.c_str());
    strcat(formatted_msg.data(), msg.data());

    recent_msgs_.push_back(formatted_msg);
    while (recent_msgs_.size() > max_recent_msgs)
    {
        recent_msgs_.pop_front();
    }

    std::for_each(participants_.begin(), participants_.end(),
                    boost::bind(&participant::onMessage, _1, std::ref(formatted_msg)));
}
//communication from server-specific client
void chatRoom::broadcast(std::array<char, MAX_IP_PACK_SIZE>& msg, uint8_t id)
{
    std::string timestamp = getTimestamp();
    std::array<char, MAX_IP_PACK_SIZE> formatted_msg;
    stringstream ss;
    ss << (unsigned int)id;
    strcpy(formatted_msg.data(), ss.str().c_str());
    // boundary correctness is guarded by protocol.hpp
    strcat(formatted_msg.data(), timestamp.c_str());
    strcat(formatted_msg.data(), "SERVER: ");
    strcat(formatted_msg.data(), msg.data());
    recent_msgs_.push_back(formatted_msg);
    while (recent_msgs_.size() > max_recent_msgs)
    {
        recent_msgs_.pop_front();
    }
    std::for_each(participants_.begin(), participants_.end(),
                    boost::bind(&participant::onMessage, _1, std::ref(formatted_msg)));
}
//communication from server-all clients
void chatRoom::broadcast(std::array<char, MAX_IP_PACK_SIZE>& msg)
{
    std::string timestamp = getTimestamp();
    std::array<char, MAX_IP_PACK_SIZE> formatted_msg;
    // boundary correctness is guarded by protocol.hpp
    strcat(formatted_msg.data(), timestamp.c_str());
    strcat(formatted_msg.data(), "SERVER: ");
    strcat(formatted_msg.data(), msg.data());
    recent_msgs_.push_back(formatted_msg);
    while (recent_msgs_.size() > max_recent_msgs)
    {
        recent_msgs_.pop_front();
    }
    std::for_each(participants_.begin(), participants_.end(),
                    boost::bind(&participant::onMessage, _1, std::ref(formatted_msg)));
}
std::string chatRoom::getNickname(std::shared_ptr<participant> participant)
{
    return name_table_[participant];
}
tcp::socket& personInRoom::socket() { return socket_; }

void personInRoom::start()
{
    boost::asio::async_read(socket_,
                            boost::asio::buffer(nickname_, nickname_.size()),
                            strand_.wrap(boost::bind(&personInRoom::nicknameHandler, shared_from_this(), _1)));
}
void personInRoom::onMessage(std::array<char, MAX_IP_PACK_SIZE>& msg)
{
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
        boost::asio::async_write(socket_,
                                    boost::asio::buffer(write_msgs_.front(), write_msgs_.front().size()),
                                    strand_.wrap(boost::bind(&personInRoom::writeHandler, shared_from_this(), _1)));
    }
}
void personInRoom::nicknameHandler(const boost::system::error_code& error)
{
    if (strlen(nickname_.data()) <= MAX_NICKNAME - 2)
    {
        strcat(nickname_.data(), ": ");
    }
    else
    {
        //cut off nickname if too long
        nickname_[MAX_NICKNAME - 2] = ':';
        nickname_[MAX_NICKNAME - 1] = ' ';
    }

    room_.enter(shared_from_this(), std::string(nickname_.data()));

    boost::asio::async_read(socket_,
                            boost::asio::buffer(read_msg_, read_msg_.size()),
                            strand_.wrap(boost::bind(&personInRoom::readHandler, shared_from_this(), _1)));
}

void personInRoom::readHandler(const boost::system::error_code& error)
{
    if (!error)
    {
        room_.broadcast(read_msg_, shared_from_this());

        boost::asio::async_read(socket_,
                                boost::asio::buffer(read_msg_, read_msg_.size()),
                                strand_.wrap(boost::bind(&personInRoom::readHandler, shared_from_this(), _1)));
    }
    else
    {
        room_.leave(shared_from_this());
    }
}

void personInRoom::writeHandler(const boost::system::error_code& error)
{
    if (!error)
    {
        write_msgs_.pop_front();

        if (!write_msgs_.empty())
        {
            boost::asio::async_write(socket_,
                                        boost::asio::buffer(write_msgs_.front(), write_msgs_.front().size()),
                                        strand_.wrap(boost::bind(&personInRoom::writeHandler, shared_from_this(), _1)));
        }
    }
    else
    {
        room_.leave(shared_from_this());
    }
}

void server::run()
{
    std::shared_ptr<personInRoom> new_participant(new personInRoom(io_service_, strand_, room_));
    acceptor_.async_accept(new_participant->socket(), strand_.wrap(boost::bind(&server::onAccept, this, new_participant, _1)));
}

void server::onAccept(std::shared_ptr<personInRoom> new_participant, const boost::system::error_code& error)
{
    if (!error)
    {
        new_participant->start();
    }

    run();
}


//----------------------------------------------------------------------
/* This thread and its corresponding helper functions are responsible for accepting and validating (join/create) commands 
    sent from the clients. A map is used to keep track of the unique room# codes assigned to each available port
*/
std::mutex roomMutex;
std::string createRoom(int &nextPort, std::unordered_map<std::string,std::string> &roomInfo,std::vector<uint8_t> &playerNums)
{
    //Uses mutex to update roomInfo map and increment port number for thread-safety
    std::lock_guard<std::mutex> guard(roomMutex);
    nextPort++;
    // boost::uuids::uuid uuid = boost::uuids::random_generator()();
    // std::cout << uuid << std::endl;
    hash<std::string> hashfunc;
    std::cout << hashfunc(std::to_string(nextPort)) <<std::endl;
    fflush(stdout);
    auto key = hashfunc(std::to_string(nextPort));
    roomInfo.insert({std::to_string(key),std::to_string(nextPort)});
    //playerNums[nextPort-4000]++;
    return std::to_string(nextPort) + " " + std::to_string(key);
}

std::string validateRoom(std::string code,std::unordered_map<std::string,std::string> &roomInfo,std::vector<uint8_t> &playerNums)
{
    std::lock_guard<std::mutex> guard(roomMutex);
    if (auto search = roomInfo.find(code); search != roomInfo.end()){
        std::cout<<"Found: "<<search->second<<std::endl;
        fflush(stdout);
        return search->second + " " + std::to_string(++playerNums[std::stoi(search->second)-4000]);
    }
    std::cout <<"Not found\n";
    fflush(stdout);
    return "-1";
}

int mainServer(std::shared_ptr<server> s){
    // Initialize server socket..
    TCPServer tcpServer;

    /*** Game room variables ***/
    // Map of room# to port#
    std::unordered_map<std::string,std::string> roomInfo;
    int nextPort = 3999;
    std::vector<uint8_t> playerNums(10, 0);

    // When a new client connected:
    tcpServer.onNewConnection = [&](TCPSocket *newClient) {
        cout << "New client: [";
        cout << newClient->remoteAddress() << ":" << newClient->remotePort() << "]" << endl;

        newClient->onMessageReceived = [newClient,&nextPort,&roomInfo,&playerNums](string message) {
            cout << newClient->remoteAddress() << ":" << newClient->remotePort() << " => " << message << endl;
            if(strcmp(message.data(),"join")==0){
                //wait for next message that contains the code

            }else if(strcmp(message.data(),"create")==0){
                //create new room
                std::cout<< "Creating new room\n";
                auto k = createRoom(nextPort,roomInfo,playerNums);
                newClient->Send("create "+k);
                sleep(INT_MAX);
            }else{
                std::cout<<"Validating...\n";
                auto v = validateRoom(message.data(),roomInfo,playerNums);
                newClient->Send("join "+v);
            }
        };

        //
        newClient->onSocketClosed = [newClient](int errorCode) {
            cout << "Socket closed:" << newClient->remoteAddress() << ":" << newClient->remotePort() << " -> " << errorCode << endl;
            cout << flush;
        };
    };

    // Bind the server to a port.
    tcpServer.Bind(8888, [](int errorCode, string errorMessage) {
        // BINDING FAILED:
        cout << errorCode << " : " << errorMessage << endl;
    });

    // Start Listening the server.
    tcpServer.Listen([](int errorCode, string errorMessage) {
        // LISTENING FAILED:
        cout << errorCode << " : " << errorMessage << endl;
    });

    string input;
    getline(cin, input);
    while (input != "exit\n")
    {
        if(input == "sean")
        {
            std::cout << "asd" << std::endl;
            std::unique_ptr<LocalMessage> l (new LocalMessage("Player 1, choose your weapon!", (uint8_t)0, s));
            l.get()->runRule();
        }
        getline(cin, input);
    }

    // Close the server before exiting the program.
    tcpServer.Close();

    return 0;
}
//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
    std::shared_ptr<server> serv;
    try
    {
        if (argc < 2)
        {
            std::cerr << "Usage: chat_server <port> [<port> ...]\n";
            return 1;
        }
        std::shared_ptr<boost::asio::io_service> io_service(new boost::asio::io_service);
        boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(*io_service));
        boost::shared_ptr<boost::asio::io_service::strand> strand(new boost::asio::io_service::strand(*io_service));

        std::cout << "[" << std::this_thread::get_id() << "]" << "server starts" << std::endl;

        std::list < std::shared_ptr < server >> servers;
        for (int i = 1; i < argc; ++i)
        {
            tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
            std::shared_ptr<server> a_server(new server(*io_service, *strand, endpoint));
            servers.push_back(a_server);
        }
        serv = servers.front();
        std::thread main_thread(mainServer, serv);
        boost::thread_group workers;
        for (int i = 0; i < 1; ++i)
        {
            boost::thread * t = new boost::thread{ boost::bind(&workerThread::run, io_service) };

#ifdef __linux__
            // bind cpu affinity for worker thread in linux
            cpu_set_t cpuset;
            CPU_ZERO(&cpuset);
            CPU_SET(i, &cpuset);
            pthread_setaffinity_np(t->native_handle(), sizeof(cpu_set_t), &cpuset);
#endif
            workers.add_thread(t);
        }

        workers.join_all();
    } catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}
