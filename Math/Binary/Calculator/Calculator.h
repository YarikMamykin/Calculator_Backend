#pragma once
#include <Binary/Parser/Parser.h>

namespace math::binary::calculation {

	struct Calculator {
		math::binary::input::BinaryNumber calculate(math::binary::input::ParsedData&& data) const;
	};

}
