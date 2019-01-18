//
// Created by sam on 11.12.18.
//

#include "Game.h"

using namespace road_fighter;

Game::Game(const shared_ptr<EntityFactory>& f) : factory(f), world(f->createWorld()), gameEnd(false)
{
        world->setPlayer(factory->createPlayerCar()); // Add player to world
        world->setLength(200);                        // Set level length
        for (int i = 0; i < 3; ++i) {
                world->addRacingCar(factory->createRacingCar()); // Add RacingCars
        }
}

void Game::drawEntities() { world->draw(); }

void Game::handleInputWorld()
{
        if (!gameEnd) {
                world->handleInput();
        }
}

void Game::handleMovement() { world->handleMovement(); }

void Game::checkCollisions() { world->checkCollisions(); }

void Game::spawnPassableCar()
{
        // Spawn passable car (randomly, 1 per 100 ticks on average)
        double rnd = Random::getInstance().getRandom(0, 1); // Get random between 0 and 1
        if (rnd < 1 / 100.0) {
                world->addPassableCar(factory->createPassableCar());
        }
}

void Game::spawnBullet()
{
        // Generates a bullet which is given to world
        world->spawnBullet(factory->createBullet());
}

void Game::cleanEntities() { world->cleanEntities(); }

void Game::checkEnd()
{
        if (world->getYPos() >= world->getLength()) {
                gameEnd = world->isGameEnd();
        }
}

void Game::spawnAmmo()
{
        // Spawn passable car (randomly, 1 per 300 ticks on average)
        double rnd = Random::getInstance().getRandom(0, 1); // Get random between 0 and 1
        if (rnd < 1 / 300.0) {
                world->addEntityFront(factory->createAmmo()); // Add to front (draw under other objects)
        }
}

// Execute all procedures necessary per tick
void Game::executeTick()
{
        cleanEntities();
        spawnAmmo();
        spawnPassableCar();
        handleInput();
        handleMovement();
        checkCollisions();
        checkEnd();
}
