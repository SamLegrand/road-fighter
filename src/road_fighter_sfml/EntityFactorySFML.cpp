//
// Created by sam on 12.12.18.
//

#include "EntityFactorySFML.h"

using namespace road_fighter_SFML;

EntityFactorySFML::EntityFactorySFML(const shared_ptr<sf::RenderWindow> &w) : window(w) {};

unique_ptr<road_fighter::PlayerCar> EntityFactorySFML::createPlayerCar() {
    return make_unique<PlayerCarSFML>(window);
}

unique_ptr<road_fighter::Bullet> EntityFactorySFML::createBullet() {
    return make_unique<BulletSFML>(window);
}

unique_ptr<road_fighter::PassableCar> EntityFactorySFML::createPassableCar() {
    return make_unique<PassableCarSFML>(window);
}

unique_ptr<road_fighter::RacingCar> EntityFactorySFML::createRacingCar() {
    return make_unique<RacingCarSFML>();
}

unique_ptr<road_fighter::World> EntityFactorySFML::createWorld() {
    return make_unique<WorldSFML>(window);
}
