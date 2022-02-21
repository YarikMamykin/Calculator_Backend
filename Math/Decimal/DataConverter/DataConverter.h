#pragma once

#include <Decimal/Parser/Parser.h>
#include <Decimal/Operation/Operation.h>

namespace math::decimal::input {

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
