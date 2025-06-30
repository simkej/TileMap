#include "tilemap.h"
#include <stdio.h>

int main()
{
    printf("Hello World!\n");
    TileMap *map = createTileMap(50, 50);
    printTileMap(map);
    deleteTileMap(map);

    return 0;
}
