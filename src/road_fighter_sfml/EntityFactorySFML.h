//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_ENTITYFACTORYSFML_H
#define ROAD_FIGHTER_ENTITYFACTORYSFML_H

#include "../road_fighter/EntityFactory.h"
#include "AmmoSFML.h"
#include "BulletSFML.h"
#include "PassableCarSFML.h"
#include "PlayerCarSFML.h"
#include "RacingCarSFML.h"
#include "WorldSFML.h"

namespace road_fighter_SFML {
class EntityFactorySFML : public road_fighter::EntityFactory
{
public:
        // Constructor
        explicit EntityFactorySFML(const shared_ptr<sf::RenderWindow>& w);

        // Creator functions returning base class pointers
        shared_ptr<road_fighter::Bullet> createBullet() const override;
        unique_ptr<road_fighter::PlayerCar> createPlayerCar() const override;
        shared_ptr<road_fighter::PassableCar> createPassableCar() const override;
        shared_ptr<road_fighter::RacingCar> createRacingCar() const override;
        unique_ptr<road_fighter::World> createWorld() const override;
        shared_ptr<road_fighter::Ammo> createAmmo() const override;

private:
        shared_ptr<sf::RenderWindow> window; // Window to render to (for creating the objects)
};
} // namespace road_fighter_SFML

#endif // ROAD_FIGHTER_ENTITYFACTORYSFML_H
