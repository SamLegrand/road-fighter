//
// Created by sam on 05/12/18.
//

#include "PlayerCar.h"

using namespace road_fighter;

PlayerCar::PlayerCar() : Entity(0.4, 0.8) {
    speedX = 0;
    speedY = 0;
    blockShoot = false;
    motorDisabledTime = 0;
}

void PlayerCar::handleMovement() {
    double x = getXPos();
    double y = getYPos();
    if (x + speedX > leftBound && x + speedX + width < rightBound) {
        updatePos(x + speedX, y);
    }
    else {
        speedX = -speedX/2;
    }
    if (prevSpeedX == speedX) {
        notMovingX = true;
    }
    if (prevSpeedY == speedY) {
        notMovingY = true;
    }
    if (notMovingX) {
        speedX *= 0.93;
    }
    if (notMovingY) {
        speedY *= 0.97;
    }
    if (motorDisabledTime > 0) {
        motorDisabledTime--;
    }
    prevSpeedX = speedX;
    prevSpeedY = speedY;
}

void PlayerCar::moveLeft() {
    notMovingX = false;
    if (speedX >= -0.04) {
        speedX -= 0.002;
    }
}

void PlayerCar::moveRight() {
    notMovingX = false;
    if (speedX <= 0.04) {
        speedX += 0.002;
    }
}

void PlayerCar::moveUp() {
    notMovingY = false;
    if (speedY >= -0.08 && motorDisabledTime == 0) {
        speedY -= 0.001;
    }
}

void PlayerCar::moveDown() {
    notMovingY = false;
    if (speedY < 0) {
        speedY += 0.001;
    }
    if (speedY <= 0.04) {
        speedY += 0.0005;
    }
}

double PlayerCar::getMovementSpeed() const {
    return speedY;
}

void PlayerCar::setBlockShoot(const bool &b) {
    blockShoot = b;
}

bool PlayerCar::canShoot() const {
    return !blockShoot;
}

void PlayerCar::setSpeed(const double &s) {
    speedY = s;
    speedX = -speedX*0.5;
}

void PlayerCar::setMotorDisabled(const unsigned int &time) {
    motorDisabledTime = time;
}
