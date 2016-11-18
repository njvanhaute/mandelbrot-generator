//
//  pixels.cpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/17/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include "pixels.hpp"

void initPixels(Uint32 *pixels) {
    memset(pixels, 255, constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT * sizeof(Uint32));
}

void addAxes(Uint32 *pixels) {
    for (int j = 320; j < 409599; j += 640) {
        pixels[j] = 0;
    }
    for (int j = 204800; j < 204800 + 640; j++) {
        pixels[j] = 0;
    }
}

void GenerateSet(Uint32 *pixels) {
    for (int j = 0; j < constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT; j++) {
        Point xyPoint = GetPoint(pixels[j]);
        xyPoint = NormalizePoint(xyPoint);
        if (isInSet(xyPoint.x, xyPoint.y)) {
            pixels[j] = 0;
        }
    }
}
