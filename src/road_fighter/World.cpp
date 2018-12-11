//
// Created by sam on 05/12/18.
//

#include "World.h"

using namespace road_fighter;

void World::addObserver(shared_ptr<Observer> observer) {
    observers.emplace_back(observer);
}

void World::removeObserver(shared_ptr<Observer> observer) {
    // Move element to end of vector, then erase it
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void World::notifyObservers() {
    for (const shared_ptr<Observer>& observer : observers) {
        observer->update();
    }
}
