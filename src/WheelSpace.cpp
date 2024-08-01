//
//  WheelSpace.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "WheelSpace.hpp"
#include "Route.hpp"
#include "Space.hpp"

WheelSpace::WheelSpace(Route *jumpTarget, Route *owningRoute): Space("Jump") {
    jumpTo = jumpTarget->startSpace;
    myRoute = owningRoute;
}

Space* WheelSpace::endMovementOn(Player* player) {
    Space* newEndSpace = jumpTo->endMovementOn(player);
    return newEndSpace;
}

