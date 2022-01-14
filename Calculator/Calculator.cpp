#include <Calculator.h>
#include <algorithm>

namespace calculation {

	ResultType Calculator::calculate(input::ConvertedData&& data) const {
		return data.operations.back().result();
	}
}
