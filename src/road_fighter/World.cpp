//
// Created by sam on 05/12/18.
//

#include "World.h"

using namespace road_fighter;

World::World() : Entity(8, 6) {
    xPos = -4;
    yPos = -3;
    type = "World";
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

void World::handleInputEntities() {
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
    if (movementSpeed != 0 && yPos >= -3) {
        scrollWorld(movementSpeed);
    }
    if (yPos < -3) {
        yPos = -3;
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

void World::checkCollisions() {
    for (const unique_ptr<Entity>& e1 : entities) {
        for (const unique_ptr<Entity>& e2 : entities) {
            if (e1 != e2 && areColliding(*e1, *e2)) {
                cout << &e1 << " colliding with " << &e2 << endl;
            }
        }
    }
    for (size_t i = 0; i < entities.size();) {
        if (areColliding(*player, *entities[i])) {
            cout << "Player colliding with " << &entities[i] << endl;
            entities.erase(entities.begin() + i);
            continue;
        }
        ++i;
    }
//    for (const unique_ptr<Entity>& e : entities) {
//        if (areColliding(*player, *e)) {
//            cout << "Player colliding with " << &e << endl;
//            entities.erase(remove(entities.begin(), entities.end(), e), entities.end());
//            break;
//        }
//    }
}

bool World::areColliding(const road_fighter::Entity &e1, const road_fighter::Entity &e2) {
    // Object is above or under other object, no collision
    // Object is left or right from other object, no collision
    return (!(e1.getYPos() + e1.getHeight() < e2.getYPos() || e1.getYPos() > e2.getYPos() + e2.getHeight()
        || e1.getXPos() + e1.getWidth() < e2.getXPos() || e1.getXPos() > e2.getXPos() + e2.getWidth()));
}

bool World::addPassableCar(unique_ptr<road_fighter::Entity> entity) {
    for (const unique_ptr<Entity>& e : entities) {
        if (areColliding(*entity, *e)) {
            return false;
        }
    }
    if (player->getMovementSpeed() > 0.01) {
        return true;
    }
    addEntity(move(entity));
    return true;
}

void World::spawnBullet(unique_ptr<Entity> entity) {
    entity->updatePos(player->getXPos() + player->getWidth()/2 - entity->getWidth()/2, player->getYPos() - entity->getHeight());
    for (const unique_ptr<Entity>& e : entities) {
        if (areColliding(*entity, *e)) {
            return;
        }
    }
    addEntity(move(entity));
}

void World::cleanEntities() {
    for (const unique_ptr<Entity>& e : entities) {
        if (e->getYPos() + e->getHeight() < -3) {
            if (e->getType() == "Bullet") {
                entities.erase(remove(entities.begin(), entities.end(), e), entities.end());
                break;
            }
        }
    }
}
