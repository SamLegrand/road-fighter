//
// Created by sam on 18.01.19.
//

#ifndef ROAD_FIGHTER_AMMOSFML_H
#define ROAD_FIGHTER_AMMOSFML_H

#include "../road_fighter/Ammo.h"
#include "HelperSFML.h"
#include <SFML/Graphics.hpp>

namespace road_fighter_SFML {
class AmmoSFML : public road_fighter::Ammo
{
public:
        // Constructors
        AmmoSFML();
        explicit AmmoSFML(const shared_ptr<sf::RenderWindow>& w);

        // Display and input functions
        void draw() override;
        void handleInput() override{};

private:
        sf::Texture texture;                 // Texture
        sf::Sprite sprite;                   // Sprite to render
        shared_ptr<sf::RenderWindow> window; // Window to render to
};
} // namespace road_fighter_SFML

#endif // ROAD_FIGHTER_AMMOSFML_H
