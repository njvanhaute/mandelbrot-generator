//
//  pixels.hpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/17/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#ifndef PIXELS_HPP
#define PIXELS_HPP

#include <SDL2/SDL.h>
#include <string.h>
#include "globals.hpp"
#include "mandelbrot.hpp"

void initPixels(Uint32 *pixels);
void addAxes(Uint32 *pixels);
void GenerateSet(Uint32 *pixels);
void AddWeirdEffect(Uint32 *pixels);

#endif /* PIXELS_HPP */
