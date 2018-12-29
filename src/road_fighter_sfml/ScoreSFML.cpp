//
// Created by sam on 29.12.18.
//

#include "ScoreSFML.h"

using namespace road_fighter_SFML;

ScoreSFML::ScoreSFML(const shared_ptr<sf::RenderWindow>& w) : Score(), window(w) {
    if (!font.loadFromFile("../graphics/Font.ttf"))
    {
        cerr << "Couldn't load font data." << endl;
    }
    text.setFont(font);
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(15, 0);
}

void ScoreSFML::display() {
    text.setString("Score: " + to_string(static_cast<int>(round(score))));
    window->draw(text);
}
