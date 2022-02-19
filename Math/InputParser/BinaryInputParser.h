#pragma once
#include <tuple>
#include <string>
#include <bitset>
#include <OperationID.h>


namespace binary::input {

	constexpr std::size_t BinaryNumberSize { 64u };
	using BinaryNumber = std::bitset<BinaryNumberSize>;
	using ParsedData = std::tuple<BinaryNumber, OperationID, BinaryNumber>;
	using Data = std::string;

	class Parser {

		std::size_t m_max_output_length;

		using OperationData = std::tuple<OperationID, std::size_t>;
		OperationData define_operation_and_symbol_position(const Data& data) const;

		public:

			ParsedData parse(Data&& input);
			std::size_t max_output_length() const;
	};

}
