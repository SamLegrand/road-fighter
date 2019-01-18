//
// Created by sam on 29.12.18.
//

#ifndef ROAD_FIGHTER_SCORESFML_H
#define ROAD_FIGHTER_SCORESFML_H

#include "../road_fighter/Score.h"
#include "../road_fighter/Transformation.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#include <iostream>
#include <memory>

using namespace std;

namespace road_fighter_SFML {
class ScoreSFML : public road_fighter::Score
{
public:
        // Constructor
        explicit ScoreSFML(const shared_ptr<sf::RenderWindow>& w);

        // Display function
        void display() override;

private:
        sf::Text text;                       // Text to display
        sf::Font font;                       // Font for text
        shared_ptr<sf::RenderWindow> window; // Window to render to
};
} // namespace road_fighter_SFML

#endif // ROAD_FIGHTER_SCORESFML_H
