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

namespace road_fighter_SFML {
    class EntityFactorySFML : public road_fighter::EntityFactory {
    public:
        unique_ptr<road_fighter::Bullet> createBullet() override;
        unique_ptr<road_fighter::PlayerCar> createPlayerCar() override;
        unique_ptr<road_fighter::PassableCar> createPassableCar() override;
        unique_ptr<road_fighter::RacingCar> createRacingCar() override;
    };
}


#endif //ROAD_FIGHTER_ENTITYFACTORYSFML_H
