//
//  WheelSpace.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef WheelSpace_hpp
#define WheelSpace_hpp

class Route;
#include "Space.hpp"
class WheelSpace : public Space {
private:
    Space *jumpTo;

public:
    WheelSpace(Route *jumpTarget, Route *owningRoute);
    Space *endMovementOn(Player *player) override;
};
#endif /* WheelSpace_hpp */
