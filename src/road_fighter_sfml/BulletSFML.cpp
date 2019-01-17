//
// Created by sam on 12.12.18.
//

#include "BulletSFML.h"

using namespace road_fighter_SFML;

BulletSFML::BulletSFML() : Bullet(0.1, 0.3) {
    if (!texture.loadFromFile("../graphics/Bullet.png")) {
        cerr << "Loading texture for PlayerCar failed." << endl;
    }
    sprite.setTexture(texture);

    // Properly scale sprite
    ScaleSFML::getInstance().scaleSprite(sprite, width, height);
}

BulletSFML::BulletSFML(const shared_ptr<sf::RenderWindow> &w) : BulletSFML() {
    window = w;
}

void BulletSFML::draw() {
    // Don't execute draw calls when bullet is not on screen
    if (yPos + height >= -3) {
        double x = xPos;
        double y = yPos;
        road_fighter::Transformation::getInstance().coordinatesToRes(x, y);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        window->draw(sprite);
    }
}
