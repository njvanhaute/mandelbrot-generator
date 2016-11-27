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
#include "helperfunctions.hpp"
#include <math.h>

void initPixels(Uint32 *pixels);
void addAxes(Uint32 *pixels);
void GenerateSet(Uint32 *pixels, Uint32 *palette);
void AddWeirdEffect(Uint32 *pixels);
void AllColors(Uint32 *pixels);
void GeneratePalette(Uint32 *palette);

#endif /* PIXELS_HPP */
