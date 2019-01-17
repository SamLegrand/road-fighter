//
// Created by sam on 12.12.18.
//

#include "BulletSFML.h"

using namespace road_fighter_SFML;

BulletSFML::BulletSFML() : Bullet(0.1, 0.3) {
    // Load texture data
    if (!texture.loadFromFile("../graphics/Bullet.png")) {
        cerr << "Loading texture for PlayerCar failed." << endl;
    }
    sprite.setTexture(texture);

    // Properly scale sprite
    HelperSFML::getInstance().scaleSprite(sprite, width, height);
}

BulletSFML::BulletSFML(const shared_ptr<sf::RenderWindow> &w) : BulletSFML() {
    window = w;
}

void BulletSFML::draw() {
    // Don't execute draw calls when bullet is not on screen
    if (yPos + height >= -3) {
        HelperSFML::getInstance().setSpritePosition(sprite, xPos, yPos);
        window->draw(sprite);
    }
}
