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
        // Returns the singleton instance
        static Transformation& getInstance();

        // Deleting copy constructor and assignment operator (no copies are allowed!)
        Transformation(Transformation const&) = delete;
        void operator=(Transformation const&)  = delete;

        // Set the resolution for proper coordinate calculation
        void setResolution(const unsigned int& width, const unsigned int& height);

        // Conversion functions
        void coordinatesToRes(double &x, double &y);
        void dimensionsToRes(double &w, double &h);

    private:
        // Private constructor (constructs only once)
        Transformation() : width(0), height(0) {};

        // Resolution parameters
        unsigned int width;
        unsigned int height;
    };
}

#endif //ROAD_FIGHTER_TRANSFORMATION_H
