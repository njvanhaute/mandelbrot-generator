//
//  graphics.hpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "globals.hpp"

class Graphics {
private:
    SDL_Texture *_texture;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    SDL_Color *_colors;
    SDL_Palette *_palette;
public:
    Graphics();
    ~Graphics();
    SDL_Texture *getTexture();
    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();
    bool PrintScreen(std::string filepath);
    void updateTexture(Uint32 *pixels);
    void render();
    void initColors();
    void initPalette();
};

bool saveScreenshotBMP(std::string filepath, SDL_Window* SDLWindow, SDL_Renderer* SDLRenderer);

#endif /* GRAPHICS_HPP */
