//
// Created by sam on 12.12.18.
//

#include "PassableCarSFML.h"

using namespace road_fighter_SFML;

PassableCarSFML::PassableCarSFML() : PassableCar(0.4, 0.8, "normal") {
    if (!texture.loadFromFile("../graphics/PassableCar.png")) {
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

PassableCarSFML::PassableCarSFML(const shared_ptr<sf::RenderWindow> &w) : PassableCarSFML() {
    window = w;
}

void PassableCarSFML::draw() {
    double x = xPos;
    double y = yPos;
    road_fighter::Transformation::getInstance().coordinatesToRes(x, y);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    window->draw(sprite);
}
