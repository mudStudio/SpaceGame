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
#include "../inc/SG/define.h"
#include "../inc/SG/struct.h"
#include "../inc/SG/timer.h"
#include "../inc/SG/events.h"
#include "../inc/SG/init.h"
#include "../inc/SG/update.h"
#include "../inc/SG/render.h"


int main(void) {
    
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
            //Update(pGame, updateTimer);
            updateTimer = 0;
        }
        
        renderTimer += deltaTime;
        if (renderTimer >= RENDER_TIMER) {
            Render(pGame);
            renderTimer = 0;
        }
        SDL_Delay(1);
    }

/*  //free
    //free à refaire avec un len propre
    for (int i = 0; i < pGame->pUnivers->rect.y; ++i)
    {
        if(pGame->pUnivers->Map[i] != NULL)
        free(pGame->pUnivers->Map[i]);
    }
    if(pGame->pUnivers->Map != NULL)
        free(pGame->pUnivers->Map);
*/
    //End program
    SDL_DestroyRenderer(pGame->pRenderer);
    SDL_DestroyWindow(pGame->pWindow);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}