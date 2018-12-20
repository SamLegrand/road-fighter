//
// Created by sam on 05/12/18.
//

#include "PlayerCar.h"

using namespace road_fighter;

PlayerCar::PlayerCar() : Entity(0.3, 0.6) {

}

void PlayerCar::moveLeft(const double &speed) {
    double x = getXPos();
    double y = getYPos();
    if (x - speed > -4) {
        updatePos(x - speed, y);
    }
}

void PlayerCar::moveRight(const double &speed) {
    double x = getXPos();
    double y = getYPos();
    if (x + speed + width < 4) {
        updatePos(x + speed, y);
    }
}

void PlayerCar::moveUp(const double &speed) {
    double x = getXPos();
    double y = getYPos();
    if (y + speed + height < 3) {
        updatePos(x, y + speed);
    }
}

void PlayerCar::moveDown(const double &speed) {
    double x = getXPos();
    double y = getYPos();
    if (y - speed > -3) {
        updatePos(x, y - speed);
    }
}
