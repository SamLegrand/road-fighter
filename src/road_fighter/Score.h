//
// Created by sam on 11.12.18.
//

#ifndef ROAD_FIGHTER_SCORE_H
#define ROAD_FIGHTER_SCORE_H

#include "Observer.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>

namespace road_fighter {
class Score : public Observer
{
public:
        // Constructor
        Score();

        // Update and display functions
        void update(const double& change) final;
        void update(const string& event) final;

        // File handling
        void readScores();
        void writeScores();

        // Display (for draw call)
        virtual void display() = 0;

protected:
        double score;                // The current score to display
        vector<unsigned int> scores; // List of current scores save file
        bool endVisual;              // Signals game has ended to graphical library
        bool highScore;              // Signals to graphical library that current score is a high score
};
} // namespace road_fighter

#endif // ROAD_FIGHTER_SCORE_H
