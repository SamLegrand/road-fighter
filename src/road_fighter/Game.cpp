//
// Created by sam on 11.12.18.
//

#include "Game.h"

using namespace road_fighter;

Game::Game() : factory(make_shared<EntityFactory>()), world(factory->createWorld()) {
    world->addEntity(factory->createPlayerCar());
}

Game::Game(shared_ptr<EntityFactory> &f) : factory(f), world(factory->createWorld()) {
    world->addEntity(factory->createPlayerCar());
}
