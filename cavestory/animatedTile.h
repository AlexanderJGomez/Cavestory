//
//  animatedTile.h
//  Cavestory
//
//  Created by Alex Gomez on 1/2/16.
//  Copyright (c) 2016 Alex Gomez. All rights reserved.
//

#ifndef __Cavestory__animatedTile__
#define __Cavestory__animatedTile__

#include <vector>
#include "tile.h"
class AnimatedTile : public Tile {
public:
    AnimatedTile(std::vector<Vector2> tilesetPositions, int duration, SDL_Texture* tileSet, Vector2 size, Vector2 position);
    void update(int elapsedTime);
    void draw(Graphics &graphics);
protected:
    int _amountOfTime = 0;
    bool _notDone = false;
private:
    std::vector<Vector2> _tilesetPositions;
    int _tileToDraw;
    int _duration;
    
};

struct AnimatedTileInfo {
public:
    int TilesetsFirstGids;
    int StartTileId;
    std::vector<int> TileIds;
    int Duration;
};




#endif /* defined(__Cavestory__animatedTile__) */
