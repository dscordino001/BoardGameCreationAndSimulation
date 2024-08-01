//
//  Route.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef Route_hpp
#define Route_hpp

#include <vector>

class Space;
class Player;
struct SpaceTuple;

class Route {
public:
    Space *startSpace;
    std::vector<Space*> path;

public:
    Route();
    Route(int length);
    SpaceTuple getCurrentSpace(Player *player);
    virtual Space* movePlayer(Player *player, int noSpaces);
    SpaceTuple startPlayerMove(Player *player, int noSpaces);
};

#endif /* Route_hpp */
