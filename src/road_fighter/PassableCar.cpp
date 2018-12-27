//
// Created by sam on 05/12/18.
//

#include "PassableCar.h"

using namespace road_fighter;

PassableCar::PassableCar(const double &w, const double &h) : Entity(w, h) {
    xPos = Random::getInstance().getRandom(leftBound, rightBound - width);
    yPos = -3 - height;
    speed = -0.02;
    vector<string> types = {"Truck", "Taxi"};
    int rnd = static_cast<int>(round(Random::getInstance().getRandom(0, 1)));
    type = types[rnd];
}

void PassableCar::handleMovement() {
    double x = getXPos();
    double y = getYPos();
    updatePos(x, y + speed);
}
