#include <Operand.h>
#include <Operation.h>

namespace operation {

	struct ValueAccessor {
		double operator()(std::list<double>::iterator v) { return *v; }
		double operator()(std::list<Operation>::iterator v) { return v->result(); }
	};

	Operand::Operand(std::list<double>::iterator value) : value(value) { }
	Operand::Operand(std::list<Operation>::iterator value) : value(value) { }

	double Operand::as_double() const {
		return std::visit(ValueAccessor{}, value);
	}

	bool Operand::is_number() const noexcept {
		return std::holds_alternative<std::list<double>::iterator>(value);
	}

	bool Operand::is_operation() const noexcept {
		return std::holds_alternative<std::list<Operation>::iterator>(value);
	}

	bool Operand::operator == (const Operand& o) const {
		return value == o.value;
	}

}
