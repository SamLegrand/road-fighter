//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_WORLD_H
#define ROAD_FIGHTER_WORLD_H

#include "Bullet.h"
#include "Entity.h"
#include "PassableCar.h"
#include "PlayerCar.h"
#include "RacingCar.h"
#include "Random.h"
#include "Score.h"
#include <algorithm>
#include <memory>
#include <set>
#include <vector>

using namespace std;

namespace road_fighter {
class World : public Entity
{
public:
        // Constructor
        World();

        // Observer functions
        void addObserver(const shared_ptr<Score>& observer);
        void notifyObservers(const double& scoreChange);
        void notifyObservers(const string& event);

        // Functions for adding certain types of entities
        void addEntity(const shared_ptr<Entity>& entity);
        void addEntityFront(const shared_ptr<Entity>& entity);
        void setPlayer(unique_ptr<PlayerCar> entity);
        void addPassableCar(const shared_ptr<PassableCar>& entity);
        void addRacingCar(const shared_ptr<RacingCar>& racingcar);

        // Functions handling display, input and movement of entities and world
        void draw() override;
        void handleMovement() override;
        void scrollWorld(const double& speed);
        void handleInput() override;

        // Collision control
        bool areColliding(const Entity& e1, const Entity& e2);
        void checkCollisions();

        // Creating of bullets for shooting and entity cleanup
        void spawnBullet(const shared_ptr<Bullet>& entity);
        void cleanEntities();

        // Virtual function for displaying the world (implemented by SFML)
        virtual void drawSelf() = 0;
        void setLength(const double& length);
        double getLength() const;

        // Getter for when game ends (no collision control for player when game ends)
        bool isGameEnd() const;
        double getPositionScore() const;

private:
        vector<shared_ptr<Score>> observers; // List of observers
        vector<shared_ptr<Entity>> entities; // List of other entities
        unique_ptr<PlayerCar> player;        // Points to the player
        double length;                       // Level length
        bool gameEnd;                        // Set if game ends
};
} // namespace road_fighter

#endif // ROAD_FIGHTER_WORLD_H
