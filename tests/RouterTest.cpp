#include <gtest/gtest.h>
#include <Router.h>

struct RouterTest : public ::testing::Test { 
    routing::Router router;
};

TEST_F(RouterTest, RouteToDecimalPipe)
{
    auto&& action = router.routing_action( R"({ "pipe": "DECIMAL", "data": "2+3" })" );
    EXPECT_EQ(5, std::stoi(action()));
}

TEST_F(RouterTest, InvalidPipeName)
{
    auto&& action = router.routing_action( R"({ "pipe": "decimal", "data": "2+3" })" );
    EXPECT_EQ(std::string("Calculation pipe is undefined!"), action());
}

TEST_F(RouterTest, PipeNotSpecified)
{
    auto&& action = router.routing_action( R"({ "data": "2+3" })" );
    EXPECT_EQ(std::string("Calculation pipe is undefined!"), action());
}

TEST_F(RouterTest, InvalidPipeTypeInJSON)
{
    auto&& action = router.routing_action( R"({ "pipe": 1, "data": "2+3" })" );
    EXPECT_EQ(std::string("Calculation pipe is undefined!"), action());
}

TEST_F(RouterTest, DataNotSpecified)
{
    auto&& action = router.routing_action( R"({ "pipe": "DECIMAL" })" );
    EXPECT_THROW(action(), std::runtime_error);
}
