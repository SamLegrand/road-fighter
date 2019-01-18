//
// Created by sam on 05/12/18.
//

#include "Bullet.h"

using namespace road_fighter;

Bullet::Bullet(const double& width, const double& height) : Entity(width, height), speed(-0.12) { type = "Bullet"; };

void Bullet::handleMovement()
{
        double x = getXPos();
        double y = getYPos();
        updatePos(x, y + speed);
}
