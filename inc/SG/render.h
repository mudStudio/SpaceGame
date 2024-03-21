#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <stdio.h>

//Other libraries
#ifdef _WIN32
    #include "SDL.h"
#else //#elif __linux__ 
    #include <SDL2/SDL.h>
#endif

#include "struct.h"
#include "define.h"

void Render(Game *pGame);
void RenderGame(Game *pGame);
void init_RenderRect(SDL_Rect *rect);
void detect_color_system(Game *pGame, char c);

#endif // RENDER_H_INCLUDED