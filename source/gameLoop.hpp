#ifndef _GAMELOOP_HPP_
#define _GAMELOOP_HPP_

#include <iostream>
#include <math.h>
#include <time.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include "common.hpp"
#include "player.hpp"

class Player;

class GameLoop
{
private:

    Player * p1;
    Player * p2;

    int winner;
    bool tie;
    int temp;

    SDL_Rect score;
    int s;

public:
    
    GameLoop();
    ~GameLoop();

    void handleEvents();
    void update();
    void render();
    void reset();
    void renderScoreboard();
};

#endif
