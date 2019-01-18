//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_RACINGCAR_H
#define ROAD_FIGHTER_RACINGCAR_H

#include "Entity.h"

namespace road_fighter {
    class RacingCar : public Entity {
    public:
        // Constructor
        RacingCar();

        // Movement
        void moveUp();
        void moveLeft();
        void moveRight();
        void handleMovement() override;

        // Speed control (for collisions)
        void setSpeed(const double& s);
        void setMotorDisabled(const unsigned int& time);

    private:
        double speedX;  // Horizontal speed
        double speedY;  // Vertical speed
        double prevSpeedX;  // Keeps previous speed for handling slowdown
        double prevSpeedY;  // Keeps previous speed for handling slowdown
        bool notMovingX;    // Boolean for handling slowdown
        bool notMovingY;    // Boolean for handling slowdown
        unsigned int motorDisabledTime; // Time that acceleration should not be allowed
    };
}


#endif //ROAD_FIGHTER_RACINGCAR_H
