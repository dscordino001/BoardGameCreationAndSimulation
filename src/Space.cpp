//
//  Space.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//
#include "Space.hpp"
#include "Player.hpp"
#include "Route.hpp"

Space::Space(){
    myColor = "Unassigned"; 
    currentPlayers = {};
}

Space::Space(std::string color)
{
    myColor = color;
}
    
Space* Space::endMovementOn(Player *player) {
    currentPlayers.insert(player);
    player->currentSpace = this;
    return this;
}

void Space::startMovement(Player *player) {
    currentPlayers.erase(player);
}

