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
        // Constructors
        Entity();
        Entity(const double& width, const double& height);

        // Functions handling display, input and movement of entity
        virtual void draw() = 0;
        virtual void handleInput() = 0;
        virtual void handleMovement() = 0;

        // Scroll function for scrolling all entities
        // World scrolls instead of player moving up
        void scroll(const double& speed);

        // Getters and setters for position, dimensions and type of object
        void updatePos(const double& x, const double& y);
        double getXPos() const;
        double getYPos() const;
        double getWidth() const;
        double getHeight() const;
        const string &getType() const;

    protected:
        double xPos;    // Current horizontal position
        double yPos;    // Current vertical position
        double width;   // Entity width
        double height;  // Entity height
        double leftBound;   // Left bound (limitation for road)
        double rightBound;  // Right bound (limitation for road)
        string type;    // Type of entity (needed for proper action on collision)
    };
}

#endif //ROAD_FIGHTER_ENTITY_H
