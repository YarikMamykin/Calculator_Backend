#pragma once

#include "CalculationPipe.h"

namespace calculation {

	struct BinaryCalculationPipe : public CalculationPipe {

		std::string run(std::string&& data) const override final;

		private:

			std::string stretch_to(std::string&& data, std::size_t width) const;
	};
}

