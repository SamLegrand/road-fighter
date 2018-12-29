//
// Created by sam on 29.12.18.
//

#ifndef ROAD_FIGHTER_SCORESFML_H
#define ROAD_FIGHTER_SCORESFML_H

#include "SFML/Graphics.hpp"
#include "../road_fighter/Score.h"
#include <iostream>
#include <memory>
#include <cmath>

using namespace std;

namespace road_fighter_SFML {
    class ScoreSFML : public road_fighter::Score {
    public:
        ScoreSFML(const shared_ptr<sf::RenderWindow>& w);
        void display() override;

    private:
        sf::Text text;
        sf::Font font;
        shared_ptr<sf::RenderWindow> window;
    };
}

#endif //ROAD_FIGHTER_SCORESFML_H
