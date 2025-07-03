#ifndef DRAW_H
#define DRAW_H

#include "tilemap.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define TILE_WIDTH 16
#define TILE_HEIGHT 16
#define TILE_ROWS 3
#define TILES_PER_ROW 3
#define TILE_SCALE 4

int initDraw();
void quitDraw();
void drawSprite(unsigned int spriteIndex, unsigned int x, unsigned int y);
void drawTileMap(TileMap *map, unsigned int xOffset, unsigned int yOffset);
void clearScene();
void presentScene();

#endif
