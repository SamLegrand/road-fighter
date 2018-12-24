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
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void handleMovement() override;



    private:
        double speedX;
        double speedY;
        double prevSpeedX;
        double prevSpeedY;
        bool notMovingX;
        bool notMovingY;
    };
}


#endif //ROAD_FIGHTER_PLAYERCAR_H
