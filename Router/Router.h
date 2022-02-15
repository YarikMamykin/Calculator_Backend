#pragma once
#include <string>
#include <memory>
#include <CalculationPipe.h>

namespace routing {

    class RoutingAction {
        std::unique_ptr<calculation::CalculationPipe> pipe;
        std::string pipe_input;

        public:

            RoutingAction(std::unique_ptr<calculation::CalculationPipe> pipe, std::string&& pipe_input);
            RoutingAction(RoutingAction&&);
            RoutingAction& operator=(RoutingAction&&);

            RoutingAction(const RoutingAction&) = delete;
            RoutingAction& operator=(const RoutingAction&) = delete;

            ~RoutingAction();

            std::string operator()();
    };

    struct Router {

        RoutingAction routing_action(std::string&& input);

    };
}
