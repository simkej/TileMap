#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL_scancode.h>

void initInput();
void doInput();
int shouldRun();
int getKeyDown(SDL_Scancode keyCode);
int getMouseX();
int getMouseY();
int getMouseTileMapX();
int getMouseTileMapY();
int getMouseButton(int button);


#endif
