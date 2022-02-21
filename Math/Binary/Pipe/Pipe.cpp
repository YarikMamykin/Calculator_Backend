#include "Pipe.h"
#include <Binary/Parser/Parser.h>
#include <Binary/Calculator/Calculator.h>
#include <algorithm>


namespace math::binary::calculation {

	Pipe::Pipe() = default;
	Pipe::~Pipe() = default;

	std::string Pipe::run(std::string&& data) const {
		math::binary::input::Parser p;
		math::binary::calculation::Calculator c;
		auto&& result = c.calculate(p.parse(std::move(data))).to_string();
		return stretch_to(std::move(result), p.max_output_length());
	}

	std::string Pipe::stretch_to(std::string&& data, std::size_t width) const {
		return data.substr(data.size() - width, std::string::npos);
	}
}

