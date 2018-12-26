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
    double w = width;
    double h = height;
    road_fighter::Transformation::getInstance().dimensionsToRes(w, h);
    sf::Vector2f newSize(static_cast<float>(w), static_cast<float>(h));
    sf::Vector2f oldSize = static_cast<sf::Vector2f>(sprite.getTexture()->getSize());
    sprite.setScale(newSize.x/oldSize.x, newSize.y/oldSize.y);
}

BulletSFML::BulletSFML(const shared_ptr<sf::RenderWindow> &w) : BulletSFML() {
    window = w;
}

void BulletSFML::draw() {
    double x = xPos;
    double y = yPos;
    road_fighter::Transformation::getInstance().coordinatesToRes(x, y);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    window->draw(sprite);
}
