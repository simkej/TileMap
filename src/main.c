#include "tilemap.h"
#include "draw.h"
#include "input.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

extern int keyboard[MAX_KEYBOARD_KEYS];

int main()
{
    printf("Hello World!\n");
    TileMap *map = createTileMap(30, 30);

    for(unsigned int row = 0; row < map->height; row++)
    {
        for(unsigned int col = 0; col < map->width; col++)
        {
            setTileSprite(map, col, row, 3);
        }
    }

    setTileSprite(map, 0, 0, 1);
    setTileSprite(map, 0, 2, 5);
    setTileSprite(map, 9, 9, 8);
    printTileMap(map);
    unsigned int x = 0;
    unsigned int y = 0;

    initDraw();

    while(1)
    {
        clearScene();

        doInput();

        if(keyboard[SDL_SCANCODE_DOWN]) y++;
        if(keyboard[SDL_SCANCODE_UP]) y--;
        if(keyboard[SDL_SCANCODE_LEFT]) x--;
        if(keyboard[SDL_SCANCODE_RIGHT]) x++;
        if(keyboard[SDL_SCANCODE_LCTRL]) 
        {
            for(unsigned int i = 0; i < map->width; i++)
            {
                setTileSprite(map, 0+i, 5, 7);
            }
        }

        drawTileMap(map, x, y);

        if(keyboard[SDL_QUIT]) break;

        presentScene();
        SDL_Delay(16);
    }
    quitDraw();
    deleteTileMap(map);

    return 0;
}
