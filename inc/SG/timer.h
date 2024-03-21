#ifndef TIMERS_H_INCLUDED
#define TIMERS_H_INCLUDED


//Other libraries
#ifdef _WIN32
    #include "SDL.h"
#else //#elif __linux__ 
    #include <SDL2/SDL.h>
#endif

#include <time.h>
#include "define.h"

Uint32 Timer(Uint32 deltaTime);

void InitRandSeed(char *seed);

int my_rand (void);
int Random (int _iMin, int _iMax);
int boolRandom(void);

char *randSystemName(void);
char *randObjName(void);

#endif // TIMERS_H_INCLUDED