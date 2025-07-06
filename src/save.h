#ifndef SAVE_H
#define SAVE_H

#include "tilemap.h"

int saveTileMap(TileMap *map, char *filename);
TileMap *loadTileMap(char *filename);
int fileExists(char *filename);

#endif
