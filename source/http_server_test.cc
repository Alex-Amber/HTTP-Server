#include "gtest/gtest.h"

class FooTest : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(FooTest, DumbTest) {
  EXPECT_TRUE(true);
  EXPECT_FALSE(false);
}
