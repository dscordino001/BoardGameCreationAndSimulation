#ifndef AUTOSIM_HPP // Include guard to prevent multiple inclusion of the header file
#define AUTOSIM_HPP

#include <iostream> // Include the input/output stream library
#include <vector> // Include the vector container library
#include <string> // Include the string library
#include <set> // Include the set container library
#include <regex> // Include the regular expression library
#include "Player.hpp" // Include the "Player" header file
#include "Board.hpp" // Include the "Board" header file

using namespace std; // Use the standard namespace

class autoSim { // Declare the "autoSim" class
private:
	Board* myBoard; // Declare a pointer to a "Board" object

public:
	autoSim(); // Declare the default constructor
	autoSim(int); // Declare a constructor that takes an integer argument
	void runGame(); // Declare the "runGame" method
	autoSim(vector<std::string>); // Declare a constructor that takes a vector of strings argument
	bool takeTurn(); // Declare the "takeTurn" method
	vector<std::string> myPlayerOrder; // Declare a vector of strings
	Board* getBoard(); // Declare the "getBoard" method
	void outputTurn(string); // Declare the "outputTurn" method
	string outputFile; // Declare a string variable

};

#endif // End of the include guard