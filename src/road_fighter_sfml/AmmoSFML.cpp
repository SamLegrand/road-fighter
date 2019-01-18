//
// Created by sam on 18.01.19.
//

#include "AmmoSFML.h"

using namespace road_fighter_SFML;

AmmoSFML::AmmoSFML() : Ammo(0.15, 0.15)
{
        // Load texture data
        if (!texture.loadFromFile("../graphics/Ammo.png")) {
                cerr << "Loading texture for Ammo failed." << endl;
        }
        sprite.setTexture(texture);

        // Properly scale sprite
        HelperSFML::getInstance().scaleSprite(sprite, width, height);
}

AmmoSFML::AmmoSFML(const shared_ptr<sf::RenderWindow>& w) : AmmoSFML() { window = w; }

void AmmoSFML::draw()
{
        // Don't execute draw calls when ammo is not on screen
        if (yPos + height >= -3 && yPos <= 3) {
                HelperSFML::getInstance().setSpritePosition(sprite, xPos, yPos);
                window->draw(sprite);
        }
}
