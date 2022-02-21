#include "Operation.h"

namespace {
	math::decimal::operation::Priority define_operation_priority(math::decimal::operation::Type t) {

		if(t == math::decimal::operation::Type::DIVIDE || 
			 t == math::decimal::operation::Type::MULTIPLY) {

			return math::decimal::operation::Priority::HIGH;
		}
		
		return math::decimal::operation::Priority::LOW;
	}

	double obtain_result(math::decimal::operation::Type t, double l, double r) {

		switch(t) {
			case math::decimal::operation::Type::ADD: return l + r;
			case math::decimal::operation::Type::SUBSTRACT: return l - r;
			case math::decimal::operation::Type::MULTIPLY: return l * r;
			case math::decimal::operation::Type::DIVIDE: return l / r;
		}

		throw std::runtime_error("Unexpected operation!\n");
	}

}

namespace math::decimal::operation {

	Operation::Operation(Type t, Operand l, Operand r) 
	: t(t) 
	, p(define_operation_priority(t)) 
	, left(l) 
	, right(r) { }

	bool Operation::operator < (const Operation& o1) const {
		return p < o1.p;
	}

	double Operation::result() const noexcept {
		return obtain_result(t, left.as_double(), right.as_double());
	}

	bool Operation::has_same_operand_as(const Operation& o) const {

		if(left == o.left) return true;
		if(left == o.right) return true;
		if(right == o.left) return true;
		if(right == o.right) return true;

		return false;
	}

	void Operation::replace_operand_with(OperationRef o) {
		if(left == o->left || left == o->right) left = o;
		if(right == o->left || right == o->right) right = o;
	}

	std::ostream& operator << (std::ostream& os, const Operation& o) {
		auto& [ self, p, left, right ] = o;
		return os << 
			std::to_string(static_cast<int>(self)) 
			+ std::string(" ") 
			+ std::to_string(static_cast<int>(p)) 
			+ std::string(" ")
			+ std::to_string(left.as_double())
			+ std::string(" ")
			+ std::to_string(right.as_double())
			+ std::string("\n");
	}
}
