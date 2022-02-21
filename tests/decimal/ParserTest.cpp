#include <gtest/gtest.h>
#include <Decimal/Parser/Parser.h>

struct ParserTest : public ::testing::Test {

    math::decimal::input::Parser ip;

};

TEST_F(ParserTest, AllAddOperations)
{
    auto parsed_result = ip.parse("1+2+3+4");

    auto expected_numbers = math::decimal::input::Numbers { 1.0,2.0,3.0,4.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = math::decimal::input::Operations { math::decimal::operation::Type::ADD, math::decimal::operation::Type::ADD, math::decimal::operation::Type::ADD };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(ParserTest, AllSubstractOperations)
{
    auto parsed_result = ip.parse("1-2-3-4");

    auto expected_numbers = math::decimal::input::Numbers { 1.0,2.0,3.0,4.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = math::decimal::input::Operations { math::decimal::operation::Type::SUBSTRACT, math::decimal::operation::Type::SUBSTRACT, math::decimal::operation::Type::SUBSTRACT };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(ParserTest, AllDivideOperations)
{
    auto parsed_result = ip.parse("1/2/3/4");

    auto expected_numbers = math::decimal::input::Numbers { 1.0,2.0,3.0,4.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = math::decimal::input::Operations { math::decimal::operation::Type::DIVIDE, math::decimal::operation::Type::DIVIDE, math::decimal::operation::Type::DIVIDE };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(ParserTest, AllMultiplyOperations)
{
    auto parsed_result = ip.parse("1*2*3*4");

    auto expected_numbers = math::decimal::input::Numbers { 1.0,2.0,3.0,4.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = math::decimal::input::Operations { math::decimal::operation::Type::MULTIPLY, math::decimal::operation::Type::MULTIPLY, math::decimal::operation::Type::MULTIPLY };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(ParserTest, MixedOperations)
{
    auto parsed_result = ip.parse("1+2/3*4-5");

    auto expected_numbers = math::decimal::input::Numbers { 1.0,2.0,3.0,4.0,5.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = math::decimal::input::Operations { math::decimal::operation::Type::ADD, math::decimal::operation::Type::DIVIDE, math::decimal::operation::Type::MULTIPLY, math::decimal::operation::Type::SUBSTRACT };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(ParserTest, FloatNumbersParsing)
{
    auto parsed_result = ip.parse("1+2.12+3.300594");

    auto expected_numbers = math::decimal::input::Numbers { 1.0,2.12,3.300594 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = math::decimal::input::Operations { math::decimal::operation::Type::ADD, math::decimal::operation::Type::ADD };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(ParserTest, InvalidChars) {
    EXPECT_ANY_THROW(ip.parse(""));
    EXPECT_ANY_THROW(ip.parse("1="));
    EXPECT_ANY_THROW(ip.parse("~="));
    EXPECT_ANY_THROW(ip.parse("<"));
    EXPECT_ANY_THROW(ip.parse("3--7+4"));
    EXPECT_ANY_THROW(ip.parse("3--7"));
}

TEST_F(ParserTest, SignedOperandsAtBegin) {
    auto parsed_result = ip.parse("-3-7");

    auto expected_numbers = math::decimal::input::Numbers { 0.0, 3.0, 7.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = math::decimal::input::Operations { math::decimal::operation::Type::SUBSTRACT, math::decimal::operation::Type::SUBSTRACT };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(ParserTest, OneOperationOneOperandSubstract) {
    auto parsed_result = ip.parse("-7");

    auto expected_numbers = math::decimal::input::Numbers { 0.0, 7.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = math::decimal::input::Operations { math::decimal::operation::Type::SUBSTRACT };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(ParserTest, OneOperationOneOperandMultiply) {
    auto parsed_result = ip.parse("*7");

    auto expected_numbers = math::decimal::input::Numbers { 1.0, 7.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = math::decimal::input::Operations { math::decimal::operation::Type::MULTIPLY };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(ParserTest, SingleNumberNothingMore) {
    auto parsed_result = ip.parse("77");

    auto expected_numbers = math::decimal::input::Numbers { 77.0, 0.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = math::decimal::input::Operations { math::decimal::operation::Type::ADD };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(ParserTest, SingleOperator) {
    EXPECT_ANY_THROW(ip.parse("+"));
}
