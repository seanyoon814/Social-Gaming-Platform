#include <deque>
#include <array>
#include <thread>
#include <iostream>
#include <cstring>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include "protocol.hpp"
#include <boost/algorithm/string.hpp>
#include "include/tcpsocket.hpp"


using boost::asio::ip::tcp;
using namespace boost::placeholders;
using namespace std;

class client
{
public:
    client(const std::array<char, MAX_NICKNAME>& nickname,
            boost::asio::io_service& io_service, 
            uint8_t playerID,
            tcp::resolver::iterator endpoint_iterator) :
            io_service_(io_service), socket_(io_service)
    {

        strcpy(nickname_.data(), nickname.data());
        memset(read_msg_.data(), '\0', MAX_IP_PACK_SIZE);
        boost::asio::async_connect(socket_, endpoint_iterator, boost::bind(&client::onConnect, this, _1));
    }

    void write(const std::array<char, MAX_IP_PACK_SIZE>& msg)
    {
        io_service_.post(boost::bind(&client::writeImpl, this, msg));
    }

    void close()
    {
        io_service_.post(boost::bind(&client::closeImpl, this));
    }
    void setID(uint8_t id)
    {
        playerNum = id;
    }
private:

    void onConnect(const boost::system::error_code& error)
    {
        if (!error)
        {
            boost::asio::async_write(socket_,
                                     boost::asio::buffer(nickname_, nickname_.size()),
                                     boost::bind(&client::readHandler, this, _1));
        }
    }

    void readHandler(const boost::system::error_code& error)
    {
        //check to see if its a direct message (LocalMessage), or regular message (global)
        std::string str = read_msg_.data();
        if(str[0] != '[' && !str.empty())
        {
            std::stringstream ss;
            for(auto &ch : str)
            {
                if(ch == '[')
                {
                    break;
                }
                ss << ch;
            }
            auto s = stoi(ss.str());
            if(playerNum == s)
            {
                // std::string removeID = read_msg_.data();
                // size_t ind = removeID.find(playerNum);
                // removeID.erase(ind, 1);
                std::cout << read_msg_.data() << std::endl;
            }
        }
        else
        {
            std::cout << read_msg_.data() << std::endl;
        }
        if(!error)
        {
            boost::asio::async_read(socket_,
                                    boost::asio::buffer(read_msg_, read_msg_.size()),
                                    boost::bind(&client::readHandler, this, _1));
        }
        else
        {
            closeImpl();
        }
    }

    void writeImpl(std::array<char, MAX_IP_PACK_SIZE> msg)
    {
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(msg);
        if (!write_in_progress)
        {
            boost::asio::async_write(socket_,
                                     boost::asio::buffer(write_msgs_.front(), write_msgs_.front().size()),
                                     boost::bind(&client::writeHandler, this, _1));
        }
    }

    void writeHandler(const boost::system::error_code& error)
    {
        if (!error)
        {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
                boost::asio::async_write(socket_,
                                         boost::asio::buffer(write_msgs_.front(), write_msgs_.front().size()),
                                         boost::bind(&client::writeHandler, this, _1));
            }
        } else
        {
            closeImpl();
        }
    }

    void closeImpl()
    {
        socket_.close();
    }
    uint8_t playerNum;
    boost::asio::io_service& io_service_;
    tcp::socket socket_;
    std::array<char, MAX_IP_PACK_SIZE> read_msg_;
    std::deque<std::array<char, MAX_IP_PACK_SIZE>> write_msgs_;
    std::array<char, MAX_NICKNAME> nickname_;
};

class audience{
    public:
    audience(const std::array<char, MAX_NICKNAME>& nickname,
            boost::asio::io_service& io_service, 
            uint8_t playerID,
            tcp::resolver::iterator endpoint_iterator) :
            io_service_(io_service), socket_(io_service)
    {

        strcpy(nickname_.data(), nickname.data());
        memset(read_msg_.data(), '\0', MAX_IP_PACK_SIZE);
        boost::asio::async_connect(socket_, endpoint_iterator, boost::bind(&audience::onConnect, this, _1));
    }

    void write(const std::array<char, MAX_IP_PACK_SIZE>& msg)
    {
        io_service_.post(boost::bind(&audience::writeImpl, this, msg));
    }

