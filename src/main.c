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
    unsigned int pallette = 0;

    int rightPressed = 0;

    initDraw();
    initInput();

    while(1)
    {
        clearScene();

        doInput();

        if(!getMouseButton(SDL_BUTTON_RIGHT)) rightPressed = 0;

        if(getKeyDown(SDL_SCANCODE_W)) y--;
        if(getKeyDown(SDL_SCANCODE_S)) y++;
        if(getKeyDown(SDL_SCANCODE_A)) x--;
        if(getKeyDown(SDL_SCANCODE_D)) x++;

        if(getMouseButton(SDL_BUTTON_LEFT)) setTileSprite(map, getMouseTileMapX() + x, getMouseTileMapY() + y, pallette);

        if(getMouseButton(SDL_BUTTON_RIGHT) && !rightPressed)
        {
            pallette++;
            if(pallette >= TILES_PER_ROW * TILE_ROWS) pallette = 0;
            printf("%d\n", pallette);
            rightPressed = 1;
        }


        drawTileMap(map, x, y);

        if(!shouldRun()) break;

        presentScene();
        SDL_Delay(16);
    }
    saveTileMap(map, "maps/test.level");
    quitDraw();
    deleteTileMap(map);

    return 0;
}
