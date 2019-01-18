//
// Created by sam on 05/12/18.
//

#include "RacingCar.h"

using namespace road_fighter;

RacingCar::RacingCar() : Entity(0.4, 0.8), speedX(0), speedY(0), motorDisabledTime(0) { type = "RacingCar"; }

void RacingCar::handleMovement()
{
        // Handles random movement of RacingCar
        double d = Random::getInstance().getRandom(0, 1);
        if (d < 2 / 3.0) {
                if (d < 1 / 3.0) {
                        moveLeft();
                } else {
                        moveRight();
                }
        }
        if (d > 1 / 4.0) {
                moveUp();
        }
        double x = getXPos();
        double y = getYPos();
        // Keep car within legal area
        if (x + speedX > leftBound && x + speedX + width < rightBound) {
                updatePos(x + speedX, y + speedY);
        } else {
                speedX = -speedX / 2; // Bounce from sides
        }
        if (prevSpeedX == speedX) {
                notMovingX = true;
        }
        if (prevSpeedY == speedY) {
                notMovingY = true;
        }
        if (notMovingX) {
                speedX *= 0.93; // Slow down
        }
        if (notMovingY) {
                speedY *= 0.97; // Slow down
        }
        if (motorDisabledTime > 0) {
                motorDisabledTime--;
        }
        prevSpeedX = speedX;
        prevSpeedY = speedY;
}

void RacingCar::setSpeed(const double& s)
{
        speedY = s;
        speedX = -speedX * 0.5;
}

void RacingCar::setMotorDisabled(const unsigned int& time) { motorDisabledTime = time; }

void RacingCar::moveUp()
{
        notMovingY = false;
        if (speedY >= -0.08 && motorDisabledTime == 0) {
                speedY -= 0.001;
        }
}

void RacingCar::moveLeft()
{
        notMovingX = false;
        if (speedX >= -0.04) {
                speedX -= 0.002;
        }
}

void RacingCar::moveRight()
{
        notMovingX = false;
        if (speedX <= 0.04) {
                speedX += 0.002;
        }
}
