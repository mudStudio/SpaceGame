#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED


//Other libraries
#ifdef _WIN32
    #include "SDL.h"
#else //#elif __linux__ 
    #include <SDL2/SDL.h>
#endif

#include "struct.h"

int Events(Game *pGame);


#endif // EVENTS_H_INCLUDED