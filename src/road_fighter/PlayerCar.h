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
        double getMovementSpeed() const;
        void setBlockShoot(const bool& b);
        bool hasBullets() const;
        void addBullets();
        bool canShoot() const;

    private:
        double speedX;
        double speedY;
        double prevSpeedX;
        double prevSpeedY;
        bool notMovingX;
        bool notMovingY;
        bool blockShoot;
        unsigned int ammo;
        unsigned int maxAmmo;
    };
}


#endif //ROAD_FIGHTER_PLAYERCAR_H
