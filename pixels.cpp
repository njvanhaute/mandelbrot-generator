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
    for (int j = constants::WINDOW_WIDTH/ 2; j < constants::WINDOW_HEIGHT * constants::WINDOW_WIDTH; j += constants::WINDOW_WIDTH) {
        pixels[j] = 0;
    }
    for (int j = (constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT) / 2; j < (constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT) / 2 + constants::WINDOW_WIDTH; j++) {
        pixels[j] = 0;
    }
}

void GenerateSet(Uint32 *pixels) {
    for (int j = 0; j < constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT; j++) {
        Point xyPoint = GetPoint(j);
        //printf("DEBUG: For int %d, x = %.2lf, y = %.2lf\n", j, xyPoint.x, xyPoint.y);
        xyPoint = NormalizePoint(xyPoint);
        pixels[j] = isInSet(xyPoint.x, xyPoint.y);
    }
}
