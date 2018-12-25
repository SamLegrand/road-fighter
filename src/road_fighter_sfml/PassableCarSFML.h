//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_PASSABLECARSFML_H
#define ROAD_FIGHTER_PASSABLECARSFML_H

#include <SFML/Graphics.hpp>
#include "../road_fighter/PassableCar.h"

namespace road_fighter_SFML {
    class PassableCarSFML : public road_fighter::PassableCar {
    public:
        PassableCarSFML();
        PassableCarSFML(const shared_ptr<sf::RenderWindow>& w);
        void draw() override;
        void handleInput() override {};
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;
    };
}


#endif //ROAD_FIGHTER_PASSABLECARSFML_H
