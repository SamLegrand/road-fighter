//
// Created by sam on 10.12.18.
//

#ifndef ROAD_FIGHTER_RANDOM_H
#define ROAD_FIGHTER_RANDOM_H

#include <iostream>
#include <memory>
#include <random>

using namespace std;

namespace road_fighter {
class Random
{
public:
        // Returns the singleton instance
        static Random& getInstance();

        // Deleting copy constructor and assignment operator (no copies are allowed!)
        Random(Random const&) = delete;
        void operator=(Random const&) = delete;

        // Returns a random double between lowerBound and upperBound
        double getRandom(const double& lowerBound, const double& upperBound);

private:
        // Private constructor (only constructed once)
        Random() = default;
};
} // namespace road_fighter

#endif // ROAD_FIGHTER_RANDOM_H
