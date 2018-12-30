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
        // Constructor
        explicit Game(const shared_ptr<EntityFactory>& factory);

        // Functions to call in game loop, calls all actions in world
        void drawEntities();
        virtual void handleInput() = 0;
        void handleInputWorld();
        void handleMovement();
        void spawnPassableCar();
        void checkCollisions();
        void spawnBullet();
        void cleanEntities();
        void checkEnd();

    private:
        shared_ptr<EntityFactory> factory;  // Factory for entity creation
        unique_ptr<World> world;    // Game world
        bool gameEnd;
    };
}

#endif //ROAD_FIGHTER_GAME_H
