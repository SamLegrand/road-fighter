//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_ENTITYFACTORY_H
#define ROAD_FIGHTER_ENTITYFACTORY_H

#include "../AbstractFactory.h"

namespace road_fighter {
    class EntityFactory : public AbstractFactory {
    public:
        unique_ptr<Bullet> createBullet() override;
        unique_ptr<PassableCar> createPassableCar() override;
        unique_ptr<PlayerCar> createPlayerCar() override;
        unique_ptr<RacingCar> createRacingCar() override;
        unique_ptr<World> createWorld() override;
    };
}

#endif //ROAD_FIGHTER_ENTITYFACTORY_H
