//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_PLAYERCARSFML_H
#define ROAD_FIGHTER_PLAYERCARSFML_H

#include "../road_fighter/PlayerCar.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

using namespace std;

namespace road_fighter_SFML {
    class PlayerCarSFML : public road_fighter::PlayerCar {
    public:
        PlayerCarSFML();
        PlayerCarSFML(const shared_ptr<sf::RenderWindow>& w);
        void draw() override;
        void handleInput() override;

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;
    };
}


#endif //ROAD_FIGHTER_PLAYERCARSFML_H
