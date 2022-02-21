#pragma once

#include <string>
#include <memory>

namespace math::calculation {
	
	struct Pipe {

		protected:

			Pipe();

		public:

			virtual std::string run(std::string&& data) const = 0;

			virtual ~Pipe();

			static std::unique_ptr<Pipe> create(const std::string& id);
	};
}
