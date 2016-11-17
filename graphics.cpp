//
//  graphics.cpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include "graphics.hpp"

Graphics::Graphics() {
    SDL_Init(SDL_INIT_VIDEO);
    _window = SDL_CreateWindow("Mandelbrot Set", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    // Pixel format -> 8 bits for alpha, red, green, and blue (channels)
    // Each channel consists of one byte and can range from 0 - 255
    // Texture Access -> Store pixels in CPU memory and then copy them over to GPU.
    _texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);
}

Graphics::~Graphics() {
    SDL_DestroyTexture(_texture);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Graphics::updateTexture(Uint32 *pixels) {
    SDL_UpdateTexture(_texture, NULL, pixels, WINDOW_WIDTH * sizeof(Uint32));
}

void Graphics::render() {
    SDL_RenderClear(_renderer);
    SDL_RenderCopy(_renderer, _texture, NULL, NULL);
    SDL_RenderPresent(_renderer);
}
