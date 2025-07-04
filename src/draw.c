#include "draw.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *spriteSheet;

static SDL_Texture *loadTexture(char *filename);

int initDraw()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Couldn't init SDL: %s\n", SDL_GetError());
        return 0; 
    }
    fprintf(stdout, "SDL initialized...\n");

    window = SDL_CreateWindow("Tile Map", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if(!window)
    {
        fprintf(stderr, "Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        SDL_Quit();
        return 0;
    }
    fprintf(stdout, "Window created...\n");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!renderer)
    {
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }
    fprintf(stdout, "Renderer created...\n");

    if(!IMG_Init(IMG_INIT_PNG))
    {
        fprintf(stderr, "Failed to init IMG: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }
    fprintf(stdout, "IMG initialized...\n");

    // Could be NULL!
    spriteSheet = loadTexture("gfx/spriteSheet.png");
    

    return 1;
}

void quitDraw()
{
    SDL_DestroyTexture(spriteSheet);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void drawSprite(unsigned int spriteIndex, unsigned int x, unsigned int y)
{
    if(spriteIndex >= (TILES_PER_ROW * TILE_ROWS) || spriteSheet == NULL)
    {
        fprintf(stderr, "Failed to draw sprite!\n");
        return;
    }

    SDL_Rect source;
    source.x = (spriteIndex % TILES_PER_ROW) * TILE_WIDTH;
    source.y = (spriteIndex / TILES_PER_ROW) * TILE_HEIGHT;
    source.w = TILE_WIDTH;
    source.h = TILE_HEIGHT;

    SDL_Rect destination;
    destination.x = x;
    destination.y = y;
    destination.w = TILE_WIDTH * TILE_SCALE;
    destination.h = TILE_HEIGHT * TILE_SCALE;

    SDL_RenderCopy(renderer, spriteSheet, &source, &destination);
}

void drawTileMap(TileMap *map, unsigned int xOffset, unsigned int yOffset)
{
    if(map == NULL) return;

    for(unsigned int row = 0; row < map->height; row++)
    {
        for(unsigned int col = 0; col < map->width; col++)
        {
            drawSprite(map->tiles[row * map->width + col].spriteIndex, 
                       (col * TILE_WIDTH * TILE_SCALE) - (xOffset * TILE_WIDTH * TILE_SCALE), 
                       (row * TILE_HEIGHT * TILE_SCALE) - (yOffset * TILE_HEIGHT * TILE_SCALE));
        }
    }
}

void clearScene()
{
    SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
    SDL_RenderClear(renderer);
}

void presentScene()
{
    SDL_RenderPresent(renderer);
}

static SDL_Texture *loadTexture(char *filename)
{
    SDL_Texture *texture;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    texture = IMG_LoadTexture(renderer, filename);

    if(texture == NULL)
    {
        fprintf(stderr, "Failed to load texture %s: %s\n", filename, SDL_GetError());
    }

    return texture;
}
