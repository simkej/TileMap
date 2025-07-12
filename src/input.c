#include "input.h"
#include "draw.h"
#include <SDL2/SDL_events.h>


static int keyboard[SDL_NUM_SCANCODES];
static int running;
static int mouseX;
static int mouseY;
static unsigned int mouseButton;
static void doKeyUp(SDL_KeyboardEvent *event);
static void doKeyDown(SDL_KeyboardEvent *event);


void initInput()
{
    running = 1;
    mouseX = 0;
    mouseY = 0;
    mouseButton = 0;
}

void doInput()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                running = 0;
                break;

            case SDL_KEYDOWN:
                doKeyDown(&event.key);
                break;

            case SDL_KEYUP:
                doKeyUp(&event.key);
                break;

            case SDL_MOUSEMOTION:
                mouseX = event.motion.x;
                mouseY = event.motion.y;
                break;

            case SDL_MOUSEBUTTONDOWN:
                mouseButton |= SDL_BUTTON(event.button.button);
                break;

            case SDL_MOUSEBUTTONUP:
                mouseButton &= ~SDL_BUTTON(event.button.button);
                break;

            default:
                break;
        }
    }
}


static void doKeyDown(SDL_KeyboardEvent *event)
{
    if(event->repeat == 0 && event->keysym.scancode < SDL_NUM_SCANCODES)
    {
        keyboard[event->keysym.scancode] = 1;
    }
}

static void doKeyUp(SDL_KeyboardEvent *event)
{
    if(event->repeat == 0 && event->keysym.scancode < SDL_NUM_SCANCODES)
    {
        keyboard[event->keysym.scancode] = 0;
    }
}

int getKeyDown(SDL_Scancode keyCode)
{
    if(keyCode >= 0 && keyCode < SDL_NUM_SCANCODES)
    {
        return keyboard[keyCode];
    }
    return 0;
}

int shouldRun()
{
    return running;
}

int getMouseX()
{
    return mouseX;
}

int getMouseY()
{
    return mouseY;
}

int getMouseTileMapX()
{
    return mouseX / (TILE_WIDTH * TILE_SCALE);
}

int getMouseTileMapY()
{
    return mouseY / (TILE_HEIGHT * TILE_SCALE);
}

int getMouseButton(int button)
{
    return (mouseButton & SDL_BUTTON(button)) != 0;
}
