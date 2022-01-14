#include <CalculationPipe.h>
#include <InputParser.h>
#include <InputDataConverter.h>
#include <Calculator.h>
#include <iostream>

namespace calculation {

	calculation::ResultType CalculationPipe::run(std::string&& data) const {

		input::Parser p;
		input::DataConverter dc;
		Calculator c;

		return c.calculate(dc.convert_parsed_data(p.parse(data)));
	}

}
