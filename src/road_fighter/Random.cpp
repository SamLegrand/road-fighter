//
// Created by sam on 10.12.18.
//

#include "Random.h"

using namespace road_fighter;

Random& Random::getInstance() {
    static Random instance;
    return instance;
}

double Random::getRandom(const double& lowerBound, const double& upperBound) {
    random_device device;
    std::mt19937 engine(device());
    std::uniform_real_distribution<double> distribution(lowerBound, upperBound);
    return distribution(engine);
}
