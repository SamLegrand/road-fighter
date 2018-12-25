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

void Transformation::convertToWorldSpace(double &x, double &y) {
    if (width == 0 || height == 0) {
        cerr << "Resolution has not been set." << endl;
    }
    if (x > 0 && x < width) {
        x = x/width * 8 - 4;
    }
    else {
        cerr << "Invalid x-coordinate: " << x << endl;
    }
    if (y > 0 && y < height) {
        y = y/height * 6 - 3;
    }
    else {
        cerr << "Invalid y-coordinate: " << y << endl;
    }
}

void Transformation::coordinatesToRes(double &x, double &y){
    if (width == 0 || height == 0) {
        cerr << "Resolution has not been set." << endl;
    }
    x = (x + 4)/8 * width;
    y = (y + 3)/6 * height;
}

void Transformation::dimensionsToRes(double &w, double &h) {
    if (width == 0 || height == 0) {
        cerr << "Resolution has not been set." << endl;
    }
    w = w/8 * width;
    h = h/6 * height;
}
