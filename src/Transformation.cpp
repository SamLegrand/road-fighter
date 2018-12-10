//
// Created by sam on 10.12.18.
//

#include "Transformation.h"

shared_ptr<Transformation> Transformation::getInstance() {
    if (instance == nullptr) {
        instance = make_shared<Transformation>(instance);
    }
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
