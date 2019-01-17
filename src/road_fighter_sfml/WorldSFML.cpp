//
// Created by sam on 25.12.18.
//

#include "WorldSFML.h"

using namespace road_fighter_SFML;

WorldSFML::WorldSFML() : World(), roadTexture(sf::Texture()), roadSprite1(sf::Sprite()) {
    // Load textures
    if (!roadTexture.loadFromFile("../graphics/Road.png")) {
        cerr << "Loading texture for road failed." << endl;
    }
    if (!finishTexture.loadFromFile("../graphics/FinishLine.png")) {
        cerr << "Loading texture for finish line failed." << endl;
    }
    roadSprite1.setTexture(roadTexture);
    finishSprite.setTexture(finishTexture);

    // Properly scale world sprite
    ScaleSFML::getInstance().scaleSprite(roadSprite1, width, height);
    roadSprite2 = roadSprite1;

    // Properly scale finish line sprite
    double width = rightBound - leftBound;
    ScaleSFML::getInstance().scaleSprite(finishSprite, width);
}

// WorldSFML constructor
WorldSFML::WorldSFML(const shared_ptr<sf::RenderWindow>& w) : WorldSFML() {
    window = w;
    addObserver(make_shared<ScoreSFML>(w));
}

void WorldSFML::drawSelf() {
    // Convert width and height to resolution
    double w = width;
    double h = height;
    road_fighter::Transformation::getInstance().dimensionsToRes(w, h);

    // Convert position to resolution
    double x = xPos;
    double y = yPos;
    road_fighter::Transformation::getInstance().coordinatesToRes(x, y);
    auto spriteY = static_cast<float>(static_cast<int>(y)%static_cast<int>(h));
    roadSprite1.setPosition(static_cast<float>(x), spriteY);
    roadSprite2.setPosition(static_cast<float>(x), spriteY - static_cast<float>(h));
    window->draw(roadSprite1);
    window->draw(roadSprite2);

    // Draw finish line (no draw calls when not on screen)
    if (yPos + height >= getLength()) {
        double l = leftBound;
        double finishY = yPos - getLength();
        road_fighter::Transformation::getInstance().coordinatesToRes(l, finishY);
        finishSprite.setPosition(static_cast<float>(l), static_cast<float>(finishY));
        window->draw(finishSprite);
    }
}
