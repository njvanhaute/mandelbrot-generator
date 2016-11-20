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

namespace constants {
    const unsigned int WINDOW_WIDTH   =  4000;
    const unsigned int WINDOW_HEIGHT  =  4000;
    const unsigned int MAX_ITERATIONS =  1000;
    const double REAL_LOWER_LIMIT = -0.70;
    const double REAL_UPPER_LIMIT =  -0.45;
    const double IMAG_LOWER_LIMIT = -0.3;
    const double IMAG_UPPER_LIMIT =  -0.05;
    const unsigned long COLOR_WHITE = 4294967295;
}

#endif /* globals_hpp */
