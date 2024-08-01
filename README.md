# Board Game Creation And Simulation
Established the Chitty-Chitty-Bang-Bang board game architecture with all aspects of the game enabled. 
Implemented simulations and testing of the board game.

Run these command to build the game and simulate multiple types of games with different numbers and colors of players!
# Commands
cmake -B build; 
cmake --build build; 
./build/src/Debug/play -n <int> -o <filePath>
./build/src/Debug/play -p <str> -o <filePath>
# Simulation Game command format options 
-n is for number of players. use a number 1-4
-p is for the color of player. please only use r (Red), b (Blue), g (Green), or y (Yellow)
1. 
./build/src/Debug/play -n <numberOfPlayers> -o <outputFilePath>
./build/src/Debug/play -n 2 -o output.txt; 

2. 
./build/src/Debug/play -p <playerColors> -o <outputFilePath>
ex: ./build/src/Debug/play -p rgby -o output.txt;

# Simulation of 2 random players
./build/src/Debug/play -n 2 -o twoRandomPlayers.txt; 
# Simulation of 3 random players
./build/src/Debug/play -n 3 -o threeRandomPlayers.txt; 
# Simulation of 4 random players
./build/src/Debug/play -n 4 -o fourRandomPlayers.txt; 
# Simulation of Red v. Green Players
./build/src/Debug/play -p rg -o redGreenPlayers.txt; 
# Simulation of Red v. Green v. Blue Players
./build/src/Debug/play -p rgb -o redGreenBluePlayers.txt; 
# Simulation of Red v. Green v. Blue v. Yellow Players
./build/src/Debug/play -p rgby -o redGreenBlueYellowPlayers.txt;
