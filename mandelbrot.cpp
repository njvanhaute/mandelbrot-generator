//
//  mandelbrot.cpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/17/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include "mandelbrot.hpp"

bool isInSet(double real, double imag) {
    std::complex<double> z(0, 0);
    std::complex<double> c(real, imag);
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        z = z * z + c;
        if (abs(z) > 2) {
            return false;
        }
    }
    return true;
}
