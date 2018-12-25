//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_PASSABLECAR_H
#define ROAD_FIGHTER_PASSABLECAR_H

#include "Entity.h"

namespace road_fighter {
    class PassableCar : public Entity {
    public:
        PassableCar(const double& width, const double& height, const string& type);
        void handleMovement() override {};
    private:
        string type;
    };
}


#endif //ROAD_FIGHTER_PASSABLECAR_H
