#include "BinaryCalculator.h"

namespace binary::input {

	BinaryNumber Calculator::calculate(ParsedData&& data) const {
		auto& [ n1, operation, n2 ] = data;

		switch(operation) {
			case OperationID::AND: return n1 & n2; 
			case OperationID::OR:  return n1 | n2; 
			case OperationID::XOR: return n1 ^ n2; 
		}
	}
}
