//
// Created by sam on 12.12.18.
//

#include "PlayerCarSFML.h"

using namespace road_fighter_SFML;

PlayerCarSFML::PlayerCarSFML() : PlayerCar(), texture(sf::Texture()), sprite(sf::Sprite()) {
    if (!texture.loadFromFile("../graphics/temp.png")) {
        cerr << "Loading texture for PlayerCar failed." << endl;
    }
    sprite.setTexture(texture);
}

void PlayerCarSFML::draw() {
    double x = xPos;
    double y = yPos;
    road_fighter::Transformation::getInstance().convertToResolution(x, y);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    window->draw(sprite);
}

PlayerCarSFML::PlayerCarSFML(const shared_ptr<sf::RenderWindow>& w) : PlayerCarSFML() {
    window = w;
}

void PlayerCarSFML::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        moveLeft(0.0001);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveRight(0.0001);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        moveUp(0.0001);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        moveDown(0.0001);
    }
}
