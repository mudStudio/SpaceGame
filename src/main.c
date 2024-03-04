//Standard libraries
#include <stdlib.h>
#include <stdio.h>

///Other libraries
#ifdef _WIN32
    #include "SDL.h"
#else //#elif __linux__ 
    #include <SDL2/SDL.h> //make a path
#endif

//Local includes
#include "define.h"
#include "struct.h"
#include "timer.h"
#include "events.h"
#include "init.h"
#include "update.h"
#include "render.h"


int main(int argc, char** argv) {
    
    //Master Object creation & init
    Game *pGame = calloc(1, sizeof(Game));  
    if (pGame == NULL){
        fprintf(stderr, "ERROR : Game creation failed.");
        exit(EXIT_FAILURE);
    }

    Init(pGame);

    //Main variables
    Uint32 deltaTime = 0;
    Uint32 updateTimer = UPDATE_TIMER;
    Uint32 renderTimer = RENDER_TIMER;

    //Main Loop
    while (Events(pGame)) {
        deltaTime = Timer(deltaTime);

        updateTimer += deltaTime;
        if (updateTimer >= UPDATE_TIMER) {
            Update(pGame, updateTimer);
            updateTimer = 0;
        }
        
        renderTimer += deltaTime;
        if (renderTimer >= RENDER_TIMER) {
            Render(pGame);
            renderTimer = 0;
        }
        SDL_Delay(1);
    }

    //free
    //free à refaire avec un len propre
    for (int i = 0; i < pGame->UniversMap->rect.y; ++i)
    {
        if(pGame->UniversMap->Map[i] != NULL)
        free(pGame->UniversMap->Map[i]);
    }
    if(pGame->UniversMap->Map != NULL)
        free(pGame->UniversMap->Map);

    //End program
    SDL_DestroyRenderer(pGame->pRenderer);
    SDL_DestroyWindow(pGame->pWindow);
    SDL_Quit();

    //define l, L and malloc it
/*    int H = Random(H_MIN, H_MAX);
    int W = Random(W_MIN, W_MAX);

    if (boolRandom())
        ;
    else
    {
        int tmp = H;
        H = W;
        W = tmp;
    }

    char **Map = (char**)malloc(sizeof(char*) * H);
    for (int i = 0; i < H; ++i)
        Map[i] = (char*)malloc(sizeof(char) * W);

    // insert -- make control of this shit
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (Random(0,100) > 10)
                Map[i][j] = ' ';
            else
                Map[i][j] = Random(MIN_PLANET, MAX_PLANET) + '0';
        }
    }

    //display -> render
    for (int i = 0; i < H; ++i)
    {
        printf("%s\n", Map[i]);
    }

    //free à refaire avec un len propre
    for (int i = 0; i < H; ++i)
    {
        if(Map[i] != NULL)
        free(Map[i]);
    }
    if(Map != NULL)
        free(Map);
*/
    return EXIT_SUCCESS;
}