#include "../inc/SG/render.h"

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
    
    for (int i = 0; i < pGame->pUnivers->rect.h ; ++i)
    {
        for (int j = 0; j < pGame->pUnivers->rect.w; ++j)
        {
            for (int k = 0; k < MAX_PLANET; ++k)
            {
              if(pGame->pUnivers->Map[i][j][0] >= MIN_PLANET + '0' && pGame->pUnivers->Map[i][j][0] <= MAX_PLANET + '0')
                {
                    dst.x = j * dst.w;
                    dst.y = i * dst.h;
                    detect_color_system(pGame, pGame->pUnivers->Map[i][j][0]);
                    SDL_RenderFillRect(pGame->pRenderer, &dst);
                }
            }
        }
    }
}

void detect_color_system(Game *pGame, char c) // --> swich case, stupid !
{
    if (c == '0')
        SDL_SetRenderDrawColor(pGame->pRenderer,255,255,0,255);
    else if (c == '1')
        SDL_SetRenderDrawColor(pGame->pRenderer,225,225,0,255);
    else if (c == '2')
        SDL_SetRenderDrawColor(pGame->pRenderer,195,195,0,255);
    else if (c == '3')
        SDL_SetRenderDrawColor(pGame->pRenderer,165,165,0,255);
    else if (c == '4')
        SDL_SetRenderDrawColor(pGame->pRenderer,135,135,0,255);
    else if (c == '5')
        SDL_SetRenderDrawColor(pGame->pRenderer,105,105,0,255);
    else if (c == '6')
        SDL_SetRenderDrawColor(pGame->pRenderer,75,75,0,255);
    else if (c == '7')
        SDL_SetRenderDrawColor(pGame->pRenderer,35,35,0,255);
    else
        SDL_SetRenderDrawColor(pGame->pRenderer,0,0,255,255);
}

void init_RenderRect(SDL_Rect *rect)
{
    //position rect    
    rect->x = 0;
    rect->y = 0;

    // taille en pixel du rect
    rect->w = RECT_H;
    rect->h = RECT_W;
}