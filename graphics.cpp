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
    _window = SDL_CreateWindow("Mandelbrot Set", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT, 0);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_SOFTWARE);
    // Pixel format -> 8 bits for alpha, red, green, and blue (channels)
    // Each channel consists of one byte and can range from 0 - 255
    // Texture Access -> Store pixels in CPU memory and then copy them over to GPU.
    _texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT);
}

Graphics::~Graphics() {
    SDL_DestroyTexture(_texture);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

SDL_Renderer *Graphics::getRenderer() {
    return _renderer;
}

SDL_Window *Graphics::getWindow() {
    return _window;
}

SDL_Texture *Graphics::getTexture() {
    return _texture;
}

bool Graphics::PrintScreen(std::string filepath) {
    return saveScreenshotBMP(filepath, _window, _renderer);
}

void Graphics::updateTexture(Uint32 *pixels) {
    SDL_UpdateTexture(_texture, NULL, pixels, constants::WINDOW_WIDTH * sizeof(Uint32));
}

void Graphics::render() {
    SDL_RenderClear(_renderer);
    SDL_RenderCopy(_renderer, _texture, NULL, NULL);
    SDL_RenderPresent(_renderer);
}

bool saveScreenshotBMP(std::string filepath, SDL_Window* SDLWindow, SDL_Renderer* SDLRenderer) {
    SDL_Surface* saveSurface = NULL;
    SDL_Surface* infoSurface = NULL;
    infoSurface = SDL_GetWindowSurface(SDLWindow);
    if (infoSurface == NULL) {
        std::cerr << "Failed to create info surface from window in saveScreenshotBMP(string), SDL_GetError() - " << SDL_GetError() << "\n";
    } else {
        unsigned char * pixels = new (std::nothrow) unsigned char[infoSurface->w * infoSurface->h * infoSurface->format->BytesPerPixel];
        if (pixels == 0) {
            std::cerr << "Unable to allocate memory for screenshot pixel data buffer!\n";
            return false;
        } else {
            if (SDL_RenderReadPixels(SDLRenderer, &infoSurface->clip_rect, infoSurface->format->format, pixels, infoSurface->w * infoSurface->format->BytesPerPixel) != 0) {
                std::cerr << "Failed to read pixel data from SDL_Renderer object. SDL_GetError() - " << SDL_GetError() << "\n";
                pixels = NULL;
                return false;
            } else {
                saveSurface = SDL_CreateRGBSurfaceFrom(pixels, infoSurface->w, infoSurface->h, infoSurface->format->BitsPerPixel, infoSurface->w * infoSurface->format->BytesPerPixel, infoSurface->format->Rmask, infoSurface->format->Gmask, infoSurface->format->Bmask, infoSurface->format->Amask);
                if (saveSurface == NULL) {
                    std::cerr << "Couldn't create SDL_Surface from renderer pixel data. SDL_GetError() - " << SDL_GetError() << "\n";
                    return false;
                }
                SDL_SaveBMP(saveSurface, filepath.c_str());
                SDL_FreeSurface(saveSurface);
                saveSurface = NULL;
            }
            delete[] pixels;
        }
        SDL_FreeSurface(infoSurface);
        infoSurface = NULL;
    }
    return true;
}
