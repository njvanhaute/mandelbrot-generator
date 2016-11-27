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
    for (int j = constants::WINDOW_WIDTH / 2; j < constants::WINDOW_HEIGHT * constants::WINDOW_WIDTH; j += constants::WINDOW_WIDTH) {
        pixels[j] = 0;
    }
    for (int j = (constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT) / 2; j < (constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT) / 2 + constants::WINDOW_WIDTH; j++) {
        pixels[j] = 0;
    }
}

void GenerateSet(Uint32 *pixels, Uint32 *palette) {
    for (int j = 0; j < constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT; j++) {
        Point xyPoint = GetPoint(j);
        xyPoint = NormalizePoint(xyPoint);
        pixels[j] = isInSet(xyPoint.x, xyPoint.y, palette);
    }
}

void AddWeirdEffect(Uint32 *pixels) {
    for (int j = 1; j < constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT - 1; j++) {
        pixels[j] = (pixels[j - 1] + pixels[j] + pixels[j + 1]) / 3;
    }
}

void AllColors(Uint32 *pixels) {
    for (int j = 0; j < 256; j++) {
        pixels[j] = 0b00000001000000000000001 * j + 0b11111111000000000000000000000000;
    }
}

void GeneratePalette(Uint32 *palette) {
    Uint32 *colorWheel = new Uint32[constants::WINDOW_WIDTH * constants::WINDOW_WIDTH];
    const int R = 0.5 * constants::WINDOW_WIDTH;
    const double factor = 0.35;
    const int XR = R + factor * R * cos(0);
    const int YR = R + factor * R * sin(0);
    const double XB = R + factor * R * cos(2 * PI / 3);
    const double YB = R + factor * R * sin(2 * PI / 3);
    const double XG = R + factor * R * cos(4 * PI / 3);
    const double YG = R + factor * R * sin(4 * PI / 3);
    for (int y = 0; y < 2 * R; y++) {
        for (int x = 0; x < 2 * R; x++) {
            int redComp   = 255 - (int)dist(x, y, XR, YR) < 0 ? 0 : 255 - (int)dist(x, y, XR, YR);
            int blueComp  = 255 - (int)dist(x, y, XB, YB) < 0 ? 0 : 255 - (int)dist(x, y, XB, YB);
            int greenComp = 255 - (int)dist(x, y, XG, YG) < 0 ? 0 : 255 - (int)dist(x, y, XG, YG);
            colorWheel[y * constants::WINDOW_WIDTH + x] = 0b11111111000000000000000000000000 + 0b10000000000000000 * redComp + 0b100000000 * greenComp + blueComp;
        }
    }
    int a;
    for (a = 0; a < 1080; a++) {
        int x = R/2*cos(a/180.0*PI/3.0) + R;
        int y = R/2*sin(a/180.0*PI/3.0) + R;
        palette[a] = colorWheel[y * constants::WINDOW_WIDTH + x];
    }
    delete[] colorWheel;
    //printf("a = %d\n", a);
}
