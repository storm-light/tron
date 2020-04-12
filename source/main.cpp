#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "common.hpp"
#include "functions.hpp"
#include "gameLoop.hpp"

int length = 5;
int halflen = length / 2;
int requestExit = 0;
int ree = 0;

SDL_Event event;

SDL_Renderer * rend;
SDL_Window * win;
SDL_Texture * map;
SDL_Texture * grid;
int world[500][500];
SDL_Rect loc;
SDL_Color white;
SDL_Texture * tex;

SDL_RendererFlip flip = (SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
SDL_Rect * cam = new SDL_Rect();

SDL_Rect vp;

int main()
{
    if (!init())
    {
        return 1;
    }

    loc.w = length;
    loc.h = length;
    white.r = 255; white.g = 255; white.b = 255; white.a = 255;

    vp.w = MAP_WIDTH; vp.h = MAP_HEIGHT; vp.x = 0; vp.y = WINDOW_HEIGHT - MAP_HEIGHT; 

    titlescreen();
    
    GameLoop * gaim = new GameLoop();

    while (requestExit != 1)
    {
        // handle events
        gaim->handleEvents();
        // update
        gaim->update();
        // render
        gaim->render();

        if (ree)
        {
            gaim->reset();
            ree = 0;
            // printf("%d\n", blankMap());
        }
    }

    // clean up
    gaim->~GameLoop();

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    
    TTF_Quit();
    SDL_Quit();

    return 0;
}
