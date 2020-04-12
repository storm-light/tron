#include "functions.hpp"

bool init()
{

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        return false;
    } 
    
    if (TTF_Init() != 0)
    {
        std::cout << "TTF Init Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // window with defined dimensions and in center of screen
    // win = SDL_CreateWindow("TRON",
    //                        SDL_WINDOWPOS_CENTERED,
    //                        SDL_WINDOWPOS_CENTERED,
    //                        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN);
    win = SDL_CreateWindow("TRON",
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    // fullscreen!
    // SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (!win)
    {
        std::cout << "Window Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // renderer sets up the graphics hardware
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE;
    rend = SDL_CreateRenderer(win, -1, render_flags);
   
    if (!rend)
    {
        std::cout << "Renderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return false;
    }

    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );

    // SDL_Rect rect;
    // SDL_GetDisplayBounds(0, &rect);
    // printf("w:%d, h:%d\n", rect.w, rect.h);
    
    return true;
}

SDL_Texture * loadTexture(SDL_Renderer * rend, std::string file)
{
    SDL_Texture * t = NULL;

    SDL_Surface * image = IMG_Load(file.c_str());

    if (image != NULL)
    {
        t = SDL_CreateTextureFromSurface(rend, image);

        SDL_FreeSurface(image);

        if (t == NULL)
        {
            std::cout << "Texture error: " << SDL_GetError() << std::endl;
        }
    }

    else
    {
        std::cout << "Surface Init error: " << SDL_GetError() << std::endl;
    }

    return t;
}

void generateTerrain()
{
    SDL_Rect r;
    r.w = length; r.h = length;

    int i;
    int xTiles = MAP_WIDTH / length; // 50
    int yTiles = MAP_HEIGHT / length;

    SDL_DestroyTexture(map);
    SDL_DestroyTexture(grid);
    map = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, MAP_WIDTH, MAP_HEIGHT);
    grid = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, MAP_WIDTH, MAP_HEIGHT);

    SDL_SetRenderTarget(rend, grid);
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
    SDL_RenderClear(rend);

    SDL_SetRenderTarget(rend, map);
    SDL_RenderClear(rend);

    SDL_SetRenderDrawColor(rend, 25, 25, 25, 25);
    
    for (i = 1; i < xTiles; i++)
    {
        // if (i % 16 == 1)
            SDL_RenderDrawLine(rend, i * length, 0, i * length, MAP_WIDTH);
    }

    for (i = 1; i < yTiles; i++)
    {
        // if (i % 16 == 1)
            SDL_RenderDrawLine(rend, 0, i * length, MAP_HEIGHT, i * length);
    }

    SDL_SetRenderTarget(rend, NULL);
}

void renderText(std::string message, std::string fontFile, SDL_Color color, int fontSize, int x, int y)
{
    /* opens font */
    TTF_Font * font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == 0)
    {
        std::cout << "TTF OPENfont: " << SDL_GetError() << std::endl;
    }

    /* render surface first with TTF_RenderText then create a texture for the surface */
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == 0)
    {
        TTF_CloseFont(font);
        std::cout << "TTF RenderText: " << SDL_GetError() << std::endl;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(rend, surf);
	if (texture == NULL){
        std::cout << "Create Texture : " << SDL_GetError() << std::endl;
	}

    SDL_Rect d;
    SDL_QueryTexture(texture, NULL, NULL, &d.w, &d.h);
    if (x == -1)
    {
        d.x = (WINDOW_WIDTH - d.w) / 2;
    }
    else
        d.x = x - d.w / 2;
    d.y = y - d.h / 2;
    SDL_RenderCopy(rend, texture, NULL, &d);

    /* frees stuff up */
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture); // fucking TwinkleBear Dev FUCK HIM
	TTF_CloseFont(font);
}

