//
// Created by sam on 29.12.18.
//

#ifndef ROAD_FIGHTER_SCORESFML_H
#define ROAD_FIGHTER_SCORESFML_H

#include "SFML/Graphics.hpp"
#include "../road_fighter/Score.h"
#include "../road_fighter/Transformation.h"
#include <iostream>
#include <memory>
#include <cmath>

using namespace std;

namespace road_fighter_SFML {
    class ScoreSFML : public road_fighter::Score {
    public:
        // Constructor
        ScoreSFML(const shared_ptr<sf::RenderWindow>& w);

        // Display function
        void display() override;

    private:
        sf::Text text;  // Text to display
        sf::Font font;  // Font for text
        shared_ptr<sf::RenderWindow> window;    // Window to render to
    };
}

#endif //ROAD_FIGHTER_SCORESFML_H
