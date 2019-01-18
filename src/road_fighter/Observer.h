//
// Created by sam on 11.12.18.
//

#ifndef ROAD_FIGHTER_OBSERVER_H
#define ROAD_FIGHTER_OBSERVER_H

#include <iostream>
using namespace std;

namespace road_fighter {
// Abstract base class for observers
class Observer
{
public:
        virtual void update(const double& change) = 0;
        virtual void update(const string& event) = 0;
};
} // namespace road_fighter

#endif // ROAD_FIGHTER_OBSERVER_H
