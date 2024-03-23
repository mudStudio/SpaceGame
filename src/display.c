#include "../inc/SG/display.h"

void	displayUniversMapTerm(Univers *pUnivers)
{
	printf("\n\t-- Univers Map --\n\n");fflush(stdout);    
    for (int i = 0; i < pUnivers->rect.h; ++i){
        for (int j = 0; j < pUnivers->rect.w; ++j)
        {
            printf("%c", pUnivers->Map[i][j][0]);
            fflush(stdout);
        }
        printf("\n");
    }

    printf("\n\t-- All System Map --\n\n");fflush(stdout);
    for (int i = 0; i < pUnivers->rect.h; ++i){
        for (int j = 0; j < pUnivers->rect.w; ++j)
            if (pUnivers->Map[i][j][0] != ' '){
                printf("%s\n", pUnivers->Map[i][j]);
            }
    }
}