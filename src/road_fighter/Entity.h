//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_ENTITY_H
#define ROAD_FIGHTER_ENTITY_H

#include "Transformation.h"
#include "Random.h"

namespace road_fighter {
    class Entity {
    public:
        Entity();
        virtual void draw() = 0;
        virtual void handleInput() = 0;
        virtual void handleMovement() = 0;
        Entity(const double& width, const double& height);
        void scroll(const double& speed);
        void updatePos(const double& x, const double& y);
        double getXPos() const;
        double getYPos() const;
        double getWidth() const;
        double getHeight() const;
        const string &getType() const;

    protected:
        double xPos;
        double yPos;
        double width;
        double height;
        double leftBound;
        double rightBound;
        string type;
    };
}

#endif //ROAD_FIGHTER_ENTITY_H
