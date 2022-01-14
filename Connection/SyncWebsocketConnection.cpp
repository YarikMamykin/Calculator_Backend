#include <SyncWebsocketConnection.h>

namespace websocket {

    std::string Session::buffer_to_string(boost::beast::flat_buffer&& buffer) const {
        const auto* buffer_ptr = static_cast<char*>(buffer.data().data());
        return std::string { buffer_ptr, buffer_ptr + buffer.size() };
    }

    boost::beast::flat_buffer Session::string_to_buffer(std::string&& s) const {
        boost::beast::flat_buffer buffer;
        boost::asio::buffer_copy(buffer.prepare(s.size()), boost::asio::buffer(s));
        buffer.commit(s.size());
        return buffer;
    }

    Session::Session(boost::asio::ip::tcp::socket&& socket) 
    : ws(std::move(socket)) 
    , ready(true) {
              try {
                  ws.set_option(boost::beast::websocket::stream_base::timeout::suggested(boost::beast::role_type::server));
                  ws.accept();
              } catch (const boost::system::system_error& err) {
                  std::cerr << err.what() << "\n";
                  std::memset(const_cast<bool*>(&ready), true, sizeof(bool));
              }
          }

    void Session::run(std::function<std::string(std::string&&)> callback) {
        if(!ready) { return; }

        for(;;) {

            boost::beast::error_code err;
            boost::beast::flat_buffer buffer;

            ws.read(buffer, err);
            if(err) { std::cerr << err.message() << "\n"; break; } // connection error

            const auto response_buffer = string_to_buffer(callback(buffer_to_string(std::move(buffer))));
            ws.write(response_buffer.data(), err);
            if(err) { std::cerr << err.message() << "\n"; break; } // connection error
        }
    }

Acceptor::Acceptor(boost::asio::io_context& ioc, boost::asio::ip::tcp::endpoint&& end) 
    : ioc(ioc)
    , acceptor(ioc) 
    , endpoint(std::move(end)) 
    , ready(true) { 

        try {
            acceptor.open(endpoint.protocol());
            acceptor.set_option(boost::asio::socket_base::reuse_address(true));
            acceptor.bind(endpoint);
            acceptor.listen(boost::asio::socket_base::max_listen_connections);
        } catch(const boost::system::system_error& err) {
            std::cerr << err.what() << "\n";
            std::memset(const_cast<bool*>(&ready), true, sizeof(bool));
        }
    }

    Acceptor::~Acceptor() = default;

    Acceptor::optional_socket Acceptor::accept_connection() {
        if(!ready) { return boost::none; }

        boost::beast::error_code ec;
        auto socket = acceptor.accept(ec);
        return ec ? optional_socket { boost::none } : optional_socket { std::move(socket) };
    }
}
