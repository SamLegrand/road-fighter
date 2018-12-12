//
// Created by sam on 12.12.18.
//

#include "PlayerCarSFML.h"

using namespace road_fighter_SFML;

PlayerCarSFML::PlayerCarSFML() : PlayerCar(), texture(sf::Texture()), sprite(sf::Sprite()) {
    if (!texture.loadFromFile("../../graphics/black_viper.png")) {
        cerr << "Loading texture for Player failed." << endl;
    }
    sprite.setTexture(texture);
}

void PlayerCarSFML::draw(sf::RenderWindow& window) {
    sprite.setPosition(static_cast<float>(xPos), static_cast<float>(yPos));
    window.draw(sprite);
}
