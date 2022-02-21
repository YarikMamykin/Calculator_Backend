#include "Calculator.h"
#include <algorithm>

namespace math::decimal::calculation {

	ResultType Calculator::calculate(math::decimal::input::ConvertedData&& data) const {
		return data.operations.back().result();
	}
}
