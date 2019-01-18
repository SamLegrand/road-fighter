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
#include "HelperSFML.h"

using namespace std;

namespace road_fighter_SFML {
    class PlayerCarSFML : public road_fighter::PlayerCar {
    public:
        // Constructors
        PlayerCarSFML();
        explicit PlayerCarSFML(const shared_ptr<sf::RenderWindow>& w);

        // Display and input functions
        void draw() override;
        void handleInput() override;

    private:
        sf::Texture texture;    // Texture
        sf::Sprite sprite;      // Sprite to render
        shared_ptr<sf::RenderWindow> window;    // Window to render to
        sf::Font font;
        sf::Text text;
    };
}


#endif //ROAD_FIGHTER_PLAYERCARSFML_H
