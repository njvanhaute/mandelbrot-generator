//
//  main.cpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include <string.h>
#include <stdio.h>
#include "graphics.hpp"
#include "globals.hpp"

int main(int argc, const char *argv[]) {
    Graphics graphics;
    bool quit = false;
    SDL_Event eventHandler;
    Uint32 *pixels = new Uint32[constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT];
    memset(pixels, 255, constants::WINDOW_WIDTH * constants::WINDOW_HEIGHT * sizeof(Uint32));
    while (!quit) {
        graphics.updateTexture(pixels);
        SDL_WaitEvent(&eventHandler);
        switch(eventHandler.type) {
            case SDL_QUIT :
                quit = true;
                break;
        }
        graphics.render();
    }
    delete[] pixels;
    return 0;
}
