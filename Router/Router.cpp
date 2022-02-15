#include "Router.h"
#include "rapidjson/document.h"

namespace {

    constexpr char key_data[] { "data" };
    constexpr char key_pipe[] { "pipe" };

    std::string extract_pipe_input(const rapidjson::Document& doc) {
        if(doc.HasMember(key_data)) {
            if(doc[key_data].IsString()) {
                return doc[key_data].GetString();
            }
        }

        return {};
    }

    std::unique_ptr<calculation::CalculationPipe> extract_pipe(const rapidjson::Document& doc) {
        if(doc.HasMember(key_pipe)) {
            if(doc[key_pipe].IsString()) {
                return calculation::CalculationPipe::create(doc[key_pipe].GetString());
            }
        }

        return nullptr;
    }
}

namespace routing {

    RoutingAction::RoutingAction(std::unique_ptr<calculation::CalculationPipe> pipe, std::string&& pipe_input)
    : pipe(std::move(pipe))
    , pipe_input(std::move(pipe_input)) { }

    RoutingAction::RoutingAction(RoutingAction&&) = default;
    RoutingAction& RoutingAction::operator=(RoutingAction&&) = default;

    RoutingAction::~RoutingAction() = default;

    std::string RoutingAction::operator()() {
        return pipe ? pipe->run(std::move(pipe_input)) : std::string { "Calculation pipe is undefined!" }; 
    }
}

namespace routing {
    
    RoutingAction Router::routing_action(std::string&& input) {
        rapidjson::Document request;
        request.Parse(input.c_str());

        auto pipe_input = extract_pipe_input(request);
        auto pipe = extract_pipe(request);

        return RoutingAction(std::move(pipe), std::move(pipe_input));
    }
}
