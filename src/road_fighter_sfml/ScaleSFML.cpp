//
// Created by sam on 17.01.19.
//

#include "ScaleSFML.h"

using namespace road_fighter_SFML;

ScaleSFML& ScaleSFML::getInstance() {
    static ScaleSFML instance;
    return instance;
}

void ScaleSFML::scaleSprite(sf::Sprite& sprite, const double& width, const double& height) {
    double w = width;
    double h = height;
    road_fighter::Transformation::getInstance().dimensionsToRes(w, h);
    sf::Vector2f newSize(static_cast<float>(w), static_cast<float>(h));
    sf::Vector2f oldSize = static_cast<sf::Vector2f>(sprite.getTexture()->getSize());
    sprite.setScale(newSize.x/oldSize.x, newSize.y/oldSize.y);
}

void ScaleSFML::scaleSprite(sf::Sprite &sprite, const double &width) {
    double w = width;
    double h = 0;
    road_fighter::Transformation::getInstance().dimensionsToRes(w, h);
    sf::Vector2f oldSize = static_cast<sf::Vector2f>(sprite.getTexture()->getSize());
    sprite.setScale(static_cast<float>(w)/oldSize.x, static_cast<float>(w)/oldSize.x);
}
