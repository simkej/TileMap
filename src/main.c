#include "tilemap.h"
#include <stdio.h>

int main()
{
    printf("Hello World!\n");
    TileMap *map = createTileMap(50, 50);
    for(unsigned int row = 0; row < map->height; row++)
    {
        for(unsigned int col = 0; col < map->width; col++)
        {
            setTileSprite(map, col, row, 5);
        }
    }
    addTileFlag(map, 5, 5, is_solid | is_burning);
    removeTileFlag(map, 5, 5, is_solid);
    if(tileHasFlag(map, 5, 5, is_burning)) printf("Its burning!\n");
    printTileFlags(map, 5, 5);
    printTileMap(map);
    deleteTileMap(map);

    return 0;
}
