//
// Created by sam on 17.01.19.
//

#include "HelperSFML.h"

using namespace road_fighter_SFML;

HelperSFML& HelperSFML::getInstance() {
    static HelperSFML instance;
    return instance;
}

void HelperSFML::scaleSprite(sf::Sprite& sprite, const double& width, const double& height) {
    double w = width;
    double h = height;
    road_fighter::Transformation::getInstance().dimensionsToRes(w, h);
    sf::Vector2f newSize(static_cast<float>(w), static_cast<float>(h));
    sf::Vector2f oldSize = static_cast<sf::Vector2f>(sprite.getTexture()->getSize());
    sprite.setScale(newSize.x/oldSize.x, newSize.y/oldSize.y);
}

void HelperSFML::scaleSprite(sf::Sprite &sprite, const double &width) {
    double w = width;
    double h = 0;
    road_fighter::Transformation::getInstance().dimensionsToRes(w, h);
    sf::Vector2f oldSize = static_cast<sf::Vector2f>(sprite.getTexture()->getSize());
    sprite.setScale(static_cast<float>(w)/oldSize.x, static_cast<float>(w)/oldSize.x);
}

void HelperSFML::setSpritePosition(sf::Sprite &sprite, const double &xPos, const double &yPos) {
    double x = xPos;
    double y = yPos;
    road_fighter::Transformation::getInstance().coordinatesToRes(x, y);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
}
