#include "gtest/gtest.h"

#include "Space.hpp"
#include "Player.hpp"
#include "LinearRoute.hpp"
#include "Board.hpp"
class BoardTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.
  Board* myBoard = new Board();	
    
  BoardTest() {
     // You can do set-up work common for each test here.

  }

  ~BoardTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class member functions declared here can be used by all tests in the test suite
  // for Foo.
};

// Tests that the Player::Player() method does what it should.
TEST_F(BoardTest, ConstructorWorks) {
    // Verify that the three routes all have correct lengths
    EXPECT_EQ(myBoard->route3->path.size(),16);
    EXPECT_EQ(myBoard->route2->path.size(),18);
    EXPECT_EQ(myBoard->route1->path.size(),26);
    ASSERT_EQ(myBoard->players.size(), 0);
}
