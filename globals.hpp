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

namespace constants {
    const unsigned int WINDOW_WIDTH   =  1500;
    const unsigned int WINDOW_HEIGHT  =  1500;
    const unsigned int MAX_ITERATIONS =  1000;
    const double REAL_LOWER_LIMIT = -0.752598855;
    const double REAL_UPPER_LIMIT = -0.751105594;
    const double IMAG_LOWER_LIMIT =  0.034151768261;
    const double IMAG_UPPER_LIMIT =  0.035645029578;
    const unsigned long COLOR_WHITE = 4294967295;
    const std::complex<double> JULIA_CONSTANT(-0.4, 0.6);
}

#endif /* globals_hpp */
