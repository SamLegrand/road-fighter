//
// Created by sam on 11.12.18.
//

#include "Game.h"

using namespace road_fighter;

Game::Game(shared_ptr<EntityFactory> &f) : factory(f), world(make_unique<World>()) {
    world->addEntity(factory->createPlayerCar());
}

void Game::drawEntities() {
    world->draw();
}

void Game::handleInput() {
    world->handleInput();
}

void Game::handleMovement() {
    world->handleMovement();
}
