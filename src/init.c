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

    //Init Map
    pGame->UniversMap = calloc(1, sizeof(Dungeon));
    if (pGame->UniversMap == NULL){
        fprintf(stderr, "ERROR : Init Dungeon failed.");
        exit(EXIT_FAILURE);
    }

    pGame->UniversMap->rect.h = Random(H_MIN, H_MAX);
    pGame->UniversMap->rect.w = Random(W_MIN, W_MAX);

    if (boolRandom())
        ;
    else
    {
        int tmp = pGame->UniversMap->rect.h;
        pGame->UniversMap->rect.h = pGame->UniversMap->rect.w;
        pGame->UniversMap->rect.w = tmp;
    }

    //allocation
    pGame->UniversMap->Map = (char**)malloc(sizeof(char*) * pGame->UniversMap->rect.h);
    for (int i = 0; i < pGame->UniversMap->rect.h; ++i)
        pGame->UniversMap->Map[i] = (char*)malloc(sizeof(char) * pGame->UniversMap->rect.w);

    // insert -- make control of this shit
    for (int i = 0; i < pGame->UniversMap->rect.h; ++i)
    {
        for (int j = 0; j < pGame->UniversMap->rect.w; ++j)
        {
            if (Random(0,100) > 10)
                pGame->UniversMap->Map[i][j] = ' ';
            else
                pGame->UniversMap->Map[i][j] = Random(MIN_PLANET, MAX_PLANET) + '0';
        }
    }

    //displah -> render
    for (int i = 0; i < pGame->UniversMap->rect.h; ++i)
    {
        printf("%s\n", pGame->UniversMap->Map[i]);
    }
}
