#include "tilemap.h"
#include <stdio.h>

int main()
{
    printf("Hello World!\n");
    TileMap *map = createTileMap(50, 50);
    printTileMap(map);
    addTileFlag(map, 5, 5,  is_burning | is_solid | is_pit);
    addTileFlag(map, 5, 5,  is_burning | is_solid | is_pit);
    removeTileFlag(map, 5, 5, is_solid);
    removeTileFlag(map, 5, 5, is_solid);
    addTileFlag(map, 5, 5, is_solid);
    removeTileFlag(map, 5, 5, is_burning);
    printTileFlags(map, 5, 5);
    setTileTexture(map, 5, 6, 6);
    addTileFlag(map, 5, 6, is_burning);
    if(tileHasFlag(map, 5, 6, is_burning)) printf("OMG ITS BURNING!\n");
    printTileMap(map);
    deleteTileMap(map);

    return 0;
}
