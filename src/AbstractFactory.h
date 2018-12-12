//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_ABSTRACTFACTORY_H
#define ROAD_FIGHTER_ABSTRACTFACTORY_H

#include <memory>
#include "road_fighter/Bullet.h"
#include "road_fighter/PassableCar.h"
#include "road_fighter/PlayerCar.h"
#include "road_fighter/RacingCar.h"
#include "road_fighter/World.h"

using namespace std;
using namespace road_fighter;

class AbstractFactory {
public:
    virtual unique_ptr<Bullet> createBullet() = 0;
    virtual unique_ptr<PassableCar> createPassableCar() = 0;
    virtual unique_ptr<PlayerCar> createPlayerCar() = 0;
    virtual unique_ptr<RacingCar> createRacingCar() = 0;
    virtual unique_ptr<World> createWorld() = 0;
};


#endif //ROAD_FIGHTER_ABSTRACTFACTORY_H
