#include <gtest/gtest.h>
#include <InputParser.h>

struct InputParserTest : public ::testing::Test {

	input::Parser ip;

};

TEST_F(InputParserTest, AllAddOperations)
{
    auto parsed_result = ip.parse("1+2+3+4");

    auto expected_numbers = input::Numbers { 1.0,2.0,3.0,4.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = input::Operations { operation::Type::ADD, operation::Type::ADD, operation::Type::ADD };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(InputParserTest, AllSubstractOperations)
{
    auto parsed_result = ip.parse("1-2-3-4");

    auto expected_numbers = input::Numbers { 1.0,2.0,3.0,4.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = input::Operations { operation::Type::SUBSTRACT, operation::Type::SUBSTRACT, operation::Type::SUBSTRACT };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(InputParserTest, AllDivideOperations)
{
    auto parsed_result = ip.parse("1/2/3/4");

    auto expected_numbers = input::Numbers { 1.0,2.0,3.0,4.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = input::Operations { operation::Type::DIVIDE, operation::Type::DIVIDE, operation::Type::DIVIDE };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(InputParserTest, AllMultiplyOperations)
{
    auto parsed_result = ip.parse("1*2*3*4");

    auto expected_numbers = input::Numbers { 1.0,2.0,3.0,4.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = input::Operations { operation::Type::MULTIPLY, operation::Type::MULTIPLY, operation::Type::MULTIPLY };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(InputParserTest, MixedOperations)
{
    auto parsed_result = ip.parse("1+2/3*4-5");

    auto expected_numbers = input::Numbers { 1.0,2.0,3.0,4.0,5.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = input::Operations { operation::Type::ADD, operation::Type::DIVIDE, operation::Type::MULTIPLY, operation::Type::SUBSTRACT };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(InputParserTest, FloatNumbersParsing)
{
    auto parsed_result = ip.parse("1+2.12+3.300594");

    auto expected_numbers = input::Numbers { 1.0,2.12,3.300594 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = input::Operations { operation::Type::ADD, operation::Type::ADD };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(InputParserTest, InvalidChars) {
    EXPECT_ANY_THROW(ip.parse(""));
    EXPECT_ANY_THROW(ip.parse("1="));
    EXPECT_ANY_THROW(ip.parse("~="));
    EXPECT_ANY_THROW(ip.parse("<"));
    EXPECT_ANY_THROW(ip.parse("3--7+4"));
    EXPECT_ANY_THROW(ip.parse("3--7"));
}

TEST_F(InputParserTest, SignedOperandsAtBegin) {
    auto parsed_result = ip.parse("-3-7");

    auto expected_numbers = input::Numbers { 0.0, 3.0, 7.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = input::Operations { operation::Type::SUBSTRACT, operation::Type::SUBSTRACT };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(InputParserTest, OneOperationOneOperandSubstract) {
    auto parsed_result = ip.parse("-7");

    auto expected_numbers = input::Numbers { 0.0, 7.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = input::Operations { operation::Type::SUBSTRACT };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(InputParserTest, OneOperationOneOperandMultiply) {
    auto parsed_result = ip.parse("*7");

    auto expected_numbers = input::Numbers { 1.0, 7.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = input::Operations { operation::Type::MULTIPLY };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(InputParserTest, SingleNumberNothingMore) {
    auto parsed_result = ip.parse("77");

    auto expected_numbers = input::Numbers { 77.0, 0.0 };
    EXPECT_TRUE(parsed_result.numbers == expected_numbers);

    auto expected_operations = input::Operations { operation::Type::ADD };
    EXPECT_TRUE(parsed_result.operations == expected_operations);
}

TEST_F(InputParserTest, SingleOperator) {
    EXPECT_ANY_THROW(ip.parse("+"));
}
