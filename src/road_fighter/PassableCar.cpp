//
// Created by sam on 05/12/18.
//

#include "PassableCar.h"

using namespace road_fighter;

PassableCar::PassableCar(const double &w, const double &h, const string& t) : Entity(w, h), type(t) {
    xPos = Random::getInstance().getRandom(leftBound, rightBound - width);
    yPos = -3 - height;
    speed = -0.02;
}

void PassableCar::handleMovement() {
    double x = getXPos();
    double y = getYPos();
    updatePos(x, y + speed);
}
