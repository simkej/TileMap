#ifndef TILEMAP_H
#define TILEMAP_H

#define is_solid    1 << 0
#define is_burning  1 << 1
#define is_pit      1 << 2

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
void setTileSprite(TileMap *map, unsigned int col, unsigned int row, unsigned int spriteIndex);
void addTileFlag(TileMap *map, unsigned int col, unsigned int row, unsigned int flags);
void removeTileFlag(TileMap *map, unsigned int col, unsigned int row, unsigned int flags);
int tileHasFlag(TileMap *map, unsigned int col, unsigned int row, unsigned int flag);
void printTileFlags(TileMap *map, unsigned int col, unsigned int row);

#endif
