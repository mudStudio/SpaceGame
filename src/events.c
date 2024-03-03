#include "events.h"

int Events(Game *pGame) {

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        //vérifications QUIT
        if (event.type == SDL_QUIT) return 0;

        //CLAVIER - TOUCHE ENFONCEE
        if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_UP:
                    pGame->pKeyboard->ArrowUp = 1;
                    break;
                case SDLK_LEFT:
                    pGame->pKeyboard->ArrowLeft = 1;
                    break;
                case SDLK_DOWN:
                    pGame->pKeyboard->ArrowDown = 1;
                    break;
                case SDLK_RIGHT:
                    pGame->pKeyboard->ArrowRight = 1;
                    break;
                case SDLK_z:
                    pGame->pKeyboard->Keyz = 1;
                    break;
                case SDLK_q:
                    pGame->pKeyboard->Keyq = 1;
                    break;
                case SDLK_s:
                    pGame->pKeyboard->Keys = 1;
                    break;
                case SDLK_d:
                    pGame->pKeyboard->Keyd = 1;
                    break;
                case SDLK_SPACE:
                    pGame->pKeyboard->KeySpace = 1;
                    break;
            }
        }
        //CLAVIER - TOUCHE RELACHEE
        else if (event.type == SDL_KEYUP) {
            switch(event.key.keysym.sym) {
                case SDLK_UP:
                    pGame->pKeyboard->ArrowUp = 0;
                    break;
                case SDLK_LEFT:
                    pGame->pKeyboard->ArrowLeft = 0;
                    break;
                case SDLK_DOWN:
                    pGame->pKeyboard->ArrowDown = 0;
                    break;
                case SDLK_RIGHT:
                    pGame->pKeyboard->ArrowRight = 0;
                    break;
                case SDLK_z:
                    pGame->pKeyboard->Keyz = 0;
                    break;
                case SDLK_q:
                    pGame->pKeyboard->Keyq = 0;
                    break;
                case SDLK_s:
                    pGame->pKeyboard->Keys = 0;
                    break;
                case SDLK_d:
                    pGame->pKeyboard->Keyd = 0;
                    break;
                case SDLK_SPACE:
                    pGame->pKeyboard->KeySpace = 0;
                    break;
            }
        }

        //SOURIS - MOUVEMENT
        if (event.type == SDL_MOUSEMOTION) {
            pGame->pMouse->MouseX=event.motion.x;
            pGame->pMouse->MouseY=event.motion.y;
        }
        //SOURIS - CLIC ENFONCE
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    pGame->pMouse->MouseLeftClic = 1;
                    break;
                case SDL_BUTTON_RIGHT:
                    pGame->pMouse->MouseRightClic = 1;
                    break;
            }
        }
        //SOURIS - CLIC RELACHE
        else if (event.type == SDL_MOUSEBUTTONUP) {
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    pGame->pMouse->MouseLeftClic = 0;
                    break;
                case SDL_BUTTON_RIGHT:
                    pGame->pMouse->MouseRightClic = 0;
                    break;
            }
        }

/*
        //Ecran redimensionné
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
            pScr->w = event.window.data1;
            pScr->h = event.window.data2;
            pScr->needResize = 1;
        }
*/

    }

    return 1;
}