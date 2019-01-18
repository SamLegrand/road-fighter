//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_PLAYERCARSFML_H
#define ROAD_FIGHTER_PLAYERCARSFML_H

#include "../road_fighter/PlayerCar.h"
#include "HelperSFML.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <memory>

using namespace std;

namespace road_fighter_SFML {
class PlayerCarSFML : public road_fighter::PlayerCar
{
public:
        // Constructors
        PlayerCarSFML();
        explicit PlayerCarSFML(const shared_ptr<sf::RenderWindow>& w);

        // Display and input functions
        void draw() override;
        void handleInput() override;

private:
        sf::Texture texture;                 // Texture
        sf::Sprite sprite;                   // Sprite to render
        shared_ptr<sf::RenderWindow> window; // Window to render to
        sf::Font font;
        sf::Text text;
};
} // namespace road_fighter_SFML

#endif // ROAD_FIGHTER_PLAYERCARSFML_H
