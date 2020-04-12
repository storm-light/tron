#include "player.hpp"

Player::Player()
{
    dir = 0; vert = 1;
    x = 0; y = 0; dx = 0; dy = 0; v = 200; dir = 0;
    
    tex = loadTexture(rend, "white.png");
    
    lastTime = 0;
    lastX = 0, lastY = 0;
    score = 0;
    boosts = 3;
    cycles = 0;
    spedUp = 0;

    start = 0;
}

void Player::reset()
{
    setNum(player);
}

Player::~Player()
{
    SDL_DestroyTexture(tex);
}

int Player::update()
{
    currentTime = SDL_GetTicks();
    if (currentTime > lastTime + 50 - spedUp && start)
    {
        if (spedUp > 0)
        {
            cycles++;
            if (cycles > 100)
            {
                spedUp = 0;
                cycles = 0;
            }
        }

        switch (dir)
        {
        case 0:
            y--;
            break;
        case 1:
            y++;
            break;
        case 2:
            x--;
            break;
        case 3:
            x++;
            break;
        }
        lastTime = currentTime;
    }
    
    // paint(x,y);
    if (lastX != x || lastY != y)
    {
        paint(lastX, lastY);
        lastX = x;
        lastY = y;
    }
    // collision with square tiles
    
    if (collided(x, y))
    {
        ree = 1;
        if (player == 1)
            return 2;
        else
            return 1;
    }
    
    // collision with world boundaries
    if (x < 0)
    {
        x = 0;
    }
    if (y < 0)
    {
        y = 0;
    }
    if ((1+x) * length > MAP_WIDTH)
    {
        x--;
    }
    if ((y+1) * length > MAP_HEIGHT)
    {
        y--;
    }

    // if (ree)
    // {
    //     // starting positions
    //     if (player == 1)
    //     {
    //         x = MAP_WIDTH / length / 4;
    //         y = MAP_HEIGHT / length / 2;
    //         dir = 3;
    //     }
    //     else if (player == 2)
    //     {
    //         x = 3 * MAP_WIDTH / length / 4;
    //         y = MAP_HEIGHT / length / 2;
    //         dir = 2;
    //     }

    //     // clears the map
    //     memset(world, 0, sizeof(world[0][0] * MAP_WIDTH * MAP_HEIGHT));
    //     delete map;
    //     generateTerrain();

    //     ree = 0;
    // }

    return 0;
}

void Player::render()
{
    // renderMap();

    dest.x = x * length; dest.y = y * length; dest.w = length; dest.h = length;
    SDL_RenderCopy(rend, tex, NULL, &dest);

    if (!start)
    {
        if (player == 2)
        {
            renderText("WASD", "TRON.ttf", white, 10, MAP_WIDTH / 4 * 3, MAP_HEIGHT / 2 - 40);
        }
        else
        {
            renderText("Arrow Keys", "TRON.ttf", white, 10, MAP_WIDTH / 4, MAP_HEIGHT / 2 - 40);
        }
    }
}

// void Player::renderMap()
// {
//     SDL_GetRendererOutputSize(rend, &winW, &winH); 
//     // std::cout << winW << winH << std::endl;

//     // winW = WINDOW_WIDTH;
//     // winH = WINDOW_HEIGHT;
//     cam->x = x + (length - winW) / 2;
//     cam->y = y + (length - winH) / 2;
//     cam->w = winW;
//     cam->h = winH;

//     if (cam->x < 0) cam->x = 0;
//     if (cam->y < 0) cam->y = 0;
//     if (cam->x > MAP_WIDTH - cam->w) cam->x = MAP_WIDTH - cam->w;
//     if (cam->y > MAP_HEIGHT - cam->h) cam->y = MAP_HEIGHT - cam->h;

//     SDL_RenderCopy(rend, map, cam, NULL);
// }

void Player::setNum(int p)
{
    player = p;

    boosts = 3;
    cycles = 0;
    spedUp = 0;
    if (p == 1)
    {
        x = MAP_WIDTH / length / 4;
        y = MAP_HEIGHT / length / 2;
        dir = 3;
        lastX = x, lastY = y;
    }
    else if (p == 2)
    {
        x = 3 * MAP_WIDTH / length / 4;
        y = MAP_HEIGHT / length / 2;
        dir = 2;
        lastX = x, lastY = y;
    }
}

void Player::handleEvents()
{
    if (player == 2)
    {
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_w:
                if (dir != 1)
                    dir = 0;
                break;

            case SDLK_s:
                if (dir != 0)
                    dir = 1;
                break;

            case SDLK_a:
                if (dir != 3)
                    dir = 2;
                break;

            case SDLK_d:
                if (dir != 2)
                    dir = 3;
                break;

            case SDLK_BACKQUOTE:
                spedUp = 30;
                break;
            }

        }
        
        // else if(event.type == SDL_KEYUP && event.key.repeat == 0)
        // {
        //     switch(event.key.keysym.sym)
        //     {
        //     case SDLK_w:
        //         up = 0;
        //         lastDir = 0;
        //         break;

        //     case SDLK_s:
        //         down = 0;
        //         lastDir = 0;
        //         break;

        //     case SDLK_a:
        //         left = 0;
        //         lastDir = 2;
        //         break;
                
        //     case SDLK_d:
        //         right = 0;
        //         lastDir = 3;
        //         break;
        //     }
        // }
    }

    else if (player == 1)
    {
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_UP:
                if (dir != 1)
                    dir = 0;
                break;

            case SDLK_DOWN:
                if (dir != 0)
                    dir = 1;
                break;

            case SDLK_LEFT:
                if (dir != 3)
                    dir = 2;
                break;

            case SDLK_RIGHT:
                if (dir != 2)
                    dir = 3;
                break;

            case SDLK_PERIOD:
                spedUp = 30;
                break;
            }

        }
        
        // else if(event.type == SDL_KEYUP && event.key.repeat == 0)
        // {
        //     switch(event.key.keysym.sym)
        //     {
        //     case SDLK_UP:
        //         up = 0;
        //         lastDir = 0;
        //         break;

        //     case SDLK_DOWN:
        //         down = 0;
        //         lastDir = 0;
        //         break;

        //     case SDLK_LEFT:
        //         left = 0;
        //         lastDir = 2;
        //         break;

        //     case SDLK_RIGHT:
        //         right = 0;
        //         lastDir = 3;
        //         break;
        //     }
        // }
    }
}
