#include <iostream>
#include <Router.h>
#include <Connection.h>
#include <cstdlib>

struct ConnectionClient : public connection::Connection::Client {
    std::string on_data_receive(std::string&& data) override {
        routing::Router router;
        return router.routing_action(std::move(data))();
    }
};

std::string parse_host() {

    if(const char* host = std::getenv("CALC_HOST")) {
        return { host };
    }

    return { "127.0.0.1" };
}

unsigned short parse_port() {

    if(const char* port = std::getenv("CALC_PORT")) {
        return std::stoi(port);
    }

    return 8081;
}

int main(int argc, char* argv[])
{
    const std::string host  = parse_host();
    const unsigned short port = parse_port();

    connection::Connection c ({ host, port, 1});
    auto client = std::make_shared<ConnectionClient>();
    c.set_client(client);

    std::cout << "Listening on " << host << ":" << port << "\n";
    c.poll();

    return 0;
}
