#pragma once

#include <string>

namespace calculation {

	using ResultType = double;

	struct CalculationPipe {

			ResultType run(std::string&& data) const;

	};
}
