#include "../inc/SG/timer.h"

Uint32 Timer(Uint32 deltaTime) {
    Uint32 currentTick = SDL_GetTicks();
    static Uint32 lastTick = 0;

    if (lastTick == 0) {
        lastTick = currentTick;
        return 0;
    }

    deltaTime = currentTick - lastTick;
    lastTick = currentTick;

    return deltaTime;
}

int my_rand (void){
   static int tab[TABSIZERANDOM];
   static int first = 0;
   int index;
   int rn;

   if (first == 0){
      int i;

      srand (time (NULL));
      for (i = 0; i < TABSIZERANDOM; i++)
         tab[i] = rand();
      first = 1;
   }
   index = (int)(rand() / RAND_MAX * (TABSIZERANDOM - 1));
   rn = tab[index];
   tab[index] = rand();
   return (rn);
}

/*void InitRandSeed(char *seed){
    ;
}*/

int Random (int _iMin, int _iMax){
    return (_iMin + (my_rand () % (_iMax-_iMin+1)));
}

int boolRandom(void){
    return(Random(0,1));
}

char *randSystemName(void){
    return("Random Name");
}

char *randObjName(void){
    return("Random Name");
}