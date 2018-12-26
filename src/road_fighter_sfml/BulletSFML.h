//
// Created by sam on 12.12.18.
//

#ifndef ROAD_FIGHTER_BULLETSFML_H
#define ROAD_FIGHTER_BULLETSFML_H

#include "../road_fighter/Bullet.h"
#include <SFML/Graphics.hpp>

namespace road_fighter_SFML {
    class BulletSFML : public road_fighter::Bullet {
    public:
        BulletSFML();
        BulletSFML(const shared_ptr<sf::RenderWindow>& w);
        void draw() override;
        void handleInput() override {};
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;
    };
}

#endif //ROAD_FIGHTER_BULLETSFML_H
