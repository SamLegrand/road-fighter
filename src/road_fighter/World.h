//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_WORLD_H
#define ROAD_FIGHTER_WORLD_H

#include "Entity.h"
#include "Score.h"
#include "PlayerCar.h"
#include "Random.h"
#include "Bullet.h"
#include "RacingCar.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <set>

using namespace std;

namespace road_fighter {
    class World : public Entity {
    public:
        // Constructor
        World();

        // Observer functions
        void addObserver(const shared_ptr<Score>& observer);
        void removeObserver(const shared_ptr<Score>& observer);
        void notifyObservers(const double& scoreChange);

        // Functions for adding certain types of entities
        void addEntity(shared_ptr<Entity> entity);
        void removeEntity(const shared_ptr<Entity>& entity);
        void setPlayer(unique_ptr<PlayerCar> entity);
        bool addPassableCar(shared_ptr<Entity> entity);
        void addRacingCar(const shared_ptr<RacingCar>& racingcar);

        // Functions handling display, input and movement of entities and world
        void draw() override;
        void handleMovement() override;
        void scrollWorld(const double& speed);
        void handleInputEntities();

        // Collision control
        bool areColliding(const Entity& e1, const Entity& e2);
        void checkCollisions();

        // Creating of bullets for shooting and entity cleanup
        void spawnBullet(shared_ptr<Entity> entity);
        void cleanEntities();

        // Virtual function for displaying the world (implemented by SFML)
        virtual void drawSelf() = 0;

    private:
        vector<shared_ptr<Score>> observers;    // List of observers
        vector<shared_ptr<Entity>> entities;    // List of other entities
        vector<shared_ptr<RacingCar>> racingcars;       // List of racing cars
        unique_ptr<PlayerCar> player;           // Points to the player
    };
}


#endif //ROAD_FIGHTER_WORLD_H
