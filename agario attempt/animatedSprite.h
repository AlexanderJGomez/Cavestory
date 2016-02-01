//
//  animatedSprite.h
//  Cavestory
//
//  Created by Alex Gomez on 12/23/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#ifndef __Cavestory__animatedSprite__
#define __Cavestory__animatedSprite__

#include <map>
#include <string>
#include <vector>
#include "globals.h"
#include "sprite.h"
class Graphics;
/*
 AnimatedSprite class
 */

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);
    /*
     Plays the animation if it is not already playing
     */
    void playAnimation(std::string animation, bool once = false);
    /*Updates the animated sprite
     */
    void update(int elapsedTime);
    
    //draws sprite to screen
    void draw(Graphics &graphics, int x, int y);
    
    
    
protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;
    
    //adds an animation to map of animations
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);
    
    //resets all animations associated
    void resetAnimations();
    
    //stops the animation
    void stopAnimation();
    
    //changes visibility of animatecd sprite
    void setVisibile(bool visible);
    
    //logic to occur when animation ends
    virtual void animationDone(std::string currentAnimation)= 0;
    
    /*
     A required func to set up all animations for a sprite
     */
    virtual void setupAnimations() = 0;
    
private:
    std::map<std::string, std::vector<SDL_Rect>> _animations;
    std::map<std::string, Vector2> _offsets;
    
    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};



#endif /* defined(__Cavestory__animatedSprite__) */
