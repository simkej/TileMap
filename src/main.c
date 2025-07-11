#include "save.h"
#include "tilemap.h"
#include "draw.h"
#include "input.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

int main()
{
    printf("Hello World!\n");

    TileMap *map;

    if(fileExists("maps/test.level"))
    {
        map = loadTileMap("maps/test.level");
    } else {
        map = createTileMap(50, 50);
        for(unsigned int row = 0; row < map->height; row++)
        {
            for(unsigned int col = 0; col < map->width; col++)
            {
                setTileSprite(map, col, row, 3);
            }
        }
    }
    
    printTileMap(map);
    unsigned int x = 0;
    unsigned int y = 0;

    initDraw();

    while(1)
    {
        clearScene();

        doInput();

        if(getKeyDown(SDL_SCANCODE_DOWN)) y++;
        if(getKeyDown(SDL_SCANCODE_UP)) y--;
        if(getKeyDown(SDL_SCANCODE_LEFT)) x--;
        if(getKeyDown(SDL_SCANCODE_RIGHT)) x++;

        drawTileMap(map, x, y);

        if(getKeyDown(SDL_QUIT)) break;

        presentScene();
        SDL_Delay(16);
    }
    saveTileMap(map, "maps/test.level");
    quitDraw();
    deleteTileMap(map);

    return 0;
}
