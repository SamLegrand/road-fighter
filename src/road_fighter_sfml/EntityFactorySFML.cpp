//
// Created by sam on 12.12.18.
//

#include "EntityFactorySFML.h"

using namespace road_fighter_SFML;

unique_ptr<road_fighter::PlayerCar> EntityFactorySFML::createPlayerCar() {
    return make_unique<PlayerCarSFML>();
}

unique_ptr<road_fighter::Bullet> EntityFactorySFML::createBullet() {
    return make_unique<BulletSFML>();
}

unique_ptr<road_fighter::PassableCar> EntityFactorySFML::createPassableCar() {
    return make_unique<PassableCarSFML>();
}

unique_ptr<road_fighter::RacingCar> EntityFactorySFML::createRacingCar() {
    return make_unique<RacingCarSFML>();
}
