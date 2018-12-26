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
    if (speedY >= -0.06) {
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
