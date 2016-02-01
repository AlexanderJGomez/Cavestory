//
//  input.h
//  agario attempt
//
//  Created by Alex Gomez on 12/22/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#ifndef __agario_attempt__input__
#define __agario_attempt__input__

#include <stdio.h>
#include <map>
#include <SDL2/SDL.h>

class Input {
public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);
    
    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);
    
private:
    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;
    
    
};

#endif /* defined(__agario_attempt__input__) */
