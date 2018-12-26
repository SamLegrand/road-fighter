//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_BULLET_H
#define ROAD_FIGHTER_BULLET_H

#include "Entity.h"

namespace road_fighter {
    class Bullet : public Entity {
    public:
        Bullet(const double& width, const double& height);
        void handleMovement() override;
    private:
        double speed;
    };
}


#endif //ROAD_FIGHTER_BULLET_H
