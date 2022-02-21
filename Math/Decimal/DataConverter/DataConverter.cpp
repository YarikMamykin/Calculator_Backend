#include <Decimal/DataConverter/DataConverter.h>
#include <algorithm>

namespace math::decimal::input {
	
	ConvertedData DataConverter::convert_parsed_data(ParsedData&& data) const {

		ConvertedData result = bind_operations_to_operands(std::move(data));
		organize_relations_between_operations(result.operations);

		return result;
	}

	ConvertedData DataConverter::bind_operations_to_operands(ParsedData&& data) const { 

		ConvertedData result { .numbers = std::move(data.numbers) };

		auto numbers_it = result.numbers.begin();

		for(const auto& operation_type: data.operations) {

			auto left_operand = numbers_it;
			auto right_operand = std::next(numbers_it);

			result.operations.emplace_back(operation_type, left_operand, right_operand);

			std::advance(numbers_it, 1);
		}

		result.operations.sort();

		return result;
	}

	void DataConverter::organize_relations_between_operations(ConvertedData::Operations& operations) const {
		
		for(auto operation_it = std::next(operations.begin()); operation_it != operations.end(); ++operation_it) {

			auto predicate = [operation_it](const auto& op) { return operation_it->has_same_operand_as(op); };
			for(auto op_to_bind = std::find_if(operations.begin(), operation_it, predicate); 
							 op_to_bind != operation_it; 
							 op_to_bind = std::find_if(operations.begin(), operation_it, predicate)) {

				operation_it->replace_operand_with(op_to_bind);
			}

		}
	}
}
