//
// Created by sam on 05/12/18.
//

#include "PlayerCar.h"

using namespace road_fighter;

PlayerCar::PlayerCar() : Entity(0.4, 0.8) {
    speedX = 0;
    speedY = 0;
}

void PlayerCar::handleMovement() {
    double x = getXPos();
    double y = getYPos();
    if (x + speedX > -4 && x + speedX + width < 4) {
        updatePos(x + speedX, y);
    }
    else {
        speedX = 0;
    }
    x = getXPos();
    if  (y + speedY > -3 && y + speedY + height < 3) {
        updatePos(x, y + speedY);
    }
    else {
        speedY = 0;
    }
    if (prevSpeedX == speedX) {
        notMovingX = true;
    }
    if (prevSpeedY == speedY) {
        notMovingY = true;
    }
    if (notMovingX) {
        speedX *= 0.9998;
    }
    if (notMovingY) {
        speedY *= 0.9999;
    }
    prevSpeedX = speedX;
    prevSpeedY = speedY;
}

void PlayerCar::moveLeft(const double &speed) {
    notMovingX = false;
    if (speedX >= -0.00012) {
        speedX -= 0.00000002;
    }
}

void PlayerCar::moveRight(const double &speed) {
    notMovingX = false;
    if (speedX <= 0.00012) {
        speedX += 0.00000002;
    }
}

void PlayerCar::moveUp(const double &speed) {
    notMovingY = false;
    if (speedY >= -0.00012) {
        speedY -= 0.00000002;
    }
}

void PlayerCar::moveDown(const double &speed) {
    notMovingY = false;
    if (speedY <= 0) {
        speedY += 0.00000001;
    }
}
