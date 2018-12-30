//
// Created by sam on 11.12.18.
//

#include "Game.h"

using namespace road_fighter;

Game::Game(const shared_ptr<EntityFactory> &f) : factory(f), world(f->createWorld()) {
    world->setPlayer(factory->createPlayerCar());
    world->addRacingCar(factory->createRacingCar());
}

void Game::drawEntities() {
    world->draw();
}

void Game::handleInputWorld() {
    world->handleInput();
}

void Game::handleMovement() {
    world->handleMovement();
}

void Game::checkCollisions() {
    world->checkCollisions();
}

void Game::spawnPassableCar() {
    double rnd = Random::getInstance().getRandom(0, 1);
    unsigned int counter = 0;
    if (rnd < 1/150.0) {
        while (++counter < 3 && !world->addPassableCar(factory->createPassableCar()));
    }
}

void Game::spawnBullet() {
    world->spawnBullet(factory->createBullet());
}

void Game::cleanEntities() {
    world->cleanEntities();
}
