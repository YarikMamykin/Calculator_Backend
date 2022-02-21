#pragma once
#include <Decimal/Enums/OperationType.h>
#include <Decimal/Parser/Parser.h>
#include <Decimal/DataConverter/DataConverter.h>

namespace math::decimal::calculation {

	using ResultType = double;

	struct Calculator {

		ResultType calculate(math::decimal::input::ConvertedData&& data) const;

	};

}
