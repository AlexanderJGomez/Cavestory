//
//  graphics.h
//  agario attempt
//
//  Created by Alex Gomez on 12/22/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#ifndef __agario_attempt__graphics__
#define __agario_attempt__graphics__

#include <stdio.h>
#include <SDL2/SDL.h>//
#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();
    
    /*Loads an image into the _spriteSheets map if it doesn't already exist
     As a result an image will only ever be loaded once
     Returns image from map regardless of whether or not it was loaded
     */
    SDL_Surface* loadImage(const std::string &filePath);
    
    /*Blit surface and draw texture to certain part of screen
     */
    void blitSurface(SDL_Texture * source, SDL_Rect* sourceRectangle,
                     SDL_Rect* destinationRectangle);
    /*Renders everything to screen
     */
    void flip();
    
    /*Clears the screen
     */
    void clear();
    
    /* Return our renderer
     */
    SDL_Renderer* getRenderer() const;
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    std::map<std::string, SDL_Surface*> _spriteSheets;
};



#endif /* defined(__agario_attempt__graphics__) */
