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

void setTileTexture(TileMap *map, unsigned int col, unsigned int row, unsigned int spriteIndex)
{
    if(map != NULL && col < map->width && row < map->height)
    {
        map->tiles[row * map->width + col].spriteIndex = spriteIndex;
    }
}

void addTileFlag(TileMap *map, unsigned int col, unsigned int row, unsigned int flags)
{
    if(map != NULL && col < map->width && row < map->height)
    {
        map->tiles[row * map->width + col].flags |= flags;
    }
}

void removeTileFlag(TileMap *map, unsigned int col, unsigned int row, unsigned int flags)
{
    if(map != NULL && col < map->width && row < map->height)
    {
        map->tiles[row * map->width + col].flags &= ~flags;
    }
}

int tileHasFlag(TileMap *map, unsigned int col, unsigned int row, unsigned int flag)
{
    if(map != NULL && col < map->width && row < map->height)
    {
        if(map->tiles[row * map->width + col].flags & flag)
        {
            return 1;
        }
        return 0;
    }
    return -1;
}

void printTileFlags(TileMap *map, unsigned int col, unsigned int row)
{
    if(map != NULL && col < map->width && row < map->height)
    {
        if(map->tiles[row * map->width + col].flags & is_solid) printf("is_solid ");
        if(map->tiles[row * map->width + col].flags & is_burning) printf("is_burning ");
        if(map->tiles[row * map->width + col].flags & is_pit) printf("is_pit ");
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


