//
// Created by sam on 12.12.18.
//

#include "EntityFactory.h"

using namespace road_fighter;

unique_ptr<Bullet> EntityFactory::createBullet() {
    return make_unique<Bullet>();
}

unique_ptr<PassableCar> EntityFactory::createPassableCar(){
    return make_unique<PassableCar>();
}

unique_ptr<PlayerCar> EntityFactory::createPlayerCar(){
    return make_unique<PlayerCar>();
}

unique_ptr<RacingCar> EntityFactory::createRacingCar(){
    return make_unique<RacingCar>();
}

unique_ptr<World> EntityFactory::createWorld(){
    return make_unique<World>();
}
