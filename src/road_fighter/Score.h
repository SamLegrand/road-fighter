//
// Created by sam on 11.12.18.
//

#ifndef ROAD_FIGHTER_SCORE_H
#define ROAD_FIGHTER_SCORE_H

#include "Observer.h"

namespace road_fighter {
    class Score : public Observer {
        void update() final;
    };
}


#endif //ROAD_FIGHTER_SCORE_H
