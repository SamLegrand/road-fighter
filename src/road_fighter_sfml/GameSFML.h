//
// Created by sam on 28.12.18.
//

#ifndef ROAD_FIGHTER_GAMESFML_H
#define ROAD_FIGHTER_GAMESFML_H

#include "../road_fighter/Game.h"
#include "EntityFactorySFML.h"
#include "SFML/Graphics.hpp"

namespace road_fighter_SFML {
    class GameSFML : public road_fighter::Game {
    public:
        explicit GameSFML(const shared_ptr<sf::RenderWindow>& w);
        void handleInput() override;
    };
}

#endif //ROAD_FIGHTER_GAMESFML_H
