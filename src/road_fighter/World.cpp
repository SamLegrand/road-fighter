//
// Created by sam on 05/12/18.
//

#include "World.h"

using namespace road_fighter;

World::World() : Entity(8, 6), gameEnd(false) {
    xPos = -4;
    yPos = -3;
    type = "World";
}

void World::addObserver(const shared_ptr<Score>& observer) {
    observers.emplace_back(observer);
}

void World::addEntity(const shared_ptr<road_fighter::Entity>& entity) {
    entities.emplace_back(entity);
}

void World::addEntityFront(const shared_ptr<road_fighter::Entity>& entity) {
    entities.insert(entities.begin(), entity);
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

void World::handleInput() {
    // Don't allow input when trying to drive below level start
    if (player->getMovementSpeed() <= 0 || yPos > -3) {
        player->handleInput();
    }
    // Don't allow movement below start of level
    else {
        player->moveUp();
    }
}

void World::handleMovement() {
    // Handle all entity movements
    player->handleMovement();
    for (const shared_ptr<Entity>& e : entities) {
        e->handleMovement();
    }
    double movementSpeed = player->getMovementSpeed();
    if (movementSpeed != 0 && yPos >= -3 && yPos - 5 <= length) {
        scrollWorld(movementSpeed);
    }
    // Stop movement when game ends
    if (yPos - player->getHeight() > length && !gameEnd) {
        gameEnd = true;
        notifyObservers(getPositionScore());
        notifyObservers("GameEnd");
    }
    // Don't allow driving below start of level
    if (yPos < -3) {
        yPos = -3;
    }
}

void World::scrollWorld(const double& speed) {
    // Scroll all objects in relation to player
    for (const shared_ptr<Entity>& e : entities) {
        e->scroll(speed);
    }
    scroll(speed);
    if (!gameEnd) {
        notifyObservers(-speed*2);  // Gain points for driving
    }
}

void World::setPlayer(unique_ptr<road_fighter::PlayerCar> entity) {
    player = move(entity);
}

void World::checkCollisions() {
    set<size_t, greater<>> toErase;
    for (size_t i = 0; i < entities.size(); ++i) {
        if (entities[i]->getType() == "Ammo" && !gameEnd) {
            if (areColliding(*player, *entities[i])) {
                if (!player->hasMaxAmmo()) {
                    player->addBullets();   // Pick up ammo
                    toErase.insert(i);
                }
            }
        }
        if (entities[i]->getType() == "Bullet" && !gameEnd) {
            for (size_t j = 0; j < entities.size(); ++j) {
                if (entities[i] != entities[j] && areColliding(*entities[i], *entities[j])) {
                    if (entities[j]->getType() == "Ammo") { // No collision with ammo
                        continue;
                    }
                    if (entities[j]->getType() == "RacingCar") {
                        shared_ptr<RacingCar> r = dynamic_pointer_cast<RacingCar>(entities[j]);
                        r->setSpeed(0); // Slow down RacingCar
                    }
                    else {
                        toErase.insert(j);  // Remove other cars
                        notifyObservers(200);   // Add 200 points
                    }
                    toErase.insert(i);  // Remove the bullet
                }
            }
        }
        if (entities[i]->getType() == "RacingCar") {
            shared_ptr<RacingCar> r = dynamic_pointer_cast<RacingCar>(entities[i]);
            if (areColliding(*r, *player) && !gameEnd) {
                if (r->getYPos() < player->getYPos()) {
                    r->setSpeed(-0.02); // Bounce
                }
                else {
                    r->setSpeed(0.01);
                }
            }
            for (const shared_ptr<Entity>& e : entities) {
                if (entities[i] != e && areColliding(*entities[i], *e)) {
                    if (e->getType() == "Truck") {
                        r->setMotorDisabled(60);
                        if (r->getYPos() < e->getYPos()) {
                            r->setSpeed(-0.06); // Bounce
                        }
                        else {
                            r->setSpeed(0.02);
                        }
                    }
                    if (e->getType() == "Taxi" || e->getType() == "RacingCar") {
                        if (r->getYPos() < e->getYPos()) {
                            r->setSpeed(-0.04); // Bounce
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
    if (!gameEnd) {
        for (const shared_ptr<Entity>& e : entities) {
            if (areColliding(*player, *e)) {
                if (e->getType() == "Truck") {
                    notifyObservers(-200);  // Remove 200 points
                    player->setMotorDisabled(60);   // Disable motor for one second
                    if (player->getYPos() < e->getYPos()) {
                        player->setSpeed(-0.06);    // Bounce
                    }
                    else {
                        player->setSpeed(0.02);
                    }
                }
                if (e->getType() == "Taxi" || e->getType() == "RacingCar") {
                    notifyObservers(-100);
                    if (player->getYPos() < e->getYPos()) {
                        player->setSpeed(-0.04);    // Bounce
                    }
                    else {
                        player->setSpeed(0.01);
                    }
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

void World::addPassableCar(const shared_ptr<road_fighter::PassableCar>& entity) {
    unsigned int counter = 0;
    for (const shared_ptr<Entity>& e : entities) {
        if (e->getType() == "Taxi" || e->getType() == "Truck") {
            if (e->getYPos() > player->getYPos() - 6 && e->getYPos() < player->getYPos() + 3) {
                ++counter;
            }
        }
    }
    // Don't allow more than 5 passable cars at the same time on the screen
    if (counter >= 5) {
        return;
    }
    // Try to move spawn location when colliding (up to 3 times)
    bool colliding = true;
    unsigned int tryCounter = 0;
    while (colliding) {
        colliding = false;
        for (const shared_ptr<Entity>& e : entities) {
            if (areColliding(*entity, *e) && tryCounter < 4) {
                if (tryCounter < 4) {
                    ++tryCounter;
                    entity->updatePos(Random::getInstance().getRandom(leftBound, rightBound - entity->getWidth()), entity->getYPos());
                    colliding = true;
                    break;
                }
                else {
                    return;
                }
            }
        }
    }
    // Don't spawn cars when the player is almost standing still
    if (player->getMovementSpeed() > 0.01) {
        return;
    }
    addEntity(entity);
}

void World::spawnBullet(const shared_ptr<Bullet>& entity) {
    // Spawn bullet in front of the player
    if (player->canShoot()) {
        entity->updatePos(player->getXPos() + player->getWidth()/2 - entity->getWidth()/2, player->getYPos() - entity->getHeight());
        // Make sure bullet is not colliding
        for (const shared_ptr<Entity>& e : entities) {
            if (areColliding(*entity, *e)) {
                return;
            }
        }
        addEntity(entity);
        player->setBlockShoot(true);    // Ensure space is released before next bullet spawn
        player->useBullet();
    }
}

void World::cleanEntities() {
    // Removes entities when they have strayed far from the player
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
    // Notify all observers of score change
    for (const shared_ptr<Score>& observer : observers) {
        observer->update(scoreChange);
    }
}

void World::addRacingCar(const shared_ptr<RacingCar>& racingcar) {
    // Make sure RacingCars are not colliding with anything on spawn!
    bool colliding = true;
    while (colliding) {
        colliding = false;
        racingcar->updatePos(Random::getInstance().getRandom(leftBound, rightBound - racingcar->getWidth()), Random::getInstance().getRandom(-3, 3));
        if (areColliding(*racingcar, *player)) {
            colliding = true;
            continue;
        }
        for (const shared_ptr<Entity>& e : entities) {
            if (e->getType() == "RacingCar") {
                if (areColliding(*racingcar, *e)) {
                    colliding = true;
                    break;
                }
            }
        }
    }
    // Add RacingCar to world
    entities.emplace_back(racingcar);
}

void World::setLength(const double &l) {
    length = l;
}

double World::getLength() const {
    return length;
}

void World::notifyObservers(const string &event) {
    // Notify all observers of event
    for (const shared_ptr<Score>& observer : observers) {
        observer->update(event);
    }
}

bool World::isGameEnd() const {
    return gameEnd;
}

double World::getPositionScore() const {
    // Count how many RacingCars are positioned above the player (to determine position)
    unsigned int position = 1;
    for (const shared_ptr<Entity>& entity : entities) {
        if (entity->getType() == "RacingCar") {
            if (entity->getYPos() < player->getYPos()) {
                ++position;
            }
        }
    }
    // Return correct score for finish position
    switch(position) {
        default: return 0;
        case 1: return 2000;
        case 2: return 1000;
        case 3: return 500;
    }
}
