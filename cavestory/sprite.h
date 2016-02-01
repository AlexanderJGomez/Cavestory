//
//  sprite.h
//  agario attempt
//
//  Created by Alex Gomez on 12/23/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#ifndef __agario_attempt__sprite__
#define __agario_attempt__sprite__

#include <string>
#include <SDL2/SDL.h>
#include "rectangle.h"
#include "globals.h"
class Graphics;
//Sprite class, holds all information for individual sprites
class Sprite {
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filePath, int sourceX,
           int sourceY, int width, int height, float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, int x, int y);
    
    const Rectangle getBoundingBox() const;
    
    const sides::Side getCollisionSide(Rectangle & other) const;
    
    const inline float getX() const {
        return this->_x;
    }
    
    const inline float getY() const {
        return this->_y;
    }
    
    void setSourceRectX(int value);
    void setSourceRectY(int value);
    void setSourceRectW(int value);
    void setSourceRectH(int value);
    
protected:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;
    
    Rectangle _boundingBox;
    
    
    float _x, _y;
    
private:
    
};


#endif /* defined(__agario_attempt__sprite__) */
