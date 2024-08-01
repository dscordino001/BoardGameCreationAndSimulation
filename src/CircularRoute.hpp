//
//  CircularRoute.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef CircularRoute_hpp
#define CircularRoute_hpp

#include "Route.hpp"
class MagicButton;
class BlackSpace;

class CircularRoute : public Route {
public:
    Route *nextRoute;
    MagicButton *myMagicButton;
    
    CircularRoute(int length, Route *next);
    Space* movePlayer(Player *player, int noSpaces) override; 
};
#endif /* CircularRoute_hpp */
