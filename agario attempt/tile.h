//
//  tile.h
//  Cavestory
//
//  Created by Alex Gomez on 12/28/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#ifndef __Cavestory__tile__
#define __Cavestory__tile__

#include "globals.h"


struct SDL_Texture;
class Graphics;

class Tile {
public:
    Tile();
    Tile(SDL_Texture* tileset, Vector2 size, Vector2 tilesetPosition, Vector2 position);
    void update(int elapsedTime);
    void draw(Graphics &graphics);
    
    
protected:
    SDL_Texture* _tileset;
    Vector2 _size;
    Vector2 _tilesetPosition;
    Vector2 _position;
    
};


#endif /* defined(__Cavestory__tile__) */
