#include "autoSim.hpp"

#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <rapidcheck.h>
#include <random>
#include <iostream>
#include "Board.hpp"
using namespace std;

class autoSimTestFixture : public testing::Test {
protected:
    //    autoSimTestFixture() {}

    void SetUp() override {
        // Instantiate the elements of the fixture
    }

    void TearDown() override {

    }

    // Instantiates variables available to all tests using this fixture:
};

RC_GTEST_FIXTURE_PROP(autoSimTestFixture, DefaultConstructor, ()) {
    // declare an autoSim pointer that is the constructor
    autoSim* game = new autoSim();
    // get the board from the game
    Board* board = game->getBoard();

    // assert board is not null
    RC_ASSERT(board != nullptr);
};

// TEST - Constructor that takes in a vector of player colors
RC_GTEST_FIXTURE_PROP(autoSimTestFixture, ConstructorForTakingPlayerColors, ()) {
    // declare random color generator
    const auto numPlayers = *rc::gen::inRange(2, 4);
    //const auto playerColors = *rc::gen::resize(numPlayers, generateOnePlayerColor);
    vector<std::string> playerColors = *rc::gen::resize(numPlayers, rc::gen::arbitrary<vector<std::string>>());

    // declare an autoSim pointer that is the constructor
    autoSim* game = new autoSim(playerColors);
    // assert that game is not null
    EXPECT_NE(game, nullptr);
    // get the board from the game
    Board* board = game->getBoard();
    EXPECT_NE(board, nullptr);

    // test that the constructor initializes the board with the player colors
    for (int i = 0; i < playerColors.size(); i++) {
        // test that the player's color is the same as the color in the playerColors vector
        RC_ASSERT(board->players.at(i)->myColor == playerColors.at(i));
    }
};

// TEST - Constructor that takes in a number of players
RC_GTEST_FIXTURE_PROP(autoSimTestFixture, ConstructorForTakingNumberOfPlayers, ()) {
    // takes in an integer parameter between 2 and 4
    const int numPlayers = *rc::gen::inRange(2, 4);
    // declare an autoSim pointer that is the constructor
    autoSim* game = new autoSim(numPlayers);
    // get the board from the game
    Board* board = game->getBoard();

    // test that the constructor initializes the board with the correct number of players compared to numPlayers 
    RC_ASSERT(board->players.size() == numPlayers);
    // test that no colors repeated
    for (int i = 0; i < board->players.size(); i++) {
		for (int j = 0; j < board->players.size(); j++) {
			if (i != j) {
				RC_ASSERT(board->players.at(i)->myColor != board->players.at(j)->myColor); 
			}
		}
	}
};