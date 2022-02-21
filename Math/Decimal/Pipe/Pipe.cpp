#include "Pipe.h"
#include <Decimal/Parser/Parser.h>
#include <Decimal/DataConverter/DataConverter.h>
#include <Decimal/Calculator/Calculator.h>

namespace math::decimal::calculation {

	Pipe::Pipe() = default;
	Pipe::~Pipe() = default;

	std::string Pipe::run(std::string&& data) const {

		math::decimal::input::Parser p;
		math::decimal::input::DataConverter dc;
		Calculator c;

		return std::to_string(c.calculate(dc.convert_parsed_data(p.parse(data))));
	}
}