    void close()
    {
        io_service_.post(boost::bind(&audience::closeImpl, this));
    }
    void setID(uint8_t id)
    {
        playerNum = id;
    }
private:

    void onConnect(const boost::system::error_code& error)
    {
        if (!error)
        {
            boost::asio::async_write(socket_,
                                     boost::asio::buffer(nickname_, nickname_.size()),
                                     boost::bind(&audience::readHandler, this, _1));
        }
    }

    void readHandler(const boost::system::error_code& error)
    {
        //check to see if its a direct message (LocalMessage), or regular message (global)
        std::string str = read_msg_.data();
        if(str[0] != '[' && !str.empty())
        {
            std::stringstream ss;
            for(auto &ch : str)
            {
                if(ch == '[')
                {
                    break;
                }
                ss << ch;
            }
            auto s = stoi(ss.str());
            if(playerNum == s)
            {
                std::cout << read_msg_.data() << std::endl;
            }
        }
        else
        {
            std::cout << read_msg_.data() << std::endl;
        }
        if(!error)
        {
            boost::asio::async_read(socket_,
                                    boost::asio::buffer(read_msg_, read_msg_.size()),
                                    boost::bind(&audience::readHandler, this, _1));
        }
        else
        {
            closeImpl();
        }
    }

    void writeImpl(std::array<char, MAX_IP_PACK_SIZE> msg)
    {
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(msg);
        if (!write_in_progress)
        {
            boost::asio::async_write(socket_,
                                     boost::asio::buffer(write_msgs_.front(), write_msgs_.front().size()),
                                     boost::bind(&audience::writeHandler, this, _1));
        }
    }

