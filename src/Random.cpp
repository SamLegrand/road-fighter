//
// Created by sam on 10.12.18.
//

#include "Random.h"

shared_ptr<Random> Random::getInstance() {
    if (instance == nullptr) {
        instance = make_shared<Random>();
    }
    return instance;
}

double Random::getRandom(const double& lowerBound, const double& upperBound) {
    std::uniform_real_distribution<double> distribution(lowerBound, upperBound);
    random_device device;
    std::mt19937 engine(device);
    return distribution(engine);
}
