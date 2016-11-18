//
//  main.cpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include <stdio.h>
#include "graphics.hpp"
#include "globals.hpp"
#include "pixels.hpp"

int main(int argc, const char *argv[]) {
    Graphics graphics;
    bool quit = false;
    SDL_Event eventHandler;
    Uint32 *pixels = new Uint32[constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT];
    initPixels(pixels);
    addAxes(pixels);
    GenerateSet(pixels);
    graphics.updateTexture(pixels);
    graphics.render();
    while (!quit) {
        SDL_WaitEvent(&eventHandler);
        switch(eventHandler.type) {
            case SDL_QUIT :
                quit = true;
                break;
        }
    }
    delete[] pixels;
    return 0;
}
