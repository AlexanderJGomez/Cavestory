//
//  hud.h
//  Cavestory
//
//  Created by Alex Gomez on 1/4/16.
//  Copyright (c) 2016 Alex Gomez. All rights reserved.
//

#ifndef __Cavestory__hud__
#define __Cavestory__hud__

#include "player.h"
class Graphics;

class HUD {
public:
    HUD();
    HUD(Graphics &graphics, Player &player);
    void update(int elapsedTime);
    void draw(Graphics &graphics);
    
    
private:
    Player _player;
    
    //health sprites
    Sprite _healthBarSprite;
    Sprite _healthNumber1;
    Sprite _currentHealthBar;
    
    //exp sprites
    Sprite _lvWord;
    Sprite _lvNumber;
    Sprite _expBar;
    
};


#endif /* defined(__Cavestory__hud__) */
