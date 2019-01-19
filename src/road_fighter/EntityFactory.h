//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_ENTITYFACTORY_H
#define ROAD_FIGHTER_ENTITYFACTORY_H

#include "Ammo.h"
#include "Bullet.h"
#include "PassableCar.h"
#include "PlayerCar.h"
#include "RacingCar.h"
#include "World.h"
#include <memory>

namespace road_fighter {
// Abstract base class for entity factory
class EntityFactory
{
public:
        virtual shared_ptr<Bullet> createBullet() const = 0;
        virtual shared_ptr<PassableCar> createPassableCar() const = 0;
        virtual unique_ptr<PlayerCar> createPlayerCar() const = 0;
        virtual shared_ptr<RacingCar> createRacingCar() const = 0;
        virtual unique_ptr<World> createWorld() const = 0;
        virtual shared_ptr<Ammo> createAmmo() const = 0;
};
} // namespace road_fighter

#endif // ROAD_FIGHTER_ENTITYFACTORY_H
