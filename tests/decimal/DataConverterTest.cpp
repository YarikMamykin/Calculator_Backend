#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <Decimal/Parser/Parser.h>
#include <Decimal/DataConverter/DataConverter.h>
#include <array>

struct DataConverterTest : public ::testing::Test {

    math::decimal::input::Parser parser;
    math::decimal::input::DataConverter converter;

};

TEST_F(DataConverterTest, SimpleOperation)
{
    auto converted_data = converter.convert_parsed_data(parser.parse("1+2"));

    auto expected_numbers = math::decimal::input::Numbers { 1.0, 2.0 };
    EXPECT_TRUE(converted_data.numbers == expected_numbers);

    ASSERT_EQ(converted_data.operations.size(), 1ul);

    const auto& op = converted_data.operations.front();
    EXPECT_EQ(op.t, math::decimal::operation::Type::ADD);

    ASSERT_TRUE(op.left.is_number());
    ASSERT_TRUE(op.right.is_number());

    EXPECT_EQ(op.left.as_double(), expected_numbers.front());
    EXPECT_EQ(op.right.as_double(), expected_numbers.back());
}

TEST_F(DataConverterTest, OperationsWithDependencies)
{
    auto converted_data = converter.convert_parsed_data(parser.parse("1+2*3"));

    auto expected_numbers = math::decimal::input::Numbers { 1.0, 2.0, 3.0 };
    EXPECT_TRUE(converted_data.numbers == expected_numbers);

    ASSERT_EQ(converted_data.operations.size(), 2ul);

    EXPECT_EQ(converted_data.operations.front().t, math::decimal::operation::Type::MULTIPLY);
    EXPECT_EQ(converted_data.operations.back().t, math::decimal::operation::Type::ADD);

    ASSERT_TRUE(converted_data.operations.front().left.is_number());
    ASSERT_TRUE(converted_data.operations.front().right.is_number());

    ASSERT_TRUE(converted_data.operations.back().left.is_number());
    ASSERT_TRUE(converted_data.operations.back().right.is_operation());

    EXPECT_DOUBLE_EQ(converted_data.operations.front().left.as_double(), 2.0);
    EXPECT_DOUBLE_EQ(converted_data.operations.front().right.as_double(), 3.0);

    EXPECT_DOUBLE_EQ(converted_data.operations.back().left.as_double(), 1.0);
    EXPECT_DOUBLE_EQ(converted_data.operations.back().right.as_double(), 6.0);
}

TEST_F(DataConverterTest, OperationsWithDependencies2)
{
    auto converted_data = converter.convert_parsed_data(parser.parse("1+2*3-7/8"));
    const auto& [ numbers, operations ] = converted_data;

    EXPECT_THAT(numbers, testing::ElementsAre(1.0, 2.0, 3.0, 7.0, 8.0));

    constexpr std::size_t expected_operations_size { 4ul };
    ASSERT_EQ(operations.size(), expected_operations_size);

    std::array<math::decimal::operation::Type, expected_operations_size> operations_types;
    std::transform(operations.begin(), operations.end(), operations_types.begin(), [](const auto& o) { return o.t; });
    EXPECT_THAT(operations_types, testing::ElementsAre(
                math::decimal::operation::Type::MULTIPLY,
                math::decimal::operation::Type::DIVIDE,
                math::decimal::operation::Type::ADD,
                math::decimal::operation::Type::SUBSTRACT));

    std::array<double, expected_operations_size> operations_left_operands;
    std::transform(operations.begin(), operations.end(), operations_left_operands.begin(), [](const auto& o) -> double { return o.left.as_double(); });
    EXPECT_THAT(operations_left_operands, testing::ElementsAre(
                2.0, 7.0, 1.0, 7.0
    ));

    std::array<double, expected_operations_size> operations_right_operands;
    std::transform(operations.begin(), operations.end(), operations_right_operands.begin(), [](const auto& o) -> double { return o.right.as_double(); });
    EXPECT_THAT(operations_right_operands, testing::ElementsAre(
                3.0, 8.0, 6.0, 7.0/8.0
    ));
}
