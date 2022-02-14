#pragma once

#include "CalculationPipe.h"

namespace calculation {

	struct DecimalCalculationPipe : public CalculationPipe {

		std::string run(std::string&& data) const override final;

	};
}
