#pragma once
#include <boost/optional.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <list>

namespace websocket {

class Session {

    boost::beast::websocket::stream<boost::beast::tcp_stream> ws;
    const bool ready;

    std::string buffer_to_string(boost::beast::flat_buffer&& buffer) const;
    boost::beast::flat_buffer string_to_buffer(std::string&& s) const;

    public:

    Session(boost::asio::ip::tcp::socket&& socket);

    void run(std::function<std::string(std::string&&)> callback);
};


class Acceptor {

    boost::asio::io_context& ioc;
    boost::asio::ip::tcp::acceptor acceptor;
    boost::asio::ip::tcp::endpoint endpoint;
    const bool ready;

    public:

    Acceptor(boost::asio::io_context& ioc, boost::asio::ip::tcp::endpoint&& end);
    ~Acceptor();

    using optional_socket = boost::optional<boost::asio::ip::tcp::socket>;
    optional_socket accept_connection();
};

}
