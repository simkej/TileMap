/* 

    TODO: Remake input system.

*/

#include "input.h"
#include <SDL2/SDL_events.h>

int keyboard[MAX_KEYBOARD_KEYS];
static void doKeyUp(SDL_KeyboardEvent *event);
static void doKeyDown(SDL_KeyboardEvent *event);

void doInput()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                keyboard[SDL_QUIT] = 1;
                break;

            case SDL_KEYDOWN:
                doKeyDown(&event.key);
                break;

            case SDL_KEYUP:
                doKeyUp(&event.key);
                break;

            default:
                break;
        }
    }
}


static void doKeyDown(SDL_KeyboardEvent *event)
{
    if(event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
    {
        keyboard[event->keysym.scancode] = 1;
    }
}

static void doKeyUp(SDL_KeyboardEvent *event)
{
    if(event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
    {
        keyboard[event->keysym.scancode] = 0;
    }
}
