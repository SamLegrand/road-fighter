//
// Created by sam on 12.12.18.
//

#include "RacingCarSFML.h"

using namespace road_fighter_SFML;

RacingCarSFML::RacingCarSFML() : RacingCar(), texture(sf::Texture()), sprite(sf::Sprite()) {
    if (!texture.loadFromFile("../graphics/RacingCar.png")) {
        cerr << "Loading texture for PlayerCar failed." << endl;
    }
    sprite.setTexture(texture);
    double w = width;
    double h = height;
    road_fighter::Transformation::getInstance().dimensionsToRes(w, h);
    sf::Vector2f newSize(static_cast<float>(w), static_cast<float>(h));
    sf::Vector2f oldSize = static_cast<sf::Vector2f>(sprite.getTexture()->getSize());
    sprite.setScale(newSize.x/oldSize.x, newSize.y/oldSize.y);
}

void RacingCarSFML::draw() {
    // Don't execute draw calls when car is not on screen
    if (yPos + height >= -3 && yPos <= 3) {
        double x = xPos;
        double y = yPos;
        road_fighter::Transformation::getInstance().coordinatesToRes(x, y);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        window->draw(sprite);
    }
}

RacingCarSFML::RacingCarSFML(const shared_ptr<sf::RenderWindow>& w) : RacingCarSFML() {
    window = w;
}
