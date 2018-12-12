//
// Created by sam on 10.12.18.
//

#ifndef ROAD_FIGHTER_TRANSFORMATION_H
#define ROAD_FIGHTER_TRANSFORMATION_H

#include <memory>
#include <iostream>

using namespace std;

namespace road_fighter {
    class Transformation {
    public:
    public:
        /**
         * @brief Function that returns the instance of the Transformation singleton
         * @return instance of Transformation singleton
         */
        static Transformation& getInstance();
        Transformation(Transformation const&) = delete;
        void operator=(Transformation const&)  = delete;
        void setResolution(const unsigned int& width, const unsigned int& height);

        void convertToWorldSpace(double& x, double& y);
        void convertToResolution(double& x, double& y);

    private:
        Transformation() : width(0), height(0) {};
        unsigned int width;
        unsigned int height;
    };
}

#endif //ROAD_FIGHTER_TRANSFORMATION_H
