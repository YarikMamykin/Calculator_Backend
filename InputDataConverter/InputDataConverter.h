#pragma once

#include <InputParser.h>
#include <Operation.h>

namespace input {

	struct ConvertedData {
		Numbers numbers;
		using Operations = std::list<operation::Operation>;
		Operations operations;
	};

	struct DataConverter {

		ConvertedData convert_parsed_data(ParsedData&& data) const;

		private:

			ConvertedData bind_operations_to_operands(ParsedData&& data) const;
			void organize_relations_between_operations(ConvertedData::Operations& operations) const;

	};
}
