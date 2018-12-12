//
// Created by sam on 05/12/18.
//

#include "PlayerCar.h"

using namespace road_fighter;

PlayerCar::PlayerCar() : Entity() {

}

void PlayerCar::moveLeft(const double &speed) {
    double x = getXPos();
    double y = getYPos();
    if (x - speed > -3) {
        updatePos(x - speed, y);
    }
}

void PlayerCar::moveRight(const double &speed) {
    double x = getXPos();
    double y = getYPos();
    if (x + speed < 3) {
        updatePos(x + speed, y);
    }
}

void PlayerCar::moveUp(const double &speed) {
    double x = getXPos();
    double y = getYPos();
    if (y + speed < 4) {
        updatePos(x, y + speed);
    }
}

void PlayerCar::moveDown(const double &speed) {
    double x = getXPos();
    double y = getYPos();
    if (y - speed > -4) {
        updatePos(x, y - speed);
    }
}
