#pragma once

#include <string>

namespace calculation {
	
	struct CalculationPipe {

		virtual std::string run(std::string&& data) const = 0;

	};
}
