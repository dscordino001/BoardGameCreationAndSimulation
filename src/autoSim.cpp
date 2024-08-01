#include "autoSim.hpp"
#include "Space.hpp"
#include <cstdio>
#include <fstream>
using namespace std;

vector<std::string> generateRandomColorVector(int size) {
    vector<std::string> colors = { "Red", "Green", "Blue", "Yellow" };
    // get a random number between 2 and 4
    vector<std::string> playerColors;
    for (int i = 0; i < size; i++) {
        // gets a random postion to take from the colors vector
        int index = rand() % colors.size();
        // adds the color to the playerColors vector
        playerColors.push_back(colors[index]);
        // removes the color from the colors vector
        colors.erase(colors.begin() + index);
    }
    return playerColors;
}

Board* autoSim::getBoard() {
    return myBoard;
}

autoSim::autoSim() {
    myBoard = new Board();
    outputFile = "";
}

autoSim::autoSim(int numPlayers) {
    // Create a new instance of the Board class
    myBoard = new Board();
    // Generate a vector of random colors for the players
    vector<string> playerColors = generateRandomColorVector(numPlayers);
    // Initialize the players on the board with the generated player colors
    myBoard->initializePlayers(playerColors);
    // Set the player order to the generated player colors
    myPlayerOrder = playerColors;
    // Set the output file to an empty string
    outputFile = "";
}

autoSim::autoSim(vector<string> playerColors) {
    // Create a new instance of the Board class
    myBoard = new Board();
    // Initialize the players on the board with the given player colors
    myBoard->initializePlayers(playerColors);
    // Set the player order to the given player colors
    myPlayerOrder = playerColors;
    // Set the output file to an empty string
    outputFile = "";
}

void autoSim::outputTurn(string result) {
    if (outputFile == "") { // Check if the output file is empty
        std::cout << result; // Print the result to the console
    }
    else {
        std::ofstream outputFileStream(outputFile, std::ios_base::app); // Open the output file in append mode
        if (outputFileStream.is_open()) { // Check if the file is successfully opened
            outputFileStream << result << std::endl; // Write the result to the file
            outputFileStream.close(); // Close the file
        }
        else {
            std::cerr << "ERROR: Unable to open file " << outputFile << std::endl; // Print an error message to the console
            return; // Exit the function
        }
    }
}


bool autoSim::takeTurn() {
    static int turnCount = 1; // Declare and initialize a static variable to keep track of the turn count
    bool win = false; // Declare and initialize a boolean variable to track if a player has won
    string resultOutput = ""; // Declare an empty string variable to store the result output
    resultOutput += "-------------------------Turn #" + std::to_string(turnCount) + "------------------------- "; // Append the turn count to the result output string
    for (int i = 0; i < myPlayerOrder.size(); i++) { // Iterate over the player order vector
        int dieRoll = rand() % 6 + 1; // Generate a random number between 1 and 6 (inclusive) to simulate a die roll
        win = !myBoard->dieRoll(myPlayerOrder[i], dieRoll); // Call the dieRoll method of the Board class to determine if the player wins
        resultOutput += win; // Append the win status to the result output string
        resultOutput += "\n" + myPlayerOrder[i] + " rolled " + std::to_string(dieRoll) + " space(s)"; // Append the player's name and the die roll result to the result output string

        if (win) { // Check if the player has won
            resultOutput += "\n" + myPlayerOrder[i] + " wins!" + "\n"; // Append the win message to the result output string
            break; // Exit the loop if a player has won
        }
        resultOutput += " and moved to a " + myBoard->players[i]->currentSpace->myColor +  " Space. \n"; // Append the player's current space color to the result output string
    }
    turnCount++; // Increment the turn count
    outputTurn(resultOutput); // Call the outputTurn method to print or write the result output
    return win; // Return the win status
}

void autoSim::runGame() {
    bool playerOnBoard = myBoard->initializePlayers(myPlayerOrder); // Initialize the players on the board with the given player colors and store the result in the playerOnBoard variable
    bool gameIsWon = false; // Initialize the gameIsWon variable to false
    while (gameIsWon == false) { // Loop until the game is won
        gameIsWon = takeTurn(); // Call the takeTurn method and store the result in the gameIsWon variable
    }
}