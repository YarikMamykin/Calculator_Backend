#pragma once

#include "Pipe/Pipe.h"

namespace math::decimal::calculation {

	struct Pipe : public math::calculation::Pipe {

		Pipe();
		~Pipe();

		std::string run(std::string&& data) const override final;

	};
}
