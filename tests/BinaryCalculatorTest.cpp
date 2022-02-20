#include <gtest/gtest.h>
#include <BinaryCalculator.h>

struct BinaryCalculatorTest : public ::testing::Test {

    binary::input::Calculator calculator;
    binary::input::Parser ip;

};

TEST_F(BinaryCalculatorTest, Logical_AND) {
    auto result = calculator.calculate(ip.parse("111&010"));
    EXPECT_EQ(result.to_ulong(), 0b010ul);
}

TEST_F(BinaryCalculatorTest, Logical_OR) {
    auto result = calculator.calculate(ip.parse("111|010"));
    EXPECT_EQ(result.to_ulong(), 0b111ul);
}

TEST_F(BinaryCalculatorTest, Logical_XOR) {
    auto result = calculator.calculate(ip.parse("111^010"));
    EXPECT_EQ(result.to_ulong(), 0b101ul);
}

TEST_F(BinaryCalculatorTest, TwoOperationsPassed) {
    EXPECT_THROW(calculator.calculate(ip.parse("111^&010")), std::logic_error);
}

TEST_F(BinaryCalculatorTest, LongBinaryNumberError) {

    constexpr std::size_t long_binary_number_size { binary::input::BinaryNumberSize + 1ul };
    using LongBinaryNumber = std::bitset<long_binary_number_size>;

    LongBinaryNumber long_operand { std::string(long_binary_number_size,'1') };
    ASSERT_EQ(long_operand.count(), long_binary_number_size);
    
    EXPECT_THROW(calculator.calculate(ip.parse(std::string("010&") + long_operand.to_string())), std::runtime_error);
}
