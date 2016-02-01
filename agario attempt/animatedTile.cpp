//
//  animatedTile.cpp
//  Cavestory
//
//  Created by Alex Gomez on 1/2/16.
//  Copyright (c) 2016 Alex Gomez. All rights reserved.
//

#include "animatedTile.h"
#include "graphics.h"


AnimatedTile::AnimatedTile(std::vector<Vector2> tilesetPosition, int duration, SDL_Texture* tileset, Vector2 size, Vector2 position) :
Tile(tileset, size, tilesetPosition.at(0), position),
_tilesetPositions(tilesetPosition),
_duration(duration),
_tileToDraw(0)
{}

void AnimatedTile::update(int elapsedTime) {
    //timer code
    if (this->_amountOfTime <= 0) {
        if (this->_tileToDraw == this->_tilesetPositions.size() - 1) {
            this->_tileToDraw = 0;
        }
        else {
            this->_tileToDraw++;
        }
        this->_amountOfTime = this->_duration;
    }
    else {
        this->_amountOfTime -= elapsedTime;
    }
}


void AnimatedTile::draw(Graphics &graphics) {
    SDL_Rect destRect = {this->_position.x, this->_position.y, 0, 0};
    destRect.w = this->_size.x * globals::SPRITE_SCALE;
    destRect.h = this->_size.y * globals::SPRITE_SCALE;
    SDL_Rect sourceRect = {this->_tilesetPositions.at(this->_tileToDraw).x, this->_tilesetPositions.at(this->_tileToDraw).y, this->_size.x, this->_size.y};
    
    graphics.blitSurface(this->_tileset, &sourceRect, &destRect);
    
    
}







