//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_PASSABLECAR_H
#define ROAD_FIGHTER_PASSABLECAR_H

#include "Entity.h"

namespace road_fighter {
class PassableCar : public Entity
{
public:
        // Constructor
        PassableCar(const double& width, const double& height);

        // Movement function
        void handleMovement() override;

private:
        double speed; // Constant speed of the passable car
};
} // namespace road_fighter

#endif // ROAD_FIGHTER_PASSABLECAR_H
