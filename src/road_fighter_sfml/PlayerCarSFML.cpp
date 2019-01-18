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

    // Load and set all font data for score display
    if (!font.loadFromFile("../graphics/Font.ttf"))
    {
        cerr << "Couldn't load font data." << endl;
    }
    text.setFont(font);
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(15, 30);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(1);

    // Scale sprite properly
    HelperSFML::getInstance().scaleSprite(sprite, width, height);
}

void PlayerCarSFML::draw() {
    HelperSFML::getInstance().setSpritePosition(sprite, xPos, yPos);
    window->draw(sprite);
    if (getBulletCount() == getBulletCapacity()) {
        text.setString("Bullets: max");
    }
    else {
        text.setString("Bullets: " + to_string(getBulletCount()));
    }
    window->draw(text);
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
