#include "Parser.h"
#include <stdexcept>

namespace {

	math::decimal::operation::Type char_to_operation(const char c) {

		switch(c) {
			case '+': return math::decimal::operation::Type::ADD;
			case '-': return math::decimal::operation::Type::SUBSTRACT;
			case '*': return math::decimal::operation::Type::MULTIPLY;
			case '/': return math::decimal::operation::Type::DIVIDE;
		}

		throw std::runtime_error("operation::Type undefined!\n");
	};

	const std::string operations = { "+-*/" };
	bool belongs_to_operations (const char c) {
		return operations.find(c) != std::string::npos;
	};

	const std::string allowed_number_identifiers = { "1234567890." };
	bool belongs_to_numbers (const char c) {
		return allowed_number_identifiers.find(c) != std::string::npos;
	};

	math::decimal::input::ParsedData split_numbers_and_operations(math::decimal::input::Data& input) {
		math::decimal::input::ParsedData result;
		auto& [ result_numbers, result_operations ] = result;

		std::string buffer;
		buffer.reserve(input.size());

		bool operations_twice_in_raw { false };

		for(const auto& i: input) {

			if(belongs_to_numbers(i)) {
				buffer.push_back(i);
				operations_twice_in_raw = false;
				continue;
			}

			if(belongs_to_operations(i)) {

				if(operations_twice_in_raw)
					throw std::runtime_error("Wrong input!\n");

				result_operations.push_back(char_to_operation(i));
				operations_twice_in_raw = true;

				if(!buffer.empty()) {
					result_numbers.push_back(std::stod(buffer));
					buffer.clear();
				}
				continue;
			}

			throw std::runtime_error("Caught unexpected char!\n");
		}

		if(!buffer.empty()) {
			result_numbers.push_back(std::stod(buffer));
		}

		return result;
	}

	void handle_empty_input(const math::decimal::input::Data& input) {
		if(input.empty()) {
			throw std::runtime_error("Nothing to parse!\n");
		}
	}

	void handle_equal_numbers_and_operations_size(math::decimal::input::ParsedData& data) {

		auto& [ result_numbers, result_operations ] = data;

		if(result_numbers.size() == result_operations.size() && !result_numbers.empty()) {

			if(result_operations.front() == math::decimal::operation::Type::DIVIDE) {
				throw std::runtime_error("Input error!\n");
			}

			if(result_operations.front() == math::decimal::operation::Type::MULTIPLY) {
				result_numbers.push_front(1.0);
			}

			if(result_operations.front() == math::decimal::operation::Type::ADD ||
					result_operations.front() == math::decimal::operation::Type::SUBSTRACT) {

				result_numbers.push_front(0.0);
			}

		}

	}

	void handle_single_number(math::decimal::input::ParsedData& data) {

		auto& [ result_numbers, result_operations ] = data;

		if(result_numbers.size() == 1ul && result_operations.empty()) {
			result_operations.push_back(math::decimal::operation::Type::ADD);
			result_numbers.push_back(0.0);
		}
	}

	void handle_single_operations(math::decimal::input::ParsedData& data) {

		auto& [ result_numbers, result_operations ] = data;

		if(result_numbers.empty() && result_operations.size() == 1ul) {
			throw std::runtime_error("Input error!\n");
		}

	}
}

namespace math::decimal::input {


	ParsedData Parser::parse(Data input) const {

		handle_empty_input(input);

		auto result = split_numbers_and_operations(input);
		handle_equal_numbers_and_operations_size(result);
		handle_single_number(result);
		handle_single_operations(result);


		return result;
	}
}
