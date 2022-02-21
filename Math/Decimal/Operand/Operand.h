#pragma once

#include <list>
#include <variant>

namespace math::decimal::operation {

	struct Operation;

	struct Operand {

		Operand(std::list<double>::iterator value);
		Operand(std::list<Operation>::iterator value);

		double as_double() const;

		bool is_number() const noexcept;

		bool is_operation() const noexcept;

		bool operator == (const Operand& o) const;

		std::variant<std::list<double>::iterator, std::list<Operation>::iterator> value;
	};

}
