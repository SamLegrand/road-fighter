//
// Created by sam on 10.12.18.
//

#include "Transformation.h"

using namespace road_fighter;

Transformation& Transformation::getInstance() {
    static Transformation instance;
    return instance;
}

void Transformation::setResolution(const unsigned int &width, const unsigned int &height) {
    this->width = width;
    this->height = height;
}

void Transformation::coordinatesToRes(double &x, double &y){
    if (width == 0 || height == 0) {
        cerr << "Resolution has not been set." << endl; // Make sure resolution has been set!
    }
    x = (x + 4)/8 * width;  // Coordinate offset and scale
    y = (y + 3)/6 * height;
}

void Transformation::dimensionsToRes(double &w, double &h) {
    if (width == 0 || height == 0) {
        cerr << "Resolution has not been set." << endl;
    }
    w = w/8 * width;    // Only coordinate scale
    h = h/6 * height;
}
