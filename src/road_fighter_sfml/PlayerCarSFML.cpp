//
// Created by sam on 12.12.18.
//

#include "PlayerCarSFML.h"

using namespace road_fighter_SFML;

PlayerCarSFML::PlayerCarSFML() : PlayerCar(), texture(sf::Texture()), sprite(sf::Sprite()) {
    // Load texture data
    if (!texture.loadFromFile("../graphics/PlayerCar.png")) {
        cerr << "Loading texture for PlayerCar failed." << endl;
    }
    sprite.setTexture(texture);

    // Scale sprite properly
    HelperSFML::getInstance().scaleSprite(sprite, width, height);
}

void PlayerCarSFML::draw() {
    HelperSFML::getInstance().setSpritePosition(sprite, xPos, yPos);
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
