#include "DecimalCalculationPipe.h"
#include <InputParser.h>
#include <InputDataConverter.h>
#include <Calculator.h>
#include <iostream>

namespace calculation {

	std::string DecimalCalculationPipe::run(std::string&& data) const {

		input::Parser p;
		input::DataConverter dc;
		Calculator c;

		return std::to_string(c.calculate(dc.convert_parsed_data(p.parse(data))));
	}
}
