//
// Created by sam on 17.01.19.
//

#ifndef ROAD_FIGHTER_SCALESFML_H
#define ROAD_FIGHTER_SCALESFML_H

#include <SFML/Graphics.hpp>
#include "../road_fighter/Transformation.h"

namespace road_fighter_SFML {
    class HelperSFML {
    public:
        // Returns the singleton instance
        static HelperSFML& getInstance();

        // Deleting copy constructor and assignment operator (no copies are allowed!)
        HelperSFML(HelperSFML const&) = delete;
        void operator=(HelperSFML const&)  = delete;

        // Scales given sprite to given world width and height
        void scaleSprite(sf::Sprite& sprite, const double& width, const double& height);

        // Scales given sprite to given world width (keeps ratio)
        void scaleSprite(sf::Sprite& sprite, const double& width);

        // Sets sprite position (in resolution coordinates)
        void setSpritePosition(sf::Sprite& sprite, const double& xPos, const double& yPos);

    private:
        // Private constructor (constructs only once)
        HelperSFML() : width(0), height(0) {};

        // Resolution parameters
        unsigned int width;
        unsigned int height;
    };
}

#endif //ROAD_FIGHTER_SCALESFML_H
