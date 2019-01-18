//
// Created by sam on 18.01.19.
//

#include "Ammo.h"

using namespace road_fighter;

Ammo::Ammo(const double &width, const double &height) : Entity(width, height) {
    xPos = Random::getInstance().getRandom(leftBound, rightBound - width);
    type = "Ammo";
    yPos = -3 - height;
}
