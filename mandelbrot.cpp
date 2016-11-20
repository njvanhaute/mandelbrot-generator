//
//  mandelbrot.cpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/17/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//
// (i * 20) % 255 is a good one

#include "mandelbrot.hpp"

Uint32 isInSet(double real, double imag) {
    std::complex<double> z(0.0, 0.0);
    std::complex<double> c(real, imag);
    const std::complex<double> JULIA_CONSTANT(-0.4, 0.6);
    z = c;
    for (Uint32 i = 1; i <= constants::MAX_ITERATIONS; i++) {
        z = z * z + JULIA_CONSTANT;
        if (abs(z) > 2) {
            return (constants::COLOR_WHITE) - i * i + i * 200;
        }
    }
    return constants::COLOR_WHITE;
}

Point GetPoint(int j) {
    Point point;
    point.x = j % constants::WINDOW_WIDTH;
    point.y = j / constants::WINDOW_WIDTH;
    return point;
}

// Allow point to lie in the dimensions specified in globals.hpp
Point NormalizePoint(Point matPoint) {
    Point normalizedPoint;
    normalizedPoint = matPoint;
    normalizedPoint.x = constants::REAL_LOWER_LIMIT + matPoint.x * ((constants::REAL_UPPER_LIMIT - constants::REAL_LOWER_LIMIT) / constants::WINDOW_WIDTH);
    normalizedPoint.y = constants::IMAG_UPPER_LIMIT - matPoint.y * ((constants::IMAG_UPPER_LIMIT - constants::IMAG_LOWER_LIMIT) / constants::WINDOW_HEIGHT);
    return normalizedPoint;
}
