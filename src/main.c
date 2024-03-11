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
    for (int i = 0; i < pGame->pUniversMap->rect.y; ++i)
    {
        if(pGame->pUniversMap->Map[i] != NULL)
        free(pGame->pUniversMap->Map[i]);
    }
    if(pGame->pUniversMap->Map != NULL)
        free(pGame->pUniversMap->Map);

    //End program
    SDL_DestroyRenderer(pGame->pRenderer);
    SDL_DestroyWindow(pGame->pWindow);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}