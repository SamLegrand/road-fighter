//
// Created by sam on 11.12.18.
//

#ifndef ROAD_FIGHTER_GAME_H
#define ROAD_FIGHTER_GAME_H

#include "World.h"
#include "PlayerCar.h"

namespace road_fighter {
    class Game {
    public:
        Game();

    private:
        unique_ptr<World> world;
    };
}

#endif //ROAD_FIGHTER_GAME_H
