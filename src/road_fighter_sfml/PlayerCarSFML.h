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

using namespace std;

namespace road_fighter_SFML {
    class PlayerCarSFML : public road_fighter::PlayerCar {
    public:
        PlayerCarSFML();
        void draw(sf::RenderWindow& window);

    private:
        sf::Texture texture;
        sf::Sprite sprite;
    };
}


#endif //ROAD_FIGHTER_PLAYERCARSFML_H
