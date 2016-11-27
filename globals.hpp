//
//  globals.hpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <SDL2/SDL.h>
#include <complex>
#define PI 3.14159

namespace constants {
    const unsigned int WINDOW_WIDTH   =   800;
    const unsigned int WINDOW_HEIGHT  =  WINDOW_WIDTH;
    const unsigned int MAX_ITERATIONS =   500;
    const double REAL_LOWER_LIMIT =  -1.5;
    const double REAL_UPPER_LIMIT =   1.5;
    const double IMAG_LOWER_LIMIT =  -1.5;
    const double IMAG_UPPER_LIMIT =   1.5;
    const unsigned long COLOR_WHITE = 4294967295;
    const std::complex<double> JULIA_CONSTANT(-0.4, 0.6);
}

#endif /* globals_hpp */
