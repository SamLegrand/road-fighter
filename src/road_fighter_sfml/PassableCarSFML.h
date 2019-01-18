//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_PASSABLECARSFML_H
#define ROAD_FIGHTER_PASSABLECARSFML_H

#include <SFML/Graphics.hpp>
#include "../road_fighter/PassableCar.h"
#include "HelperSFML.h"

namespace road_fighter_SFML {
    class PassableCarSFML : public road_fighter::PassableCar {
    public:
        // Constructors
        PassableCarSFML();
        explicit PassableCarSFML(const shared_ptr<sf::RenderWindow>& w);

        // Display and input functions
        void draw() override;
        void handleInput() override {};
    private:
        sf::Texture texture;    // Texture
        sf::Sprite sprite;      // Sprite to render
        shared_ptr<sf::RenderWindow> window;    // Window to render to
    };
}


#endif //ROAD_FIGHTER_PASSABLECARSFML_H
