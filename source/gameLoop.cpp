#include "gameLoop.hpp"

GameLoop::GameLoop()
{
    p1 = new Player();  
    p1->setNum(1);
    p2 = new Player();  
    p2->setNum(2);

    winner = 0;
    tie = 0;
    temp = 0;

    score.h = WINDOW_HEIGHT - MAP_HEIGHT; score.y = 0;

    // printf("%d %d\n", p1->player, p2->player);

    // clears the map
    memset(world, 0, sizeof(world));

    generateTerrain();
    SDL_SetTextureBlendMode(grid, SDL_BLENDMODE_BLEND);
}

void GameLoop::reset()
{
    winner = 0;
    tie = 0;
    temp = 0;

    // clears the map
    memset(world, 0, sizeof(world));

    // SDL_DestroyTexture(map);
    // SDL_DestroyTexture(grid);
    generateTerrain();
    SDL_SetTextureBlendMode(grid, SDL_BLENDMODE_BLEND);

    p1->reset();
    p2->reset();
}

GameLoop::~GameLoop()
{
    p1->~Player();
    p2->~Player();

    SDL_DestroyTexture(map);
    SDL_DestroyTexture(grid);
}

void GameLoop::update()
{
    // determines winner or tie
    tie = 0;
    temp = p2->update();        // 0 or 1
    winner = p1->update();      // either 0 or 2 
    if (winner == 2 && temp == 1)
        tie = 1;
    else if (winner == 0)
    {
        winner = temp;
        tie = 0;
    }

    if (p1->x == p2->x && p1->y == p2->y)
    {
        printf("head on head\n");
        tie = 1;
        ree = 1;
    }

}

void GameLoop::render()
{
    vp.w = MAP_WIDTH; vp.h = MAP_HEIGHT; vp.x = 0; vp.y = WINDOW_HEIGHT - MAP_HEIGHT; 
    SDL_RenderSetViewport(rend, &vp);

    SDL_RenderClear(rend);

    SDL_RenderCopy(rend, map, NULL, NULL); // map rendered
    SDL_RenderCopy(rend, grid, NULL, NULL); // grid rendered
    // border of map
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    vp.y = 0;
    SDL_RenderDrawRect(rend, &vp);
    // render players
    p1->render();
    p2->render();

    if (!tie && winner == 2)
    {
        renderText("Player 2 wins!", "TRON.ttf", white, 30, MAP_WIDTH/2, MAP_HEIGHT/2);
        p2->score++;
        renderScoreboard();
        SDL_RenderPresent(rend);
        SDL_Delay(1000);
        // flickerIn("SCORE: " + std::to_string(p1->score) + "-" + std::to_string(p2->score));
    }
    else if (!tie && winner == 1)
    {
        renderText("Player 1 wins!", "TRON.ttf", white, 30, MAP_WIDTH/2, MAP_HEIGHT/2);
        p1->score++;
        renderScoreboard();
        SDL_RenderPresent(rend);
        SDL_Delay(1000);
        // flickerIn("SCORE: " + std::to_string(p1->score) + "-" + std::to_string(p2->score));
    }
    else if (tie)
    {
        renderText("Tie!", "TRON.ttf", white, 30, MAP_WIDTH/2, MAP_HEIGHT/2);
        renderScoreboard();
        SDL_RenderPresent(rend);
        SDL_Delay(1000);
        printf("tie?");
        // flickerIn("SCORE: " + std::to_string(p1->score) + "-" + std::to_string(p2->score));
    }

    renderScoreboard();

    s = p1->score - p2->score;
    if (s < -4)
    {
        renderText("Winner: Player 2!!!", "TRON.ttf", white, 30, MAP_WIDTH/2, MAP_HEIGHT/2);
        SDL_RenderPresent(rend);
        requestExit = 1;
        SDL_Delay(3000);
    }
    else if (s > 4)
    {
        renderText("Winner: Player 1!!!", "TRON.ttf", white, 30, MAP_WIDTH/2, MAP_HEIGHT/2);
        SDL_RenderPresent(rend);
        requestExit = 1;
        SDL_Delay(3000);
    }

    SDL_RenderPresent(rend);

    if (!p1->start)
    {
        SDL_Delay(3000);
        p1->start = 1;
        p2->start = 1;
    }
    SDL_Delay(1000/60);
}

void GameLoop::handleEvents()
{
    while (SDL_PollEvent(&event))
    {
        p1->handleEvents();
        p2->handleEvents();

        if (event.type == SDL_QUIT)
        {
            requestExit = 1;
        }
    }
}

void GameLoop::renderScoreboard()
{
    vp.w = MAP_WIDTH; vp.h = WINDOW_HEIGHT - MAP_HEIGHT; vp.x = 0; vp.y = 0; 
    SDL_RenderSetViewport(rend, &vp);
    // score.h and score.y are set in constructor
    s = p1->score - p2->score;

    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    score.x = 0; score.w = MAP_WIDTH;
    SDL_RenderFillRect(rend, &score);

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    if (s > 0)
    {
        score.x = MAP_WIDTH / 2;
        score.w = 50 * s;
        SDL_RenderFillRect(rend, &score);
    }
    else if (s < 0)
    {
        score.w = -50 * s;
        score.x = MAP_WIDTH / 2 - score.w;
        SDL_RenderFillRect(rend, &score);
    }

}
