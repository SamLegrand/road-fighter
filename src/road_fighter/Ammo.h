//
// Created by sam on 18.01.19.
//

#ifndef ROAD_FIGHTER_AMMO_H
#define ROAD_FIGHTER_AMMO_H

#include "Entity.h"

namespace road_fighter {
class Ammo : public Entity
{
public:
        // Constructor
        Ammo(const double& width, const double& height);

        // No movement for Ammo
        void handleMovement() override{};
};
} // namespace road_fighter

#endif // ROAD_FIGHTER_AMMO_H
