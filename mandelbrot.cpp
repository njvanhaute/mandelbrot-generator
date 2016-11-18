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

Point GetPoint(Uint32 pixel) {
    Point point;
    point.x = pixel / 640;
    point.y = pixel % 640;
    return point;
}

// Allow point to lie in the dimensions defined in globals.hpp
Point NormalizePoint(Point matPoint) {
    Point normalizedPoint;
    normalizedPoint = matPoint;
    normalizedPoint.x = -2.0 + matPoint.y * (1.0 / 160);
    normalizedPoint.y = 2.0 - matPoint.x * (1.0 / 160);
    return normalizedPoint;
}
