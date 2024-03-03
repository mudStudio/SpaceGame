#include "render.h"

void Render(Game *pGame) {
    SDL_SetRenderDrawColor(pGame->pRenderer,0,0,0,255);
    SDL_RenderClear(pGame->pRenderer);

    //RENDER
    RenderGame(pGame);

    SDL_RenderPresent(pGame->pRenderer);
}

void RenderGame(Game *pGame)
{
    SDL_Rect dst;

    init_RenderRect(&dst);
    // Color 
    
    for (int i = 0; i < pGame->pDungeon->pActualMap->rect.h ; ++i)
    {
        for (int j = 0; j < pGame->pDungeon->pActualMap->rect.w; ++j)
        {
          if(pGame->pDungeon->pActualMap->Map[i][j] >= MIN_PLANET + '0' && pGame->pDungeon->pActualMap->Map[i][j] <= MAX_PLANET + '0')
            {
                dst.x = j * dst.w;
                dst.y = i * dst.h;
                detect_color_system(pGame, pGame->pDungeon->pActualMap->Map[i][j]);
                SDL_RenderFillRect(pGame->pRenderer, &dst);
            }
        }
    }
}


void detect_color_system(Game *pGame, char c)
{
    if (c == '0')
        SDL_SetRenderDrawColor(pGame->pRenderer,255,0,0,255);
    else if (c == '1')
        SDL_SetRenderDrawColor(pGame->pRenderer,25,255,25,255);
    else if (c == '2')
        SDL_SetRenderDrawColor(pGame->pRenderer,50,255,50,255);
    else if (c == '3')
        SDL_SetRenderDrawColor(pGame->pRenderer,75,255,75,255);
    else if (c == '4')
        SDL_SetRenderDrawColor(pGame->pRenderer,100,255,100,255);
    else if (c == '5')
        SDL_SetRenderDrawColor(pGame->pRenderer,125,255,125,255);
    else if (c == '6')
        SDL_SetRenderDrawColor(pGame->pRenderer,150,255,150,255);
    else if (c == '7')
        SDL_SetRenderDrawColor(pGame->pRenderer,175,255,175,255);
    else
        SDL_SetRenderDrawColor(pGame->pRenderer,0,0,255,255);
}

void init_RenderRect(SDL_Rect *rect)
{
    //position rect    
    rect->x = 0;
    rect->y = 0;

    // taille en pixel du rect
    rect->w = 25; // --> define.h
    rect->h = 25;
}