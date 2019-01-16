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
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(1);
}

void ScoreSFML::display() {
    if (endVisual) {
        sf::FloatRect fr = text.getGlobalBounds();
        double x = 0;
        double y = 0;
        road_fighter::Transformation::getInstance().coordinatesToRes(x, y);
        text.setCharacterSize(80);
        text.setOutlineColor(sf::Color::Red);
        text.setOutlineThickness(2);
        text.setPosition(static_cast<float>(x) - fr.width/2, static_cast<float>(y) - 100);
        if (highScore) {
            sf::Text highScoreText;
            highScoreText.setString("HIGH SCORE!");
            highScoreText.setFont(font);
            highScoreText.setCharacterSize(50);
            highScoreText.setFillColor(sf::Color::Red);
            highScoreText.setOutlineColor(sf::Color::Yellow);
            highScoreText.setOutlineThickness(1.5f);
            highScoreText.setStyle(sf::Text::Bold);
            highScoreText.setPosition(static_cast<float>(x) - highScoreText.getGlobalBounds().width/2, static_cast<float>(y) - 140);
            window->draw(highScoreText);
        }
        sf::Text hallOfFame;
        hallOfFame.setFont(font);
        hallOfFame.setCharacterSize(40);
        hallOfFame.setFillColor(sf::Color::White);
        hallOfFame.setStyle(sf::Text::Bold);
        hallOfFame.setOutlineColor(sf::Color::Black);
        hallOfFame.setOutlineThickness(1);
        unsigned int counter = 1;
        for (const unsigned int& s : scores) {
            if (s == static_cast<unsigned int>(round(score))) {
                hallOfFame.setOutlineColor(sf::Color::Red);
            }
            else {
                hallOfFame.setOutlineColor(sf::Color::Black);
            }
            hallOfFame.setString(to_string(counter) + ". " + to_string(s));
            hallOfFame.setPosition(static_cast<float>(x) - hallOfFame.getGlobalBounds().width/2, static_cast<float>(y) - 50 + 40 * counter);
            window->draw(hallOfFame);
            ++counter;
        }
    }
    text.setString("Score: " + to_string(static_cast<int>(round(score))));
    window->draw(text);
}
