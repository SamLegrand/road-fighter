//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_ENTITY_H
#define ROAD_FIGHTER_ENTITY_H

namespace road_fighter {
    class Entity {
    public:
        Entity();
        virtual void draw() = 0;
        Entity(const double& x, const double& y);
        void updatePos(const double& x, const double& y);
        double getXPos() const;
        double getYPos() const;

    protected:
        double xPos;
        double yPos;
    };
}

#endif //ROAD_FIGHTER_ENTITY_H
