//
// Created by sam on 17.01.19.
//

#ifndef ROAD_FIGHTER_SCALESFML_H
#define ROAD_FIGHTER_SCALESFML_H

#include <SFML/Graphics.hpp>
#include "../road_fighter/Transformation.h"

namespace road_fighter_SFML {
    class ScaleSFML {
    public:
        // Returns the singleton instance
        static ScaleSFML& getInstance();

        // Deleting copy constructor and assignment operator (no copies are allowed!)
        ScaleSFML(ScaleSFML const&) = delete;
        void operator=(ScaleSFML const&)  = delete;

        // Scales given sprite to given world width and height
        void scaleSprite(sf::Sprite& sprite, const double& width, const double& height);

        // Scales given sprite to given world width (keeps ratio)
        void scaleSprite(sf::Sprite& sprite, const double& width);

    private:
        // Private constructor (constructs only once)
        ScaleSFML() : width(0), height(0) {};

        // Resolution parameters
        unsigned int width;
        unsigned int height;
    };
}

#endif //ROAD_FIGHTER_SCALESFML_H
