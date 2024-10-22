//
// Created by sam on 05/12/18.
//

#include "Entity.h"

using namespace road_fighter;

Entity::Entity() : xPos(0), yPos(0), leftBound(-1.75), rightBound(1.75), type("Entity") {}

Entity::Entity(const double& w, const double& h)
    : xPos(0), yPos(0), width(w), height(h), leftBound(-1.75), rightBound(1.75), type("Entity")
{
}

void Entity::updatePos(const double& x, const double& y)
{
        xPos = x;
        yPos = y;
}

double Entity::getXPos() const { return xPos; }

double Entity::getYPos() const { return yPos; }

void Entity::scroll(const double& speed) { yPos -= speed; }

double Entity::getWidth() const { return width; }

double Entity::getHeight() const { return height; }

const string& Entity::getType() const { return type; }
