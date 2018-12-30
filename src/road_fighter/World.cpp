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

void World::addObserver(const shared_ptr<Score>& observer) {
    observers.emplace_back(observer);
}

void World::removeObserver(const shared_ptr<Score>& observer) {
    // Move element to end of vector, then erase it
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void World::addEntity(shared_ptr<road_fighter::Entity> entity) {
    entities.emplace_back(move(entity));
}

void World::removeEntity(const shared_ptr<road_fighter::Entity> &entity) {
    entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
}

void World::draw() {
    drawSelf();
    for (const shared_ptr<Entity>& e : entities) {
        e->draw();
    }
    player->draw();
    for (const shared_ptr<Score>& observer : observers) {
        observer->display();
    }
}

void World::handleInputEntities() {
    player->handleInput();
    for (const shared_ptr<Entity>& e : entities) {
        e->handleInput();
    }
}

void World::handleMovement() {
    player->handleMovement();
    for (const shared_ptr<Entity>& e : entities) {
        e->handleMovement();
    }
    double movementSpeed = player->getMovementSpeed();
    if (movementSpeed != 0 && yPos >= -3 && yPos - 4 <= length) {
        scrollWorld(movementSpeed);
    }
    if (yPos < -3) {
        yPos = -3;
    }
}

void World::scrollWorld(const double& speed) {
    for (const shared_ptr<Entity>& e : entities) {
        e->scroll(speed);
    }
    scroll(speed);
    notifyObservers(-speed*2);
}

void World::setPlayer(unique_ptr<road_fighter::PlayerCar> entity) {
    player = move(entity);
}

void World::checkCollisions() {
//    vector<shared_ptr<road_fighter::Entity>> myEntities = entities;
    set<size_t, greater<>> toErase;
    for (size_t i = 0; i < entities.size(); ++i) {
        if (entities[i]->getType() == "Bullet") {
            for (size_t j = 0; j < entities.size(); ++j) {
                if (entities[i] != entities[j] && areColliding(*entities[i], *entities[j])) {
                    cout << entities[i]->getType() << " colliding with " << entities[j]->getType() << endl;
                    if (entities[j]->getType() == "RacingCar") {
                        shared_ptr<RacingCar> r = dynamic_pointer_cast<RacingCar>(entities[j]);
                        r->setSpeed(0);
                    }
                    else {
                        toErase.insert(j);
                        notifyObservers(200);
                    }
                    toErase.insert(i);
                }
            }
        }
        if (entities[i]->getType() == "RacingCar") {
            shared_ptr<RacingCar> r = dynamic_pointer_cast<RacingCar>(entities[i]);
            if (areColliding(*r, *player)) {
                if (r->getYPos() < player->getYPos()) {
                    r->setSpeed(-0.02);
                }
                else {
                    r->setSpeed(0.01);
                }
            }
            for (const shared_ptr<Entity>& e : entities) {
                if (entities[i] != e && areColliding(*entities[i], *e)) {
                    cout << entities[i]->getType() << " colliding with " << e->getType() << endl;
                    if (e->getType() == "Truck") {
                        r->setMotorDisabled(60);
                        if (r->getYPos() < e->getYPos()) {
                            r->setSpeed(-0.04);
                        }
                        else {
                            r->setSpeed(0.02);
                        }
                    }
                    if (e->getType() == "Taxi") {
                        if (r->getYPos() < e->getYPos()) {
                            r->setSpeed(-0.02);
                        }
                        else {
                            r->setSpeed(0.01);
                        }
                    }
                }
            }
        }
    }
    for (const size_t& index : toErase) {
        entities.erase(entities.begin() + index);
    }
    for (const shared_ptr<Entity>& e : entities) {
        if (areColliding(*player, *e)) {
            cout << "Player colliding with " << e->getType() << endl;
            if (e->getType() == "Truck") {
                notifyObservers(-100);
                player->setMotorDisabled(60);
                if (player->getYPos() < e->getYPos()) {
                    player->setSpeed(-0.04);
                }
                else {
                    player->setSpeed(0.02);
                }
            }
            if (e->getType() == "Taxi" || e->getType() == "RacingCar") {
                notifyObservers(-100);
                if (player->getYPos() < e->getYPos()) {
                    player->setSpeed(-0.02);
                }
                else {
                    player->setSpeed(0.01);
                }
            }
        }
    }
}

bool World::areColliding(const road_fighter::Entity &e1, const road_fighter::Entity &e2) {
    // Object is above or under other object, no collision
    // Object is left or right from other object, no collision
    return (!(e1.getYPos() + e1.getHeight() < e2.getYPos() || e1.getYPos() > e2.getYPos() + e2.getHeight()
        || e1.getXPos() + e1.getWidth() < e2.getXPos() || e1.getXPos() > e2.getXPos() + e2.getWidth()));
}

bool World::addPassableCar(shared_ptr<road_fighter::Entity> entity) {
    for (const shared_ptr<Entity>& e : entities) {
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

void World::spawnBullet(shared_ptr<Entity> entity) {
    if (player->canShoot()) {
        entity->updatePos(player->getXPos() + player->getWidth()/2 - entity->getWidth()/2, player->getYPos() - entity->getHeight());
        for (const shared_ptr<Entity>& e : entities) {
            if (areColliding(*entity, *e)) {
                return;
            }
        }
        addEntity(move(entity));
        player->setBlockShoot(true);
    }
}

void World::cleanEntities() {
    for (size_t i = 0; i < entities.size();) {
        if (entities[i]->getType() == "Bullet") {
            if (entities[i]->getYPos() + entities[i]->getHeight() < -3) {
                entities.erase(entities.begin() + i);
                continue;
            }
        }
        if (entities[i]->getType() != "RacingCar") {
            if (entities[i]->getYPos() + entities[i]->getHeight() < -30 || entities[i]->getYPos() > 30) {
                entities.erase(entities.begin() + i);
                continue;
            }
        }
        ++i;
    }
}

void World::notifyObservers(const double& scoreChange) {
    for (const shared_ptr<Score>& observer : observers) {
        observer->update(scoreChange);
    }
}

void World::addRacingCar(const shared_ptr<RacingCar>& racingcar) {
    bool colliding = true;
    while (areColliding(*racingcar, *player) || colliding) {
        colliding = false;
        racingcar->updatePos(Random::getInstance().getRandom(leftBound, rightBound - racingcar->getWidth()), Random::getInstance().getRandom(-3, 3));
        for (const shared_ptr<Entity>& e : entities) {
            if (e->getType() == "RacingCar") {
                if (areColliding(*racingcar, *e)) {
                    colliding = true;
                    break;
                }
            }
        }
    }
    entities.emplace_back(racingcar);
}

void World::setLength(const double &l) {
    length = l;
}

double World::getLength() const {
    return length;
}
