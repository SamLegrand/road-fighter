//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_ENTITYFACTORY_H
#define ROAD_FIGHTER_ENTITYFACTORY_H

#include <memory>
#include "Bullet.h"
#include "PassableCar.h"
#include "PlayerCar.h"
#include "RacingCar.h"
#include "World.h"

namespace road_fighter {
    class EntityFactory {
    public:
        virtual unique_ptr<Bullet> createBullet() = 0;
        virtual unique_ptr<PassableCar> createPassableCar() = 0;
        virtual unique_ptr<PlayerCar> createPlayerCar() = 0;
        virtual unique_ptr<RacingCar> createRacingCar() = 0;
    };
}

#endif //ROAD_FIGHTER_ENTITYFACTORY_H
