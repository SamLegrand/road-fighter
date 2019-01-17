//
// Created by sam on 12.12.18.
//

#include "RacingCarSFML.h"

using namespace road_fighter_SFML;

RacingCarSFML::RacingCarSFML() : RacingCar(), texture(sf::Texture()), sprite(sf::Sprite()) {
    // Load texture data
    if (!texture.loadFromFile("../graphics/RacingCar.png")) {
        cerr << "Loading texture for PlayerCar failed." << endl;
    }
    sprite.setTexture(texture);

    // Scale sprite properly
    ScaleSFML::getInstance().scaleSprite(sprite, width, height);
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
