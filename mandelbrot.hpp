//
//  mandelbrot.hpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/17/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

#include <SDL2/SDL.h>
#include <complex>
#include <math.h>
#include "globals.hpp"

typedef struct Point_struct {
    double x;
    double y;
} Point;

Uint32 isInSet(double real, double imag);
Point GetPoint(int j);
Point NormalizePoint(Point matPoint);

#endif /* MANDELBROT_HPP */
