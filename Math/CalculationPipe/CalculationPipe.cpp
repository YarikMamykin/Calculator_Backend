#include "CalculationPipe.h"
#include <DecimalCalculationPipe.h>
#include <stdexcept>
#include <unordered_map>
#include <functional>

using Pipe = std::unique_ptr<calculation::CalculationPipe>;

namespace {

	const std::unordered_map<std::string, std::function<Pipe()>> pipes {
		{ std::string { "DECIMAL" }, []() -> Pipe { return std::make_unique<calculation::DecimalCalculationPipe>(); } },
	};

}

namespace calculation {

	Pipe CalculationPipe::create(const std::string& id) {
		try { return pipes.at(id)(); } 
		catch(const std::out_of_range& err) { return nullptr; }
	}

}
