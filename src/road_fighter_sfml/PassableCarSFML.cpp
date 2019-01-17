//
// Created by sam on 12.12.18.
//

#include "PassableCarSFML.h"

using namespace road_fighter_SFML;

PassableCarSFML::PassableCarSFML() : PassableCar(0.4, 0.8) {
    if (!texture.loadFromFile("../graphics/" + type + ".png")) {
        cerr << "Loading texture for PlayerCar failed." << endl;
    }
    sprite.setTexture(texture);

    // Properly scale sprite
    ScaleSFML::getInstance().scaleSprite(sprite, width, height);
}

PassableCarSFML::PassableCarSFML(const shared_ptr<sf::RenderWindow> &w) : PassableCarSFML() {
    window = w;
}

void PassableCarSFML::draw() {
    // Don't execute draw calls when car is not on screen
    if (yPos + height >= -3 && yPos <= 3) {
        double x = xPos;
        double y = yPos;
        road_fighter::Transformation::getInstance().coordinatesToRes(x, y);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        window->draw(sprite);
    }
}
