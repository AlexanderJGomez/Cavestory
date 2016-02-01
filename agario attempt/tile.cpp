//
//  tile.cpp
//  Cavestory
//
//  Created by Alex Gomez on 12/28/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#include "tile.h"
#include "graphics.h"
#include <SDL2/SDL.h>

Tile::Tile() {}

Tile::Tile(SDL_Texture* tileset, Vector2 size, Vector2 tilesetPosition, Vector2 position) :
_tileset(tileset),
_size(size),
_tilesetPosition(tilesetPosition),
_position(Vector2(position.x * globals::SPRITE_SCALE, position.y * globals::SPRITE_SCALE)) {
    
}

void Tile::update(int elapsedTime) {}

void Tile::draw(Graphics &graphics) {
    SDL_Rect destRect;
    destRect.x = this->_position.x;
    destRect.y = this->_position.y;
    destRect.w = this->_size.x * globals::SPRITE_SCALE;
    destRect.h = this->_size.y * globals::SPRITE_SCALE;
    
    SDL_Rect sourceRect = {this->_tilesetPosition.x, this->_tilesetPosition.y,
        this->_size.x, this->_size.y};
    
    graphics.blitSurface(this->_tileset, &sourceRect, &destRect);
}