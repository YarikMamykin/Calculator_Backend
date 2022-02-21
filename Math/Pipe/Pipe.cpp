#include "Pipe.h"
#include <Decimal/Pipe/Pipe.h>
#include <Binary/Pipe/Pipe.h>
#include <stdexcept>
#include <unordered_map>
#include <functional>

using PipePtr = std::unique_ptr<math::calculation::Pipe>;

namespace {

	const std::unordered_map<std::string, std::function<PipePtr()>> pipes {
		{ std::string { "DECIMAL" }, []() -> PipePtr { return std::make_unique<math::decimal::calculation::Pipe>(); } },
		{ std::string { "BINARY" }, []() -> PipePtr { return std::make_unique<math::binary::calculation::Pipe>(); } },
	};

}

namespace math::calculation {

	Pipe::Pipe() = default;
	Pipe::~Pipe() = default;

	PipePtr Pipe::create(const std::string& id) {
		try { return pipes.at(id)(); } 
		catch(const std::out_of_range& err) { return nullptr; }
	}

}
