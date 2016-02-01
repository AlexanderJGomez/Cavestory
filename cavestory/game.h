//
//  game.h
//  agario attempt
//
//  Created by Alex Gomez on 12/22/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#ifndef __agario_attempt__game__
#define __agario_attempt__game__

#include <stdio.h>
#include "player.h"
#include "level.h"
#include "hud.h"

class Graphics;

class Game {
public:
    Game();
    ~Game();
    
private:
    void gameLoop();
    void draw(Graphics & graphics);
    void update(float elapsedTime);
    Player _player;
    Level _level;
    HUD _hud;
};

#endif /* defined(__agario_attempt__game__) */
