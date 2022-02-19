#include "BinaryInputParser.h"
#include <map>
#include <stdexcept>
#include <OperationID.h>

namespace {
	using namespace binary;
	const std::map<OperationID, unsigned char> Operations {
		{ OperationID::AND, '&' },
		{ OperationID::OR,	'|' },
		{ OperationID::XOR, '^' }
	};

	binary::input::BinaryNumber extract_operand(const binary::input::Data& input_part, std::string&& error_msg) {
		try {

			if(input_part.size() > input::BinaryNumberSize)
				throw std::runtime_error(std::string("Operand value exceeds capacity! Max allowed ") + std::to_string(input::BinaryNumberSize) + std::string(" bits"));

			binary::input::BinaryNumber operand { input_part };
			return operand;

		} catch(const std::runtime_error& e) {
			
			throw std::runtime_error(std::move(error_msg));

		} catch(const std::logic_error& e) {

			throw e;

		}
	}

	constexpr char first_operand_parsing_error_msg[] { "Error parsing first operand!" };
	constexpr char second_operand_parsing_error_msg[] { "Error parsing second operand!" };
	constexpr char binary_operation_not_found_error_msg[] { "No known binary operation found!" };
}

namespace binary::input {

	Parser::OperationData Parser::define_operation_and_symbol_position(const Data& data) const {

			for(const auto& [ operation, symbol ]: Operations) {

				if(std::size_t symbol_pos = data.find_first_of(symbol); symbol_pos != std::string::npos) {
					return std::make_tuple(operation, symbol_pos);
				}

			}

			throw std::runtime_error(binary_operation_not_found_error_msg);
		}

	ParsedData Parser::parse(Data&& input) {

		auto [ operation, symbol_pos ] = define_operation_and_symbol_position(input); 

		const auto first_operand_string = input.substr(0, symbol_pos);
		BinaryNumber first_operand = extract_operand(first_operand_string, first_operand_parsing_error_msg);

		const auto second_operand_string = input.substr(symbol_pos + 1ul, std::string::npos);
		BinaryNumber second_operand = extract_operand(second_operand_string, second_operand_parsing_error_msg);

		m_max_output_length = std::max(first_operand_string.size(), second_operand_string.size());

		return std::make_tuple(first_operand, operation, second_operand);
	}

	std::size_t Parser::max_output_length() const {
		return m_max_output_length;
	}
}
