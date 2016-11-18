//
//  mandelbrot.hpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/17/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#ifndef mandelbrot_hpp
#define mandelbrot_hpp

#include <SDL2/SDL.h>
#include <complex>
#include "globals.hpp"

typedef struct Point_struct {
    double x;
    double y;
} Point;

int isInSet(double real, double imag);
Point GetPoint(int j);
Point NormalizePoint(Point matPoint);

#endif /* mandelbrot_hpp */
