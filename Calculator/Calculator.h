#pragma once
#include <OperationType.h>
#include <InputParser.h>
#include <InputDataConverter.h>

namespace calculation {

	using ResultType = double;

	struct Calculator {

		ResultType calculate(input::ConvertedData&& data) const;

	};

}
