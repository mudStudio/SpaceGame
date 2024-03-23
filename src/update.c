#include "../inc/SG/update.h"

void Update(Game *pGame, Uint32 deltaTime) {

	printf("delta time diff on system : %s\t%d\n",pGame->pUnivers->pSystemList->sysName, deltaTime);
/*
//display -> render
    printf("\n\t-- Univers Map --\n\n");fflush(stdout);
    
    for (int i = 0; i < pGame->pUnivers->rect.h; ++i){
        for (int j = 0; j < pGame->pUnivers->rect.w; ++j)
        {
            printf("%c", pGame->pUnivers->Map[i][j][0]);
            fflush(stdout);
        }
        printf("\n");
    }

    printf("\n\t-- All System Map --\n\n");fflush(stdout);

// display term --> [i][j][0]
    for (int i = 0; i < pGame->pUnivers->rect.h; ++i){
        for (int j = 0; j < pGame->pUnivers->rect.w; ++j)
            if (pGame->pUnivers->Map[i][j][0] != ' '){
                printf("%s\n", pGame->pUnivers->Map[i][j]);
            }
    }
*/
}