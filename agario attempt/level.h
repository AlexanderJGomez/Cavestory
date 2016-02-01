//
//  level.h
//  Cavestory
//
//  Created by Alex Gomez on 12/27/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#ifndef __Cavestory__level__
#define __Cavestory__level__

#include "globals.h"
#include <string>
#include <vector>
#include "tile.h"
#include "rectangle.h"
#include "slope.h"
#include "animatedTile.h"

struct Tileset;

class Graphics;
struct SDL_Texture;
struct SDL_Rect;

class Level {
public:
    Level();
    Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics);
    ~Level();
    void update(int elapsedTime);
    void draw(Graphics &graphics);
    std::vector<Rectangle> checkTilecollisions(const Rectangle &other);
    std::vector<Slope> checkSlopeCollisions(const Rectangle &other);
    
    const Vector2 getPlayerSpawnPoint() const;
    
    
private:
    std::string _mapName;
    Vector2 _spawnPoint;
    
    Vector2 _size;
    Vector2 _tileSize;
    
    
    SDL_Texture* _backgroundTexture;
    
    std::vector<Tile> _tileList;
    std::vector<Tileset> _tilesets;
    std::vector<Rectangle> _collisionRects;
    std::vector<Slope> _slopes;
    
    std::vector<AnimatedTile> _animatedTileList;
    std::vector<AnimatedTileInfo> _animatedTileInfo;
    
    //loads a map
    void loadMap(std::string mapName, Graphics &graphics);
    
    Vector2 getTilesetPosition(Tileset tls, int gid, int tileWidth, int tileHeight);
    
    
};

//Tile set structure
struct Tileset {
    SDL_Texture* texture;
    int firstGid;
    
    Tileset() {
        this->firstGid = -1;
    }
    
    
    Tileset(SDL_Texture * texture, int firstGid) {
        this->texture = texture;
        this->firstGid = firstGid;
    }
    
    
    
};



#endif /* defined(__Cavestory__level__) */
