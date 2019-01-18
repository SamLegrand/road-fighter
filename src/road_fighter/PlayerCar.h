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

        // Movement functions
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void handleMovement() override;

        // Information needed by world
        double getMovementSpeed() const;
        bool canShoot() const;

        // Setters needed for world
        // Handles when shooting and accelerating is allowed
        void setBlockShoot(const bool& b);
        void setSpeed(const double& s);
        void setMotorDisabled(const unsigned int& time);


        bool hasBullets() const;
        void addBullets();
        void useBullet();
        unsigned int getBulletCapacity() const;
        unsigned int getBulletCount() const;
        bool hasMaxAmmo() const;

    private:
        double speedX;  // Horizontal speed
        double speedY;  // Vertical speed
        double prevSpeedX;  // Keeps previous speed for handling slowdown
        double prevSpeedY;  // Keeps previous speed for handling slowdown
        bool notMovingX;    // Boolean for handling slowdown
        bool notMovingY;    // Boolean for handling slowdown
        bool blockShoot;    // Blocks shooting (only able to shoot once per press)
        unsigned int motorDisabledTime; // Time that acceleration should not be allowed
        unsigned int bulletCount;   // Amount of bullets in inventory
        unsigned int bulletCapacity;    // Maximum bullet capacity
    };
}


#endif //ROAD_FIGHTER_PLAYERCAR_H
