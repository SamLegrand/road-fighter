//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_BULLETSFML_H
#define ROAD_FIGHTER_BULLETSFML_H

#include "../road_fighter/Bullet.h"
#include "HelperSFML.h"
#include <SFML/Graphics.hpp>

namespace road_fighter_SFML {
class BulletSFML : public road_fighter::Bullet
{
public:
        // Constructors
        BulletSFML();
        explicit BulletSFML(const shared_ptr<sf::RenderWindow>& w);

        // Display and input functions
        void draw() override;
        void handleInput() override{};

private:
        sf::Texture texture;                 // Texture
        sf::Sprite sprite;                   // Sprite to render
        shared_ptr<sf::RenderWindow> window; // Window to render to
};
} // namespace road_fighter_SFML

#endif // ROAD_FIGHTER_BULLETSFML_H
