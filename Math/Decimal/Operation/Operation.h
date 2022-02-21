#pragma once

#include <list>
#include <variant>
#include <ostream>
#include <Decimal/Enums/OperationType.h>
#include <Decimal/Enums/OperationPriority.h>
#include <Decimal/Operand/Operand.h>

namespace math::decimal::operation {

	struct Operation {
		Type t;
		Priority p;
		Operand left, right; 

		Operation(Type t, Operand l, Operand r);

		bool operator < (const Operation& o1) const;

		double result() const noexcept;

		bool has_same_operand_as(const Operation& o) const;

		using OperationRef = std::list<Operation>::iterator;
		void replace_operand_with(OperationRef o);

		friend std::ostream& operator << (std::ostream& os, const Operation& o);
	};
}
