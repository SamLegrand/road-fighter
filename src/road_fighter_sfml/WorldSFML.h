//
// Created by sam on 25.12.18.
//

#ifndef ROAD_FIGHTER_WORLDSFML_H
#define ROAD_FIGHTER_WORLDSFML_H

#include <SFML/Graphics.hpp>
#include "../road_fighter/World.h"

namespace road_fighter_SFML {
    class WorldSFML : public road_fighter::World {
    public:
        WorldSFML();
        WorldSFML(const shared_ptr<sf::RenderWindow>& w);
        void drawSelf() override;
        void handleInput() override;

    private:
        sf::Texture roadTexture;
        sf::Texture finishTexture;
        sf::Sprite roadSprite1;
        sf::Sprite roadSprite2;
        shared_ptr<sf::RenderWindow> window;
        unsigned int counter;
    };
}

#endif //ROAD_FIGHTER_WORLDSFML_H
