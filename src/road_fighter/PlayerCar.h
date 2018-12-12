//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_PLAYERCAR_H
#define ROAD_FIGHTER_PLAYERCAR_H

#include "Entity.h"

namespace road_fighter {
    class PlayerCar : public Entity {
    public:
        PlayerCar();
        void moveLeft(const double& speed);
        void moveRight(const double& speed);
        void moveUp(const double& speed);
        void moveDown(const double& speed);
    };
}


#endif //ROAD_FIGHTER_PLAYERCAR_H
