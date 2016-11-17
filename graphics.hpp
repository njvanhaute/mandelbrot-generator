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
#include "globals.hpp"

class Graphics {
private:
    SDL_Texture *_texture;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
public:
    Graphics();
    ~Graphics();
    void updateTexture(Uint32 *pixels);
    void render();
};

#endif /* GRAPHICS_HPP */
