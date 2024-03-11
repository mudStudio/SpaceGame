#include "init.h"

SDL_Color tmp_color = {0, 0, 0, 255};

void Init(Game *pGame) {
/* Init SDL */
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        fprintf(stderr, "ERROR : SDL initialization failed.");
        exit(EXIT_FAILURE);
    }
    
//Init Window
    pGame->pWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    if (pGame->pWindow == NULL){
        fprintf(stderr, "ERROR : Init Window failed.");
        exit(EXIT_FAILURE);
    }
    
//Init Renderer
    pGame->pRenderer = SDL_CreateRenderer(pGame->pWindow, -1 , 0);
    if (pGame->pRenderer == NULL){
        fprintf(stderr, "ERROR : Renderer failed.");
        exit(EXIT_FAILURE);
    }
    
/* Init Mouse & Keyboard */
    pGame->pMouse = calloc(1, sizeof(Mouse));
    if (pGame->pMouse == NULL){
        fprintf(stderr, "ERROR : Init Mouse failed.");
        exit(EXIT_FAILURE);
    }
    pGame->pKeyboard = calloc(1, sizeof(Keyboard));
    if (pGame->pKeyboard == NULL){
        fprintf(stderr, "ERROR : Init Keyboard failed.");
        exit(EXIT_FAILURE);
    }

/* Init UniversMap */
    pGame->pUniversMap = calloc(1, sizeof(UniversMap));
    if (pGame->pUniversMap == NULL){
        fprintf(stderr, "ERROR : Init UniversMap failed.");
        exit(EXIT_FAILURE);
    }
//fill UniversMap
    pGame->pUniversMap->rect.h = Random(H_MIN, H_MAX);
    pGame->pUniversMap->rect.w = Random(W_MIN, W_MAX);

    pGame->pUniversMap->Map = (char***)malloc(sizeof(char**) * pGame->pUniversMap->rect.h);
    for (int i = 0; i < pGame->pUniversMap->rect.h; ++i)
        pGame->pUniversMap->Map[i] = (char**)malloc(sizeof(char*) * pGame->pUniversMap->rect.w);

// insert -- make control of this shit
    for (int i = 0; i < pGame->pUniversMap->rect.h; ++i)
    {
        for (int j = 0; j < pGame->pUniversMap->rect.w; ++j)
        {
            int tmp_rand = Random(MIN_PLANET, MAX_PLANET);

            pGame->pUniversMap->Map[i][j] = (char*)malloc(sizeof(char) * (tmp_rand + 1));
            pGame->pUniversMap->Map[i][j][tmp_rand + 1] = '\0';
            
            if (Random(0,100) > 10) // -> define.h
            {
                pGame->pUniversMap->Map[i][j][0] = ' ';
                for (int k = 1; k <= tmp_rand; ++k)
                    pGame->pUniversMap->Map[i][j][k] = '\0';
            }
            else
            {
                char tmp_system_nb = Random(MIN_PLANET, tmp_rand) + '0'; // ?
                pGame->pUniversMap->Map[i][j][0] = tmp_system_nb;
                
                for (int k = 1; k <= tmp_rand; ++k)
                    pGame->pUniversMap->Map[i][j][k] = '*'; // --> make random system
            }
        }
    }



//display -> render
    printf("\n\t-- Univers Map --\n\n");fflush(stdout);
    
    for (int i = 0; i < pGame->pUniversMap->rect.h; ++i){
        for (int j = 0; j < pGame->pUniversMap->rect.w; ++j)
        {
            printf("%c", pGame->pUniversMap->Map[i][j][0]);
            fflush(stdout);
        }
        printf("\n");
    }

    printf("\n\t-- All System Map --\n\n");fflush(stdout);

    // display term --> [i][j][1]
    for (int i = 0; i < pGame->pUniversMap->rect.h; ++i){
        for (int j = 0; j < pGame->pUniversMap->rect.w; ++j)
            if (pGame->pUniversMap->Map[i][j][0] != ' ')
                printf("%s\n", pGame->pUniversMap->Map[i][j]);
    }

/* Init System */
    pGame->pUniversMap->pSystemList = calloc(1, sizeof(System));
    if (pGame->pUniversMap->pSystemList == NULL){
        fprintf(stderr, "ERROR : Init pSystemList failed.");
        exit(EXIT_FAILURE);
    }

    pGame->pUniversMap->pSystemList->sysColor = tmp_color;
    pGame->pUniversMap->pSystemList->sysName = randSystemName();
    pGame->pUniversMap->pSystemList->nbAsObject = 0;

    pGame->pUniversMap->pSystemList->prev = NULL;
    pGame->pUniversMap->pSystemList->next = NULL;

/* Init pListAsObject */
    pGame->pUniversMap->pSystemList->pListAsObject = calloc(1, sizeof(AsObject));
    if (pGame->pUniversMap->pSystemList->pListAsObject == NULL){
        fprintf(stderr, "ERROR : Init pListAsObject failed.");
        exit(EXIT_FAILURE);
    }
    pGame->pUniversMap->pSystemList->pListAsObject->asObjColor = tmp_color;
    pGame->pUniversMap->pSystemList->pListAsObject->asObjName = randSystemName();
    pGame->pUniversMap->pSystemList->pListAsObject->nbSite = 0;

    pGame->pUniversMap->pSystemList->pListAsObject->prev = NULL;
    pGame->pUniversMap->pSystemList->pListAsObject->next = NULL;

}