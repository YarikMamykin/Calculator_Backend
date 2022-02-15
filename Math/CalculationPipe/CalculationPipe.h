#pragma once

#include <string>
#include <memory>

namespace calculation {
	
	struct CalculationPipe {

		virtual std::string run(std::string&& data) const = 0;

		static std::unique_ptr<CalculationPipe> create(const std::string& id);
	};
}
