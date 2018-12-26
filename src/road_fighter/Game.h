//
// Created by sam on 11.12.18.
//

#ifndef ROAD_FIGHTER_GAME_H
#define ROAD_FIGHTER_GAME_H

#include "World.h"
#include "PlayerCar.h"
#include "EntityFactory.h"
#include "Random.h"

namespace road_fighter {
    class Game {
    public:
        Game();
        Game(shared_ptr<EntityFactory>& factory);
        void drawEntities();
        void handleInput();
        void handleMovement();
        void spawnPassableCar();
        void checkCollisions();

    private:
        shared_ptr<EntityFactory> factory;
        unique_ptr<World> world;
    };
}

#endif //ROAD_FIGHTER_GAME_H
