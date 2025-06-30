#ifndef TILEMAP_H
#define TILEMAP_H

typedef struct {
    unsigned int spriteIndex;
    unsigned int flags;
} Tile;

typedef struct {
    Tile *tiles;
    unsigned int width;
    unsigned int height;
} TileMap;

TileMap *createTileMap(unsigned int width, unsigned int height);
void deleteTileMap(TileMap *map);
void printTileMap(TileMap *map);

#endif
