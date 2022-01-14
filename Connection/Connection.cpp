#include <Connection.h>
#include <SyncWebsocketConnection.h>
#include <functional>
#include <future>

namespace connection {
    
    class Connection::Impl {
        Connection* c;
        boost::asio::io_context ioc;
        std::future<void> ioc_thread;
        std::unique_ptr<websocket::Acceptor> acceptor;
        boost::asio::ip::tcp::endpoint endpoint;


        public:
        Impl(Connection* c, const Config& config) 
        : c(c) 
        , ioc{config.threads}
        , acceptor(std::make_unique<websocket::Acceptor>(ioc, boost::asio::ip::tcp::endpoint{boost::asio::ip::make_address(config.ip_address), config.port})) { }

        std::string receive_data(std::string&& data) {
            return c->receive_data(std::move(data));
        }

        void poll() {

            ioc_thread = std::async(std::launch::async, [&ioc=this->ioc](){ ioc.run(); });

            if(auto socket = acceptor->accept_connection()) {
                auto session = std::make_unique<websocket::Session>(std::move(*socket));
                session->run([c = this->c](std::string&& data) -> std::string { return c->receive_data(std::move(data)); });
            }
            ioc.stop();
        }

        ~Impl() = default;
    };
}

namespace connection {

    Connection::Connection(Config&& c) 
    : impl(std::make_unique<Connection::Impl>(this, c)) { }

    Connection::~Connection() = default;

    std::string Connection::receive_data(std::string&& data) {

        if(client.expired()) {
            std::cerr << "DATA IGNORED: " << data << "\n";
            return std::move(data);
        }

        try {
            return client.lock()->on_data_receive(std::move(data));
        } catch(const std::runtime_error& e) {
            return e.what();
        }
    }
    
    void Connection::set_client(std::weak_ptr<Client> c) {
        client = c;
    }

    bool Connection::poll() {
        impl->poll();
        return true;
    }
}

