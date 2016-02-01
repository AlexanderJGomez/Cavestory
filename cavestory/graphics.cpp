//
//  graphics.cpp
//  agario attempt
//
//  Created by Alex Gomez on 12/22/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#include "graphics.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->_window);
    SDL_DestroyRenderer(this->_renderer);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
    if(this->_spriteSheets.count(filePath) == 0) {
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture,
                           SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle) {
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
    
}

void Graphics::flip() {
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return this->_renderer;
}