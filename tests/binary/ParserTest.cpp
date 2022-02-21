#include <exception>
#include <gtest/gtest.h>
#include <Binary/Parser/Parser.h>

struct ParserTest : public ::testing::Test {

    math::binary::input::Parser ip;

};

TEST_F(ParserTest, Logical_AND_Operation)
{
    auto [ first_operand, operation, second_operand ] = ip.parse("111&010");

    EXPECT_EQ(first_operand.to_ulong(), 0b111ul);
    EXPECT_EQ(operation, math::binary::OperationID::AND);
    EXPECT_EQ(second_operand.to_ulong(), 0b010ul);
}

TEST_F(ParserTest, Logical_OR_Operation)
{
    auto [ first_operand, operation, second_operand ] = ip.parse("111|010");

    EXPECT_EQ(first_operand.to_ulong(), 0b111ul);
    EXPECT_EQ(operation, math::binary::OperationID::OR);
    EXPECT_EQ(second_operand.to_ulong(), 0b010ul);
}

TEST_F(ParserTest, Logical_XOR_Operation)
{
    auto [ first_operand, operation, second_operand ] = ip.parse("111^010");

    EXPECT_EQ(first_operand.to_ulong(), 0b111ul);
    EXPECT_EQ(operation, math::binary::OperationID::XOR);
    EXPECT_EQ(second_operand.to_ulong(), 0b010ul);
}

TEST_F(ParserTest, FirstOperandGreaterThanSecond)
{
    auto [ first_operand, operation, second_operand ] = ip.parse("1111^10");

    EXPECT_EQ(first_operand.to_ulong(), 0b1111ul);
    EXPECT_EQ(operation, math::binary::OperationID::XOR);
    EXPECT_EQ(second_operand.to_ulong(), 0b10ul);
}

TEST_F(ParserTest, SecondOperandGreaterThanFirst)
{
    auto [ first_operand, operation, second_operand ] = ip.parse("11^10000");

    EXPECT_EQ(first_operand.to_ulong(), 0b11ul);
    EXPECT_EQ(operation, math::binary::OperationID::XOR);
    EXPECT_EQ(second_operand.to_ulong(), 0b10000ul);
}

TEST_F(ParserTest, ExtraBinaryOperationProvided)
{
    EXPECT_THROW(ip.parse("11^&10000"), std::logic_error);
}

TEST_F(ParserTest, UnknownOperation)
{
    EXPECT_THROW(ip.parse("11%10"), std::runtime_error);
}

TEST_F(ParserTest, VeryLongOperandProvided) {

    constexpr std::size_t long_binary_number_size { math::binary::input::BinaryNumberSize + 1ul };
    using LongBinaryNumber = std::bitset<long_binary_number_size>;

    LongBinaryNumber long_operand { std::string(long_binary_number_size,'1') };
    ASSERT_EQ(long_operand.count(), long_binary_number_size);

    EXPECT_THROW(ip.parse(std::string("010&") + long_operand.to_string()), std::runtime_error);
}
