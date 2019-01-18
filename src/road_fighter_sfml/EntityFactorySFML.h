//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_ENTITYFACTORYSFML_H
#define ROAD_FIGHTER_ENTITYFACTORYSFML_H


#include "../road_fighter/EntityFactory.h"
#include "PlayerCarSFML.h"
#include "BulletSFML.h"
#include "PassableCarSFML.h"
#include "RacingCarSFML.h"
#include "WorldSFML.h"
#include "AmmoSFML.h"

namespace road_fighter_SFML {
    class EntityFactorySFML : public road_fighter::EntityFactory {
    public:
        // Constructor
        explicit EntityFactorySFML(const shared_ptr<sf::RenderWindow>& w);

        // Creator functions returning base class pointers
        shared_ptr<road_fighter::Bullet> createBullet() override;
        unique_ptr<road_fighter::PlayerCar> createPlayerCar() override;
        shared_ptr<road_fighter::PassableCar> createPassableCar() override;
        shared_ptr<road_fighter::RacingCar> createRacingCar() override;
        unique_ptr<road_fighter::World> createWorld() override;
        shared_ptr<road_fighter::Ammo> createAmmo() override;

    private:
        shared_ptr<sf::RenderWindow> window;    // Window to render to (for creating the objects)
    };
}


#endif //ROAD_FIGHTER_ENTITYFACTORYSFML_H
