#pragma once
#include <BinaryInputParser.h>

namespace binary::input {

	struct Calculator {
			BinaryNumber calculate(ParsedData&& data) const;
	};

}
