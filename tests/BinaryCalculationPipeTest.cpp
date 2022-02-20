#include <gtest/gtest.h>
#include <BinaryCalculationPipe.h>

struct BinaryCalculationPipeTest: public ::testing::Test {

    calculation::BinaryCalculationPipe pipe;

};

TEST_F(BinaryCalculationPipeTest, Logical_AND) {
    auto result = pipe.run("111&010");
    EXPECT_EQ(result, "010");
}

TEST_F(BinaryCalculationPipeTest, Logical_OR) {
    auto result = pipe.run("111|010");
    EXPECT_EQ(result, "111");
}

TEST_F(BinaryCalculationPipeTest, Logical_XOR) {
    auto result = pipe.run("111^010");
    EXPECT_EQ(result, "101");
}

TEST_F(BinaryCalculationPipeTest, Logical_AND_With_Greater_First_Operand) {
    auto result = pipe.run("1010|011");
    EXPECT_EQ(result, "1011");
}

TEST_F(BinaryCalculationPipeTest, Logical_AND_With_Greater_Second_Operand) {
    auto result = pipe.run("011|1010");
    EXPECT_EQ(result, "1011");
}
