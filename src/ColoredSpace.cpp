//
//  ColoredSpace.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "MagicButton.hpp"
#include "Player.hpp"
#include "ColoredSpace.hpp"
#include "CircularRoute.hpp"
#include "Space.hpp"

ColoredSpace::ColoredSpace(std::string color, CircularRoute *route) : Space(color) {
    myRoute = (Route*)route;
}

Space *ColoredSpace::endMovementOn(Player *player) {
    CircularRoute *myCircRoute = (CircularRoute*)myRoute;
    std::string myRoutesButtonColor = myCircRoute->myMagicButton->buttonColor;

    if (myColor == myRoutesButtonColor) { // Advance to the next route
        return myCircRoute->nextRoute->startSpace->endMovementOn(player);
    }
    else { // do nothing
        Space* super = (Space*)this; //force call to parent function
        return Space::endMovementOn(player);
    }
}
