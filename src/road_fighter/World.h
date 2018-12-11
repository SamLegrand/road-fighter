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
        void addObserver(shared_ptr<Observer> observer);
        void removeObserver(shared_ptr<Observer> observer);
        void notifyObservers();

    private:
        vector<shared_ptr<Observer>> observers;
    };
}


#endif //ROAD_FIGHTER_WORLD_H