    void writeHandler(const boost::system::error_code& error)
    {
        if (!error)
        {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
                boost::asio::async_write(socket_,
                                         boost::asio::buffer(write_msgs_.front(), write_msgs_.front().size()),
                                         boost::bind(&audience::writeHandler, this, _1));
            }
        } else
        {
            closeImpl();
        }
    }

    void closeImpl()
    {
        socket_.close();
    }
    uint8_t playerNum;
    boost::asio::io_service& io_service_;
    tcp::socket socket_;
    std::array<char, MAX_IP_PACK_SIZE> read_msg_;
    std::deque<std::array<char, MAX_IP_PACK_SIZE>> write_msgs_;
    std::array<char, MAX_NICKNAME> nickname_;
};
//----------------------------------------------------------------------
void mainClient(std::string& roomNum, uint8_t& playerNum, std::string& selectedcommand)
{
    bool joinedRoom = false;
    bool received = false;
    // Initialize socket.
    TCPSocket tcpSocket([](int errorCode, std::string errorMessage){
        cout << "Socket creation error:" << errorCode << " : " << errorMessage << endl;
    });

    // Start receiving from the host.
    tcpSocket.onMessageReceived = [&roomNum,&received,&playerNum](string message) {
        cout << "Message from the Server: " << message << endl;
        std::vector<std::string> strs;
        boost::split(strs, message.data(), boost::is_any_of("\t "));
        if(strs.size()>=2){
            if(strcmp(strs[0].c_str(),"create")==0){
                std::istringstream num;
                num.str(strs[1]+"\n");
                std::getline(num, roomNum);
                std::cout<<"Room created. Code: " << strs[2] <<std::endl;
            }else if(strcmp(strs[0].c_str(),"join")==0){
                if(std::stoi(strs[1].c_str()) != -1){
                    playerNum = std::stoi(strs[2].c_str());
                    std::istringstream num;
                    num.str(strs[1]+"\n");
                    std::getline(num, roomNum);
                }
                received = true;
            }
        }
    };
    
    // On socket closed:
    tcpSocket.onSocketClosed = [](int errorCode){
        cout << "Connection closed: " << errorCode << endl;
    };

    // Connect to the host.
    tcpSocket.Connect("localhost", 8888, [&] {
        cout << "Connected to the server successfully." << endl;
    },
    [](int errorCode, std::string errorMessage){
        // CONNECTION FAILED
        cout << errorCode << " : " << errorMessage << endl;
    });

    std::cout << "1.Create\n2.Join\n3.Join as Audience\n";
    while(true){
        try{
            std::getline(std::cin, selectedcommand);
            if(std::stoi(selectedcommand) < 1 || std::stoi(selectedcommand)>3){
                std::cerr <<"Invalid input\n";
            }else if(std::stoi(selectedcommand) ==1){
                //create new room
                playerNum = 0;
                tcpSocket.Send("create");
                while(roomNum.empty()){
                    //wait for response
                    sleep(0.01);
                }
                break;
            }else if (std::stoi(selectedcommand) ==2){ 
                //join room
                tcpSocket.Send("join");
                std::cout << "Enter room #:\n";
                std::string joinCode;
                while(true){
                    try{
                        std::getline(std::cin, joinCode);
                        tcpSocket.Send(joinCode);
                        while(!received){
                            //wait for server to validate
                            sleep(0.01);
                        }
                        received = false;
                        if(roomNum.empty()){
                            //invalid room number/port
                            std::cerr << "Invalid room number, try again:\n";
                        }else{
                            break;
                        }
                    }catch(std::exception& e){
                        std::cerr << "Invalid input --- Exception: " << e.what() << "\n";
                    }
                }                
                break;
            }
            else if (std::stoi(selectedcommand) ==3)
            {   
                tcpSocket.Send("join");
                std::cout << "Enter room #:\n";
                std::string joinCode;
                while(true){
                    try{
                        std::getline(std::cin, joinCode);
                        tcpSocket.Send(joinCode);
                        while(!received){
                            //wait for server to validate
                            sleep(0.01);
                        }
                        received = false;
                        if(roomNum.empty()){
                            //invalid room number/port
                            std::cerr << "Invalid room number, try again:\n";
                        }else{
                            break;
                        }
                    }catch(std::exception& e){
                        std::cerr << "Invalid input --- Exception: " << e.what() << "\n";
                    }
                }   
                break;
            }
        }catch (std::exception& e){
            std::cerr << "Exception: " << e.what() << "\n";
        }
    }

    tcpSocket.Close();

    return;
}
//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
    std::string roomNum;
    uint8_t playerNum=0;
    bool validRoom = false;
    std::string inputChoice;
    std::thread main_thread(mainClient, std::ref(roomNum), std::ref(playerNum), std::ref(inputChoice));
    try
    {
        if (argc != 4)
        {
            std::cerr << "Usage: chat_client <nickname> <host> <port>\n";
            return 1;
        }

        while(roomNum.empty() || validRoom){
            //Block until joined room
            sleep(0.1);
            try{
                auto r = std::stoi(roomNum);
            }catch(std::exception& e){
                continue;
            }
        }
        std::cout <<"Your player ID is " << std::to_string(playerNum) << " asd" << inputChoice << std::endl;

        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(argv[2], roomNum);
        tcp::resolver::iterator iterator = resolver.resolve(query);
        std::array<char, MAX_NICKNAME> nickname;
        strcpy(nickname.data(), argv[1]);

        client cli(nickname, io_service, playerNum, iterator);
        cli.setID(playerNum);
        std::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
        std::array<char, MAX_IP_PACK_SIZE> msg;
        if(inputChoice == "3")
        {
            while (true)
            {
                memset(msg.data(), '\0', msg.size());
                if (!std::cin.getline(msg.data(), MAX_IP_PACK_SIZE - PADDING - MAX_NICKNAME))
                {
                    std::cin.clear(); //clean up error bit and try to finish reading
                }
                strcat(msg.data(), "a&^bA");
                if(strcmp (msg.data(),"create") == 0){
                    // not in use currently
                    // cli.close();
                    // t.detach();  
                }
                else if(strcmp (msg.data(),"local") == 0)       
                {
                    
                }     
                else{
                    cli.write(msg);
                }            
            }
        }
        else
        {
            while (true)
            {
                memset(msg.data(), '\0', msg.size());
                if (!std::cin.getline(msg.data(), MAX_IP_PACK_SIZE - PADDING - MAX_NICKNAME))
                {
                    std::cin.clear(); //clean up error bit and try to finish reading
                }
                if(strcmp (msg.data(),"create") == 0){
                    // not in use currently
                    // cli.close();
                    // t.detach();  
                }
                else if(strcmp (msg.data(),"local") == 0)       
                {
                    
                }     
                else{
                    cli.write(msg);
                }            
            }
        }

        cli.close();
        t.join();
    } catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
