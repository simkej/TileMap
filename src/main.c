#include "tilemap.h"
#include "draw.h"
#include "input.h"
#include <SDL2/SDL_events.h>
#include <stdio.h>

extern int keyboard[MAX_KEYBOARD_KEYS];

int main()
{
    printf("Hello World!\n");
    TileMap *map = createTileMap(50, 50);
    initDraw();

    while(1)
    {
        clearScene();

        doInput();

        if(keyboard[SDL_QUIT]) break;

        presentScene();
    }
    quitDraw();
    deleteTileMap(map);

    return 0;
}
