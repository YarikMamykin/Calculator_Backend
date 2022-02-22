#include <gtest/gtest.h>
#include <Decimal/Pipe/Pipe.h>

struct PipeTest : public ::testing::Test {

    math::decimal::calculation::Pipe pipe;

};

TEST_F(PipeTest, ComplexFunctionWithDifferentPrioOperations)
{
    auto result = pipe.run("10+92*30-20/3*7");
    EXPECT_EQ("2723.333333", result);
}

TEST_F(PipeTest, OneHighOneLowPrio)
{
    auto result = pipe.run("5*9-3");
    EXPECT_EQ("42.000000", result);
}

TEST_F(PipeTest, FloatingPointOperands)
{
    auto result = pipe.run("7.35+2.21-3*9.9");
    EXPECT_EQ("-20.140000", result);
}

TEST_F(PipeTest, SingleNumber)
{
    auto result = pipe.run("10");
    EXPECT_EQ("10.000000", result);
}
