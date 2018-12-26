//
// Created by sam on 05/12/18.
//

#include "World.h"

using namespace road_fighter;

World::World() : Entity(8, 6) {
    xPos = -4;
    yPos = -3;
}

void World::addObserver(const shared_ptr<Observer>& observer) {
    observers.emplace_back(observer);
}

void World::removeObserver(const shared_ptr<Observer>& observer) {
    // Move element to end of vector, then erase it
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void World::notifyObservers() {
    for (const shared_ptr<Observer>& observer : observers) {
        observer->update();
    }
}

void World::addEntity(unique_ptr<road_fighter::Entity> entity) {
    entities.emplace_back(move(entity));
}

void World::removeEntity(const unique_ptr<road_fighter::Entity> &entity) {
    entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
}

void World::draw() {
    drawSelf();
    player->draw();
    for (const unique_ptr<Entity>& e : entities) {
        e->draw();
    }
}

void World::handleInput() {
    player->handleInput();
    for (const unique_ptr<Entity>& e : entities) {
        e->handleInput();
    }
}

void World::handleMovement() {
    player->handleMovement();
    for (const unique_ptr<Entity>& e : entities) {
        e->handleMovement();
    }
    double movementSpeed = player->getMovementSpeed();
    if (movementSpeed != 0) {
        scrollWorld(movementSpeed);
    }
}

void World::scrollWorld(const double& speed) {
    for (const unique_ptr<Entity>& e : entities) {
        e->scroll(speed);
    }
    scroll(speed);
}

void World::setPlayer(unique_ptr<road_fighter::PlayerCar> entity) {
    player = move(entity);
}
