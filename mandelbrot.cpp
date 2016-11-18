//
//  mandelbrot.cpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/17/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include "mandelbrot.hpp"

bool isInSet(double real, double imag) {
    std::complex<double> z(0.0, 0.0);
    std::complex<double> c(real, imag);
    for (int i = 0; i < constants::MAX_ITERATIONS; i++) {
        z = z * z + c;
        if (abs(z) > 2) {
            return false;
        }
    }
    return true;
}

Point GetPoint(int j) {
    Point point;
    point.x = j / constants::WINDOW_HEIGHT;
    point.y = j % constants::WINDOW_WIDTH;
    return point;
}

// Allow point to lie in the dimensions defined in globals.hpp
Point NormalizePoint(Point matPoint) {
    Point normalizedPoint;
    normalizedPoint = matPoint;
    normalizedPoint.x = constants::REAL_LOWER_LIMIT + matPoint.y * (4.0 / constants::WINDOW_HEIGHT);
    normalizedPoint.y = constants::IMAG_UPPER_LIMIT - matPoint.x * (4.0 / constants::WINDOW_WIDTH);
    return normalizedPoint;
}
