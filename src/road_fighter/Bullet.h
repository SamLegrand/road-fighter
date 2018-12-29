//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_BULLET_H
#define ROAD_FIGHTER_BULLET_H

#include "Entity.h"

namespace road_fighter {
    class Bullet : public Entity {
    public:
        // Constructor
        Bullet(const double& width, const double& height);

        // Function for handling bullet movement
        void handleMovement() override;
    private:
        double speed; // Constant speed of the bullet
    };
}


#endif //ROAD_FIGHTER_BULLET_H
