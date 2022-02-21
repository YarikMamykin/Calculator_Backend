#include "Calculator.h"

namespace math::binary::calculation {

	math::binary::input::BinaryNumber Calculator::calculate(math::binary::input::ParsedData&& data) const {
		auto& [ n1, operation, n2 ] = data;

		switch(operation) {
			case math::binary::OperationID::AND: return n1 & n2; 
			case math::binary::OperationID::OR:  return n1 | n2; 
			case math::binary::OperationID::XOR: return n1 ^ n2; 
		}
	}
}
