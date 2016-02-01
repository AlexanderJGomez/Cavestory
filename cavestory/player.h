//
//  player.h
//  Cavestory
//
//  Created by Alex Gomez on 12/24/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#ifndef __Cavestory__player__
#define __Cavestory__player__

#include "animatedSprite.h"
#include "globals.h"
#include "slope.h"

class Graphics;

class Player : public AnimatedSprite {
public:
    Player();
    Player(Graphics &graphics, Vector2 spawnPoint);
    void draw(Graphics &graphics);
    void update(float elapsedTime);
    
    //moves left by -dx
    void moveLeft();
    //move right by dx
    void moveRight();
    //stops moving player
    void stopMoving();
    
    //look up
    void lookUp();
    //stop looking up
    void stopLookingUp();
    //look down
    void lookDown();
    ///stop looking down
    void stopLookingDown();
    
    //jumps
    void jump();
    
    void handleSlopeCollisions(std::vector<Slope> &slopes);

    virtual void animationDone(std::string currentAnimation);
    virtual void setupAnimations();
    
    const float getX() const;
    const float getY() const;
    
    void handleTileCollision(std::vector<Rectangle> &others);
    
    const inline int getMaxHealth() const {return this->_maxHealth;}
    const inline int getCurrentHealth() const {return this->_currentHealth;}
    
private:
    float _dx, _dy;
    
    Direction _facing;
    
    bool _grounded;
    
    bool _lookingUp;
    
    bool _lookingDown;
    
    int _maxHealth;
    int _currentHealth;
    
};




#endif /* defined(__Cavestory__player__) */
