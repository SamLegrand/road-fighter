//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_ENTITY_H
#define ROAD_FIGHTER_ENTITY_H

#include "Transformation.h"

namespace road_fighter {
    class Entity {
    public:
        Entity();
        virtual void draw() = 0;
        virtual void handleInput() = 0;
        virtual void handleMovement() = 0;
        Entity(const double& width, const double& height);
        void updatePos(const double& x, const double& y);
        double getXPos() const;
        double getYPos() const;

    protected:
        double xPos;
        double yPos;
        double width;
        double height;
    };
}

#endif //ROAD_FIGHTER_ENTITY_H
