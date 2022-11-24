#pragma once
#include <ctime>
#include <string>
#include <deque>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <mutex>
#include <algorithm>
#include <iomanip>
#include <array>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/uuid/uuid.hpp>            
#include <boost/uuid/uuid_generators.hpp> 
#include <boost/uuid/uuid_io.hpp>         
#include "protocol.hpp"
#include "include/tcpserver.hpp"

using boost::asio::ip::tcp;
using namespace boost::placeholders;
using namespace std;

namespace
{
std::string getTimestamp();

class workerThread
{
public:
    static void run(std::shared_ptr<boost::asio::io_service> io_service);
private:
    static std::mutex m;
};

std::mutex workerThread::m;
}

class participant
{
public:
    virtual ~participant() {}
    virtual void onMessage(std::array<char, MAX_IP_PACK_SIZE> & msg) = 0;
};

class chatRoom {
public:
    void enter(std::shared_ptr<participant> participant, const std::string & nickname);

    void leave(std::shared_ptr<participant> participant);
    void broadcast(std::array<char, MAX_IP_PACK_SIZE>& msg);
    void broadcast(std::array<char, MAX_IP_PACK_SIZE>& msg, std::shared_ptr<participant> participant);
    void broadcast(std::array<char, MAX_IP_PACK_SIZE>& msg, uint8_t id);
    std::string getNickname(std::shared_ptr<participant> participant);
    std::unordered_set<std::shared_ptr<participant>> participants_;
    //to get the participant in local/global messages
    std::unordered_map<std::string, std::shared_ptr<participant>> name_table_reverse;
private:
    enum { max_recent_msgs = 100 };
    std::unordered_map<std::shared_ptr<participant>, std::string> name_table_;
    std::deque<std::array<char, MAX_IP_PACK_SIZE>> recent_msgs_;
};

class personInRoom: public participant,
                    public std::enable_shared_from_this<personInRoom>
{
    public:
        personInRoom(boost::asio::io_service& io_service,
                    boost::asio::io_service::strand& strand, chatRoom& room)
                    : socket_(io_service), strand_(strand), room_(room){}
        tcp::socket& socket();
        void start();
        void onMessage(std::array<char, MAX_IP_PACK_SIZE>& msg);
    private:
        void nicknameHandler(const boost::system::error_code& error);
        void readHandler(const boost::system::error_code& error);
        void writeHandler(const boost::system::error_code& error);
        tcp::socket socket_;
        boost::asio::io_service::strand& strand_;
        chatRoom& room_;
        std::array<char, MAX_NICKNAME> nickname_;
        std::array<char, MAX_IP_PACK_SIZE> read_msg_;
        std::deque<std::array<char, MAX_IP_PACK_SIZE> > write_msgs_;
};

class server
{
public:
    server(boost::asio::io_service& io_service,
           boost::asio::io_service::strand& strand,
           const tcp::endpoint& endpoint)
           : io_service_(io_service), strand_(strand), acceptor_(io_service, endpoint)
    {
        run();
    }
    chatRoom room_;
private:
    void run();
    void onAccept(std::shared_ptr<personInRoom> new_participant, const boost::system::error_code& error);
    boost::asio::io_service& io_service_;
    boost::asio::io_service::strand& strand_;
    tcp::acceptor acceptor_;
};