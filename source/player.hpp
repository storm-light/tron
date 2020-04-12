#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include <math.h>
#include <time.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "common.hpp"
#include "functions.hpp"

class Player
{
private:

    unsigned int lastTime, currentTime;

    int winW, winH;

public:

    Player();
    ~Player();

    int update();
    void handleEvents();
    void render();
    void renderMap();

    int up, down, left, right, dir;
    int lastX, lastY;
    bool vert;
    float x, y;
    float dx, dy, v;
    SDL_Rect dest;

    void setNum(int p);
    void reset();
    
    SDL_Texture * tex;

    int player;
    int score;
    int boosts;
    int spedUp;
    int cycles;

    int start;
};

#endif
