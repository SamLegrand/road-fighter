//
// Created by sam on 11.12.18.
//

#include "Score.h"

using namespace road_fighter;

Score::Score() : score(0), scores({}), endVisual(false), highScore(false) {}

void Score::update(const double& change)
{
        if (score + change > 0) {
                score += change;
        } else {
                score = 0; // Prevent negative scores
        }
}

void Score::update(const string& event)
{
        if (event == "GameEnd" && !endVisual) {
                // Process to add new score to score list and determine if it's a high score
                readScores();
                auto it = std::lower_bound(scores.begin(), scores.end(), score, std::greater<>());
                scores.insert(it, static_cast<unsigned int>(round(score)));
                if (scores.size() > 10) {
                        scores.pop_back();
                }
                if (scores.front() == static_cast<unsigned int>(round(score))) {
                        highScore = true;
                }
                writeScores();
                endVisual = true;
        }
}

void Score::readScores()
{
        // Read from scores save file and parse to list
        ifstream input("../saves/scores.txt");
        if (!input) {
                return;
        }
        string line;
        while (getline(input, line)) {
                istringstream iss(line);
                unsigned int score;
                if (!(iss >> score)) {
                        break;
                }
                scores.emplace_back(score);
        }
}

void Score::writeScores()
{
        // Write score list to save file
        ofstream output("../saves/scores.txt");
        for (const unsigned int& score : scores) {
                output << score << endl;
        }
}
