//
//  main.cpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include <SDL2/SDL.h>
#include <iostream>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 640;

int main(int argc, const char *argv[]) {
    bool quit = false;
    SDL_Event eventHandler;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window *window = SDL_CreateWindow("Mandelbrot Set", SDL_WINDOWPOS_UNDEFINED,        SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    // Pixel format -> 8 bits for alpha, red, green, and blue (channels)
    // Each channel consists of one byte and can range from 0 - 255
    // Texture Access -> Store pixels in CPU memory and then copy them over to GPU.
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);
    Uint32 *pixels = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];
    memset(pixels, 255, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));
    while (!quit) {
        SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));
        SDL_WaitEvent(&eventHandler);
        switch(eventHandler.type) {
            case SDL_QUIT :
                quit = true;
                break;
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    delete[] pixels;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
