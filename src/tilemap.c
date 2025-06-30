#include "tilemap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static Tile getTile(TileMap *map, unsigned int col, unsigned int row);

TileMap *createTileMap(unsigned int width, unsigned int height)
{
    TileMap *map = malloc(sizeof(TileMap));
    if(map == NULL) return NULL;
    map->width = width;
    map->height = height;
    map->tiles = malloc(sizeof(Tile) * width * height);
    if(map->tiles == NULL)
    {
        free(map);
        return NULL;
    }
    memset(map->tiles, 0, sizeof(Tile) * width * height);

    return map;
}

void deleteTileMap(TileMap *map)
{
    if(map == NULL) return;
    free(map->tiles);
    free(map);
}

void printTileMap(TileMap *map)
{
    if(map == NULL) return;

    for(unsigned int row = 0; row < map->height; row++)
    {
        for(unsigned int col = 0; col < map->width; col++)
        {
            printf("%u ", getTile(map, col, row).spriteIndex);
        }
        printf("\n");
    }
}

static Tile getTile(TileMap *map, unsigned int col, unsigned int row)
{
    if(map != NULL && col < map->width && row < map->height)
    {
        return map->tiles[row * map->width + col];
    }
    return (Tile){.spriteIndex = 0, .flags = 0};
}
