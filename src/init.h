#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//Other libraries
#ifdef _WIN32
    #include "SDL.h"
#else //#elif __linux__ 
    #include <SDL2/SDL.h>
#endif

#include "define.h"
#include "struct.h"
#include "timer.h"

void Init(Game *pGame);

#endif // INIT_H_INCLUDED