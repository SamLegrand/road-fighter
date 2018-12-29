//
// Created by sam on 11.12.18.
//

#ifndef ROAD_FIGHTER_SCORE_H
#define ROAD_FIGHTER_SCORE_H

#include "Observer.h"

namespace road_fighter {
    class Score : public Observer {
    public:
        // Constructor
        Score();

        // Update and display functions
        void update(const double& change) final;
        virtual void display() = 0;

    protected:
        double score;   // The current score to display
    };
}


#endif //ROAD_FIGHTER_SCORE_H
