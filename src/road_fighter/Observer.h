//
// Created by sam on 11.12.18.
//

#ifndef ROAD_FIGHTER_OBSERVER_H
#define ROAD_FIGHTER_OBSERVER_H

namespace road_fighter {
    class Observer {
    public:
        virtual void update(const double& change) = 0;
    };
}


#endif //ROAD_FIGHTER_OBSERVER_H
