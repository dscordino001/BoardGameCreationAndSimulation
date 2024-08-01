//
//  LinearRoute.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef LinearRoute_hpp
#define LinearRoute_hpp

#include "Route.hpp"

class LinearRoute : public Route {
public:
    Space *endSpace;

    LinearRoute(int length);
    Space* movePlayer(Player *player, int noSpaces) override;     
};
#endif /* LinearRoute_hpp */
