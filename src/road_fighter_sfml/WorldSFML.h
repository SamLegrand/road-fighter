//
// Created by sam on 25.12.18.
//

#ifndef ROAD_FIGHTER_WORLDSFML_H
#define ROAD_FIGHTER_WORLDSFML_H

#include <SFML/Graphics.hpp>
#include "../road_fighter/World.h"
#include "ScoreSFML.h"
#include "../road_fighter/Score.h"
#include "HelperSFML.h"

namespace road_fighter_SFML {
    class WorldSFML : public road_fighter::World {
    public:
        // Constructors
        WorldSFML();
        explicit WorldSFML(const shared_ptr<sf::RenderWindow>& w);

        // Display and input functions
        void drawSelf() override;

    private:
        sf::Texture roadTexture;    // Texture for road (main part of level)
        sf::Texture finishTexture;  // Texture for finish line
        sf::Sprite roadSprite1;     // Sprite
        sf::Sprite roadSprite2;     // Second sprite to enable background looping
        sf::Sprite finishSprite;    // Sprite for finish line
        shared_ptr<sf::RenderWindow> window;    // Window to render to
    };
}

#endif //ROAD_FIGHTER_WORLDSFML_H
