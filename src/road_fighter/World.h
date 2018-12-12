//
// Created by sam on 05/12/18.
//

#ifndef ROAD_FIGHTER_WORLD_H
#define ROAD_FIGHTER_WORLD_H

#include "Entity.h"
#include "Score.h"
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

namespace road_fighter {
    class World : public Entity {
    public:
        // Observer functions
        void addObserver(const shared_ptr<Observer>& observer);
        void removeObserver(const shared_ptr<Observer>& observer);
        void notifyObservers();

        void addEntity(unique_ptr<Entity> entity);
        void removeEntity(const unique_ptr<Entity>& entity);

    private:
        vector<shared_ptr<Observer>> observers;
        vector<unique_ptr<Entity>> entities;
    };
}


#endif //ROAD_FIGHTER_WORLD_H
