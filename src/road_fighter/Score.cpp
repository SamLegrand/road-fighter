//
// Created by sam on 11.12.18.
//

#include "Score.h"

using namespace road_fighter;

Score::Score() : score(0){}

void Score::update(const double& change) {
    if (score + change > 0) {
        score += change;
    }
    else {
        score = 0;
    }
}
