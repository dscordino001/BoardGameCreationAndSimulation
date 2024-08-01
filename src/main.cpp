#include <iostream>
#include <string>
#include <vector>
#include "autoSim.hpp"
using namespace std;

// Function to parse the command line arguments
void parseCommandLineArguments(int argc, const char* argv[], int& numPlayers, string& playerColors, string& output) {
    for (int i = 1; i < argc; i++) {    // while there are less than 6 arguments sent to the command line
        string arg = argv[i];   // Check if the argument is "-o"
        if (arg == "-o") {  // Check if there is a valid output file specified
            if (i + 1 < argc) { // Assign the next argument as the output file
                output = argv[i + 1];
                i++;
            }
            else {
                cout << "Invalid input for output files" << endl;   // Print an error message for invalid input
            }
        }
        else if (arg == "-n" && arg != "-p") {  // Check if the argument is "-n"
            if (i + 1 < argc) { // Check if there is a valid number of players specified
                numPlayers = stoi(argv[i + 1]); // Assign the next argument as the number of players
                i++;
            }
            else {
                cout << "Invalid input for number of players" << endl;  // Print an error message for invalid input
            }
        }
        else if (arg != "-n" && arg == "-p") {  // Check if the argument is "-p"
            if (i + 1 < argc) { // Check if there is a valid color of players specified
                playerColors = argv[i + 1]; // Assign the next argument as the color of players
                i++;
                numPlayers = playerColors.size();
            }
            else {
                cout << "Invalid input for colors of players" << endl;  // Print an error message for invalid input
            }
        }
    }
}

vector<string> convertColorsToVectors(string colorString) {
    vector<string> output = {}; // Create an empty vector to store the converted colors

    for (int i = 0; i < colorString.size(); i++) { // Iterate through each character in the colorString
        char c = colorString[i]; // Get the current character

        switch (c) { // Check the value of the current character
        case 'r': // If the character is 'r'
            output.push_back("Red"); // Add "Red" to the output vector
            break;
        case 'g': // If the character is 'g'
            output.push_back("Green"); // Add "Green" to the output vector
            break;
        case 'y': // If the character is 'y'
            output.push_back("Yellow"); // Add "Yellow" to the output vector
            break;
        case 'b': // If the character is 'b'
            output.push_back("Blue"); // Add "Blue" to the output vector
            break;
        default: // If the character is not 'r', 'g', 'y', or 'b'
            cout << "Invalid color input" << endl; // Print an error message
            break;
        }
    }

    return output; // Return the vector containing the converted colors
}


int main(int argc, const char* argv[]) {
    int numPlayers = 0; // Initialize the variable to store the number of players
    string playerColors = ""; // Initialize the variable to store the player colors
    string outputSpec = ""; // Initialize the variable to store the output file specification
    autoSim* runSimulation; // Declare a pointer to an autoSim object

    // Parse the command line arguments
    parseCommandLineArguments(argc, argv, numPlayers, playerColors, outputSpec);

    // Insert code here...
    cout << "Welcome to the Chitty Chitty Bang Bang board game!\n"; // Print a welcome message
    cout << "Output: " << outputSpec << endl; // Print the output file specification

    vector<string> colors = convertColorsToVectors(playerColors); // Convert the player colors to a vector of strings

    // constructor for autoSim
    if (playerColors.size() != 0) { // If playerColors is not empty
        runSimulation = new autoSim(colors); // Create an autoSim object with the specified colors
    }
    else if (numPlayers > 0) { // If numPlayers is greater than 0
        runSimulation = new autoSim(numPlayers); // Create an autoSim object with the specified number of players
    }
    else { // If neither playerColors nor numPlayers is specified
        runSimulation = new autoSim(); // Create an autoSim object with default settings
    }

    runSimulation->outputFile = outputSpec; // Set the output file for the autoSim object

    playerColors = ""; // Reset the playerColors variable
    numPlayers = runSimulation->myPlayerOrder.size(); // Get the number of players from the autoSim object

    for (string player : runSimulation->myPlayerOrder) // Iterate through each player in the autoSim object
    {
        playerColors += player; // Append the player color to the playerColors string
        playerColors += ", "; // Add a comma and space after each player color
    }

    cout << "Player Colors: " << playerColors << endl; // Print the player colors
    cout << "Number of Players: " << numPlayers << endl; // Print the number of players

    // run the simulation
    runSimulation->runGame(); // Run the game simulation

    return 0; // Return 0 to indicate successful program execution
}