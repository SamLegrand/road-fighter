//
// Created by sam on 10.12.18.
//

#ifndef ROAD_FIGHTER_RANDOM_H
#define ROAD_FIGHTER_RANDOM_H

#include <memory>
#include <random>
#include <iostream>

using namespace std;

namespace road_fighter {
    class Random {
    public:
        /**
         * @brief Function that returns the instance of the Random singleton
         * @return instance of Random singleton
         */
        Random& getInstance();

        // Make sure no copies or assignments are valid
        Random(Random const&) = delete;
        void operator=(Random const&)  = delete;

        /**
         * @brief Function that generates a random real number
         * @param lowerBound lower bound of generated number
         * @param upperBound upper bound of generated number
         * @return double between lower and upper bound
         */
        double getRandom(const double& lowerBound, const double& upperBound);

    private:
        Random() = default;
    };
}

#endif //ROAD_FIGHTER_RANDOM_H