void alphaText(std::string message, std::string fontFile, SDL_Color color, int fontSize, int x, int y, int a)
{
    /* opens font */
    TTF_Font * font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == 0)
    {
        std::cout << "TTF OPENfont: " << SDL_GetError() << std::endl;
    }

    /* render surface first with TTF_RenderText then create a texture for the surface */
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == 0)
    {
        TTF_CloseFont(font);
        std::cout << "TTF RenderText: " << SDL_GetError() << std::endl;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(rend, surf);
	if (texture == NULL){
        std::cout << "Create Texture : " << SDL_GetError() << std::endl;
	}

    SDL_Rect d;
    SDL_QueryTexture(texture, NULL, NULL, &d.w, &d.h);
    if (x == -1)
    {
        d.x = (WINDOW_WIDTH - d.w) / 2;
    }
    else
        d.x = x - d.w / 2;
    d.y = y - d.h / 2;

    SDL_SetTextureAlphaMod(texture, a);
    SDL_RenderCopy(rend, texture, NULL, &d);

    /* frees stuff up */
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture); // fucking TwinkleBear Dev FUCK HIM
	TTF_CloseFont(font);
}

void flickerIn(std::string msg)
{
    int i;
    for (i = 5; i < 30; i+=5)   // flicker in
    {
        SDL_SetRenderDrawColor(rend, 0,0,0,255);
        SDL_RenderClear(rend);
        if (i % 2 == 0)
        {
            // SDL_SetRenderDrawColor(rend, 255,255,255,255);
            renderText(msg, "TRON.ttf", white, 30, MAP_WIDTH/2, MAP_HEIGHT/2);
            SDL_RenderPresent(rend);
        }
        SDL_RenderPresent(rend);
        SDL_Delay(1000/60 * 5);
    }
    // clear part of the display
    SDL_SetRenderDrawColor(rend, 0,0,0,255);
    SDL_RenderClear(rend);
    renderText(msg, "TRON.ttf", white, 30, MAP_WIDTH/2, MAP_HEIGHT/2);
    SDL_RenderPresent(rend);
    SDL_Delay(1500);
}

void paint(int x, int y)
{
    if (x >= 0 && y >= 0 && x * length <= MAP_WIDTH && y * length <= MAP_HEIGHT && world[x][y] == 0)
    {
        world[x][y] = 1;

        loc.x = x*length;
        loc.y = y*length;

        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        SDL_SetRenderTarget(rend, grid);
        SDL_RenderDrawRect(rend, &loc);
        SDL_SetRenderTarget(rend, NULL);

    }
}

bool collided(int x, int y)
{
    if (world[(x)][(y)] == 1)
        return 1;
    return 0;
}

int blankMap()
{
    int i,j;

    for (i = 0; i < MAP_WIDTH / length; i++)
    {
        for (j = 0; j < MAP_HEIGHT / length; j++)
        {
            if (world[i][j] == 1)
                return i;
        }
    }
    return -1;
}
// void updateMap()
// {
    
// }

void titlescreen()
{

    int quit = 0;
    int alpha = 0;
    int increasing = 1;
    // unsigned int lastTime, currentTime;
    while (1)
    {
        SDL_SetRenderDrawColor(rend, 0,0,0,255);
        SDL_RenderClear(rend);
        SDL_SetRenderDrawColor(rend, 255,255,255,255);
        renderText("TRON", "TRON.ttf", white, 70, MAP_WIDTH/2, MAP_HEIGHT/2 - 70);
        alphaText("Press Any Key", "TRON.ttf", white, 10, MAP_WIDTH/2, MAP_HEIGHT/2 + 50, alpha);

        // alpha mod of "press any key" texture
        if (increasing)
            alpha += 4;
        else
            alpha -= 4;

        if (0 > alpha || alpha > 255)
        {
            if (increasing)
            {
                increasing = 0;
                alpha = 255;
            }
            else
            {
                increasing = 1;
                alpha = 0;
            }
        }

        SDL_RenderPresent(rend);
        SDL_Delay(1000/60);
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
                quit = 1;
        }

        if (quit)
            break;
    }

}
