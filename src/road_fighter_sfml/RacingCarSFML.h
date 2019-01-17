//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_RACINGCARSFML_H
#define ROAD_FIGHTER_RACINGCARSFML_H

#include "../road_fighter/RacingCar.h"
#include <SFML/Graphics.hpp>
#include "HelperSFML.h"

namespace road_fighter_SFML {
    class RacingCarSFML : public road_fighter::RacingCar {
    public:
        // Constructors
        RacingCarSFML();
        RacingCarSFML(const shared_ptr<sf::RenderWindow>& w);

        void draw() override;
        void handleInput() override {};

    private:
        sf::Texture texture;    // Texture
        sf::Sprite sprite;      // Sprite to render
        shared_ptr<sf::RenderWindow> window;    // Window to render to
    };
}


#endif //ROAD_FIGHTER_RACINGCARSFML_H
