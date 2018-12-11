//
// Created by sam on 05/12/18.
//

#include "Entity.h"

using namespace road_fighter;

void Entity::updatePos(const double &x, const double &y) {
    xPos = x;
    yPos = y;
}

double Entity::getXPos() const {
    return xPos;
}

double Entity::getYPos() const {
    return yPos;
}
