#include "init.h"

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
    
    //Init Mouse & Keyboard
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

    //Init Dungeon & Map
    pGame->pDungeon = calloc(1, sizeof(Dungeon));
    if (pGame->pDungeon == NULL){
        fprintf(stderr, "ERROR : Init Dungeon failed.");
        exit(EXIT_FAILURE);
    }
    pGame->pDungeon->listMap = calloc(1, sizeof(Map) * 1);
    if (pGame->pDungeon == NULL){
        fprintf(stderr, "ERROR : Init Dungeon->listMap failed.");
        exit(EXIT_FAILURE);
    }
    pGame->pDungeon->pActualMap = calloc(1, sizeof(Map));
    if (pGame->pDungeon == NULL){
        fprintf(stderr, "ERROR : Init Dungeon->pActualMap failed.");
        exit(EXIT_FAILURE);
    }

    pGame->pDungeon->pActualMap->rect.h = Random(H_MIN, H_MAX);
    pGame->pDungeon->pActualMap->rect.w = Random(W_MIN, W_MAX);

    if (boolRandom())
        ;
    else
    {
        int tmp = pGame->pDungeon->pActualMap->rect.h;
        pGame->pDungeon->pActualMap->rect.h = pGame->pDungeon->pActualMap->rect.w;
        pGame->pDungeon->pActualMap->rect.w = tmp;
    }

    //allocation
    pGame->pDungeon->pActualMap->Map = (char**)malloc(sizeof(char*) * pGame->pDungeon->pActualMap->rect.h);
    for (int i = 0; i < pGame->pDungeon->pActualMap->rect.h; ++i)
        pGame->pDungeon->pActualMap->Map[i] = (char*)malloc(sizeof(char) * pGame->pDungeon->pActualMap->rect.w);

    // insert -- make control of this shit
    for (int i = 0; i < pGame->pDungeon->pActualMap->rect.h; ++i)
    {
        for (int j = 0; j < pGame->pDungeon->pActualMap->rect.w; ++j)
        {
            if (Random(0,100) > 10)
                pGame->pDungeon->pActualMap->Map[i][j] = ' ';
            else
                pGame->pDungeon->pActualMap->Map[i][j] = Random(MIN_PLANET, MAX_PLANET) + '0';
        }
    }

    //displah -> render
    for (int i = 0; i < pGame->pDungeon->pActualMap->rect.h; ++i)
    {
        printf("%s\n", pGame->pDungeon->pActualMap->Map[i]);
    }
}
