//
//  BlackSpace.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef BlackSpace_hpp
#define BlackSpace_hpp

class CircularRoute;

#include "Space.hpp"
#include "CircularRoute.hpp"

class BlackSpace : public Space {
public:
    BlackSpace(CircularRoute *route) : Space("Black") {
        myRoute = (Route *)route;
    }
    Space* endMovementOn(Player *player) override;
};

#endif /* Blac*kSpace_hpp */
