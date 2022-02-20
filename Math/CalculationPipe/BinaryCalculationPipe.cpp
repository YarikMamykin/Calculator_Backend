#include "BinaryCalculationPipe.h"
#include <BinaryInputParser.h>
#include <BinaryCalculator.h>
#include <algorithm>


namespace calculation {

	std::string BinaryCalculationPipe::run(std::string&& data) const {
		binary::input::Parser p;
		binary::input::Calculator c;
		auto&& result = c.calculate(p.parse(std::move(data))).to_string();
		return stretch_to(std::move(result), p.max_output_length());
	}

	std::string BinaryCalculationPipe::stretch_to(std::string&& data, std::size_t width) const {
		return data.substr(data.size() - width, std::string::npos);
	}
}

