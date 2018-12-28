//
// Created by sam on 12.12.18.
//

#include "PlayerCarSFML.h"

using namespace road_fighter_SFML;

PlayerCarSFML::PlayerCarSFML() : PlayerCar(), texture(sf::Texture()), sprite(sf::Sprite()) {
    if (!texture.loadFromFile("../graphics/PlayerCar.png")) {
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

void PlayerCarSFML::draw() {
    double x = xPos;
    double y = yPos;
    road_fighter::Transformation::getInstance().coordinatesToRes(x, y);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    window->draw(sprite);
}

PlayerCarSFML::PlayerCarSFML(const shared_ptr<sf::RenderWindow>& w) : PlayerCarSFML() {
    window = w;
}

void PlayerCarSFML::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        moveDown();
    }
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
        setBlockShoot(false);
    }
}
