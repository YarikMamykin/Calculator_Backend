#pragma once
#include <string>
#include <list>
#include <OperationType.h>


namespace input {

	using Data = std::string;
	using Numbers = std::list<double>;
	using Operations = std::list<operation::Type>;

	struct ParsedData {
		Numbers numbers;
		Operations operations;
	};

	struct Parser {

		ParsedData parse(Data input) const;

	};

}
