#include "save.h"
#include "tilemap.h"
#include <stddef.h>
#include <stdio.h>

int saveTileMap(TileMap *map, char *filename)
{
    if(map == NULL || filename == NULL)
    {
        fprintf(stderr, "Couldn't save tilemap!\n");
        return 0;
    }

    FILE *save = fopen(filename, "wb");
    if(save == NULL)
    {
        fprintf(stderr, "Couldn't open file!\n");
        return 0;
    }
    
    // Write width and height.
    if(fwrite(&map->width, sizeof(unsigned int), 1, save) != 1 || fwrite(&map->height, sizeof(unsigned int), 1, save) != 1)
    {
        fprintf(stderr, "Couldn't write size to file!\n");
        fclose(save);
        return 0;
    }

    // Write tile array.
    size_t nTiles = (size_t)map->width * map->height;
    if(fwrite(map->tiles, sizeof(Tile), nTiles, save) != nTiles)
    {
        fprintf(stderr, "Couldn't write tiles to file!\n");
        fclose(save);
        return 0;
    }

    fclose(save);
    return 1;
}

TileMap *loadTileMap(char *filename)
{
    if(filename == NULL)
    {
        fprintf(stderr, "No filename to load!\n");
        return NULL;
    }

    FILE *save = fopen(filename, "rb");
    if(save == NULL)
    {
        fprintf(stderr, "Couldn't open file!\n");
        return NULL;
    }

    unsigned int width, height;

    // Read width and height.
    if(fread(&width, sizeof(unsigned int), 1, save) != 1 || fread(&height, sizeof(unsigned int), 1, save) != 1)
    {
        fprintf(stderr, "Couldn't read width and height!\n");
        fclose(save);
        return NULL;
    }

    // Create tilemap.
    TileMap *map = createTileMap(width, height);
    if(map == NULL)
    {
        fprintf(stderr, "Map is NULL!\n");
        fclose(save);
        return NULL;
    }

    // Read tile array.
    size_t nTiles = (size_t)map->width * map->height;
    if(fread(map->tiles, sizeof(Tile), nTiles, save) != nTiles)
    {
        fprintf(stderr, "Couldn't read tiles!\n");
        deleteTileMap(map);
        fclose(save);
        return NULL;
    }

    fclose(save);
    return map;
}

int fileExists(char *filename)
{
    if(filename == NULL) return 0;

    FILE *file = fopen(filename, "rb");
    if(file != NULL)
    {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}
