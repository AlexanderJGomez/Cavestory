//
//  game.cpp
//  agario attempt
//
//  Created by Alex Gomez on 12/22/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#include "game.h"
#include "input.h"
#include "graphics.h"

namespace {
    const int FPS=50;
    const int MAX_FRAME_TIME = 1000 / FPS;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game() {
    
}

void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;
    
    this->_level = Level("Map1", Vector2(100, 100), graphics);
    this->_player = Player(graphics, this->_level.getPlayerSpawnPoint());
    this->_hud = HUD(graphics, this->_player);
    
    int LAST_UPDATE_TIME = SDL_GetTicks();
    while(true) {
        input.beginNewFrame();
        
        if(SDL_PollEvent(&event)) {
            if(event.type == SDL_KEYDOWN) {
                if(event.key.repeat == 0) {
                    input.keyDownEvent(event);
                }
            }
            else if(event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            }
            else if(event.type == SDL_QUIT) {
                return;
            }
        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
            return;
        }
        else if(input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
            this->_player.moveLeft();
        }
        else if(input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
            this->_player.moveRight();
        }
        
        if (input.isKeyHeld(SDL_SCANCODE_UP)) {
            this->_player.lookUp();
        }
        else if(input.isKeyHeld(SDL_SCANCODE_DOWN)) {
            this->_player.lookDown();
        }
        
        if (input.wasKeyReleased(SDL_SCANCODE_UP)) {
            this->_player.stopLookingUp();
        }
        
        if (input.wasKeyReleased(SDL_SCANCODE_DOWN)) {
            this->_player.stopLookingDown();
        }
        
        if(!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
            this->_player.stopMoving();
        }
        
        
        if (input.wasKeyPressed(SDL_SCANCODE_Z) == true) {
            this->_player.jump();
        }
        
        
        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;
        
        this->draw(graphics);
        
    }
    
}

void Game::draw(Graphics &graphics) {
    graphics.clear();
    
    this->_level.draw(graphics);
    
    this->_player.draw(graphics);
    this->_hud.draw(graphics);
    
    graphics.flip();
}

void Game::update(float elapsedTime) {
    this->_player.update(elapsedTime);
    this->_level.update(elapsedTime);
    this->_hud.update(elapsedTime);
    
    //check collisions
    std::vector<Rectangle> others;
    if ((others = this->_level.checkTilecollisions(this->_player.getBoundingBox())).size() > 0) {
        //player collided with a tile
        this->_player.handleTileCollision(others);
    }
    
    std::vector<Slope> otherSlopes;
    if((otherSlopes = this->_level.checkSlopeCollisions(this->_player.getBoundingBox())).size() > 0) {
        this->_player.handleSlopeCollisions(otherSlopes);
    }


}
