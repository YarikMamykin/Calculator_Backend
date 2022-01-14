#include <gtest/gtest.h>
#include <Calculator.h>

struct CalculatorTest : public ::testing::Test {

	input::Parser ip;
	input::DataConverter dc;
	calculation::Calculator c;

};

TEST_F(CalculatorTest, ComplexFunctionWithDifferentPrioOperations)
{
    double result = c.calculate(dc.convert_parsed_data(ip.parse("10+92*30-20/3*7")));
    EXPECT_NEAR(2723.32, result, 0.02);
}

TEST_F(CalculatorTest, OneHighOneLowPrio)
{
    double result = c.calculate(dc.convert_parsed_data(ip.parse("5*9-3")));
    EXPECT_DOUBLE_EQ(42.0, result);
}

TEST_F(CalculatorTest, FloatingPointOperands)
{
    double result = c.calculate(dc.convert_parsed_data(ip.parse("7.35+2.21-3*9.9")));
    EXPECT_NEAR(-20.14, result, 0.03);
}

TEST_F(CalculatorTest, SingleNumber)
{
    double result = c.calculate(dc.convert_parsed_data(ip.parse("10")));
    EXPECT_DOUBLE_EQ(10.0, result);
}
