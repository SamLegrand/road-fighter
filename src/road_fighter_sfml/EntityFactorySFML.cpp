//
// Created by sam on 12.12.18.
//

#include "EntityFactorySFML.h"

using namespace road_fighter_SFML;

EntityFactorySFML::EntityFactorySFML(const shared_ptr<sf::RenderWindow>& w) : window(w){};

unique_ptr<road_fighter::PlayerCar> EntityFactorySFML::createPlayerCar() const
{
        return make_unique<PlayerCarSFML>(window);
}

shared_ptr<road_fighter::Bullet> EntityFactorySFML::createBullet() const { return make_shared<BulletSFML>(window); }

shared_ptr<road_fighter::PassableCar> EntityFactorySFML::createPassableCar() const
{
        return make_shared<PassableCarSFML>(window);
}

shared_ptr<road_fighter::RacingCar> EntityFactorySFML::createRacingCar() const
{
        return make_shared<RacingCarSFML>(window);
}

unique_ptr<road_fighter::World> EntityFactorySFML::createWorld() const { return make_unique<WorldSFML>(window); }

shared_ptr<road_fighter::Ammo> EntityFactorySFML::createAmmo() const { return make_shared<AmmoSFML>(window); }
