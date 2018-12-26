//
// Created by sam on 25.12.18.
//

#include "WorldSFML.h"

using namespace road_fighter_SFML;

WorldSFML::WorldSFML() : World(), roadTexture(sf::Texture()), roadSprite1(sf::Sprite()), counter(1) {
    if (!roadTexture.loadFromFile("../graphics/Road.png")) {
        cerr << "Loading texture for road failed." << endl;
    }
    roadSprite1.setTexture(roadTexture);
    double w = width;
    double h = height;
    road_fighter::Transformation::getInstance().dimensionsToRes(w, h);
    sf::Vector2f newSize(static_cast<float>(w), static_cast<float>(h));
    sf::Vector2f oldSize = static_cast<sf::Vector2f>(roadSprite1.getTexture()->getSize());
    roadSprite1.setScale(newSize.x/oldSize.x, newSize.y/oldSize.y);
    roadSprite2 = roadSprite1;
}

WorldSFML::WorldSFML(const shared_ptr<sf::RenderWindow>& w) : WorldSFML() {
    window = w;
}

void WorldSFML::drawSelf() {
    double w = width;
    double h = height;
    road_fighter::Transformation::getInstance().dimensionsToRes(w, h);
    double x = xPos;
    double y = yPos;
    road_fighter::Transformation::getInstance().coordinatesToRes(x, y);
    auto spriteY = static_cast<float>(static_cast<int>(y)%static_cast<int>(h));
    roadSprite1.setPosition(static_cast<float>(x), spriteY);
    roadSprite2.setPosition(static_cast<float>(x), spriteY - static_cast<float>(h));
    window->draw(roadSprite1);
    window->draw(roadSprite2);
}

void WorldSFML::handleInput() {
    handleInputEntities();
}
