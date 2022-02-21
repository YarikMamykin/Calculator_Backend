#pragma once
#include <string>
#include <list>
#include <Decimal/Enums/OperationType.h>


namespace math::decimal::input {

	using Data = std::string;
	using Numbers = std::list<double>;
	using Operations = std::list<math::decimal::operation::Type>;

	struct ParsedData {
		Numbers numbers;
		Operations operations;
	};

	struct Parser {

		ParsedData parse(Data input) const;

	};

}
