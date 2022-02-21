#pragma once

#include <Pipe/Pipe.h>

namespace math::binary::calculation {

	struct Pipe : public math::calculation::Pipe {

		Pipe();
		~Pipe();

		std::string run(std::string&& data) const override final;

		private:

			std::string stretch_to(std::string&& data, std::size_t width) const;
	};
}

