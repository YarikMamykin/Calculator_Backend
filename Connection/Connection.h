#pragma once
#include <memory>
#include <string>

namespace connection {

    class Connection {
        class Impl;
        std::unique_ptr<Impl> impl;

        public:
        struct Client {
            virtual std::string on_data_receive(std::string&& data) = 0;
        };

        struct Config {
            std::string ip_address;
            unsigned short port;
            int threads;
        };

        Connection(Config&& c);
        ~Connection();

        void set_client(std::weak_ptr<Client> c);

        bool poll();

        private:
        std::string receive_data(std::string&& data);

        std::weak_ptr<Client> client;
    };
}
