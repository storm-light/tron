#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>
#include "common.hpp"

#define MAP_WIDTH (500)
#define MAP_HEIGHT (500)

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 505


SDL_Texture * loadTexture(SDL_Renderer * rend, std::string file);

bool init();

void titlescreen();

void generateTerrain();

void renderText(std::string message, std::string fontFile, SDL_Color color, int fontSize, int x, int y);
void alphaText(std::string message, std::string fontFile, SDL_Color color, int fontSize, int x, int y, int a);

void flickerIn(std::string msg);

void paint(int x, int y);

bool collided(int x, int y);
int blankMap();

#endif
