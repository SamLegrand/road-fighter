//
// Created by sam on 05/12/18.
//

#include "PassableCar.h"

using namespace road_fighter;

PassableCar::PassableCar(const double &w, const double &h) : Entity(w, h), speed(-0.02) {
    xPos = Random::getInstance().getRandom(leftBound, rightBound - width);  // Set random spawn position
    yPos = -3 - height;
    vector<string> types = {"Truck", "Taxi"};
    int rnd = static_cast<int>(round(Random::getInstance().getRandom(0, 1)));   // Set random car type
    type = types[rnd];
}

void PassableCar::handleMovement() {
    // Constant movement
    double x = getXPos();
    double y = getYPos();
    updatePos(x, y + speed);
}
