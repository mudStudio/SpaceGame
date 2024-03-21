#include "../inc/SG/init.h"

SDL_Color tmp_color = {0, 0, 0, 255};
int total_planet = 0;
int total_satelite = 0;
int total_asteroid = 0;

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

/* INIT SEED */
//    InitRandSeed(seed)

/* Init Univers */
    pGame->pUnivers = calloc(1, sizeof(Univers));
    if (pGame->pUnivers == NULL){
        fprintf(stderr, "ERROR : Init Univers failed.");
        exit(EXIT_FAILURE);
    }
//fill Univers
    pGame->pUnivers->rect.h = Random(H_MIN, H_MAX);
    pGame->pUnivers->rect.w = Random(W_MIN, W_MAX);

    pGame->pUnivers->Map = (char***)malloc(sizeof(char**) * (pGame->pUnivers->rect.h + 1));
    for (int i = 0; i < pGame->pUnivers->rect.h; ++i)
        pGame->pUnivers->Map[i] = (char**)malloc(sizeof(char*) * (pGame->pUnivers->rect.w + 1));

// insert -- make control of this shit
    for (int i = 0; i < pGame->pUnivers->rect.h; ++i)
    {
        for (int j = 0; j < pGame->pUnivers->rect.w; ++j)
        {
            int tmp_rand = Random(MIN_PLANET, MAX_PLANET);

            pGame->pUnivers->Map[i][j] = (char*)malloc(sizeof(char) * (tmp_rand + 1));
            pGame->pUnivers->Map[i][j][tmp_rand + 1] = '\0';
            
            if (Random(0,100) > 10) // -> define.h
            {
                pGame->pUnivers->Map[i][j][0] = ' ';
                for (int k = 1; k <= tmp_rand; ++k)
                    pGame->pUnivers->Map[i][j][k] = '\0';
            }
            else
            {
                char tmp_system_nb = Random(MIN_PLANET, tmp_rand) + '0'; // ?
                pGame->pUnivers->Map[i][j][0] = tmp_system_nb;
                
                /** FILL SYSTEM WITH OBJECTS **/
                for (int k = 1; k <= tmp_rand; ++k)
                {
                    pGame->pUnivers->Map[i][j][k] = InitMapSystem();
                    if(pGame->pUnivers->Map[i][j][k] == 'P')
                        total_planet += 1;
                    else if(pGame->pUnivers->Map[i][j][k] == 'S')
                        total_satelite += 1;
                    else if(pGame->pUnivers->Map[i][j][k] == 'A')
                        total_asteroid += 1;
                }
            }
        }
    }


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

/* Init System */
    pGame->pUnivers->pSystemList = CreateSystem(NULL, NULL);

    int len = 1;

    System *tmp = pGame->pUnivers->pSystemList;

    for (int i = 0; i < pGame->pUnivers->rect.h; ++i){
        for (int j = 0; j < pGame->pUnivers->rect.w; ++j)
            if (pGame->pUnivers->Map[i][j][0] != ' ')
                {
                    len++;
                    pGame->pUnivers->pSystemList->next = CreateSystem(pGame->pUnivers->pSystemList, NULL);
                    pGame->pUnivers->pSystemList = pGame->pUnivers->pSystemList->next;
                }
    }
    pGame->pUnivers->pSystemList = tmp;

    printf("\nCreation of %d news systems with %d Planet(s), %d Satelites and %d Asteroïds.\n", \
        len, total_planet, total_satelite, total_asteroid);fflush(stdout);

/*    while(pGame->pUnivers->pSystemList != NULL)
    {
        printf("%s\n", pGame->pUnivers->pSystemList->sysName);
        pGame->pUnivers->pSystemList = pGame->pUnivers->pSystemList->next;
    }
    pGame->pUnivers->pSystemList = tmp;
*/
}

char    InitMapSystem(){
    int tmp_object = Random(0,2);
    
    if(tmp_object == 0)
        return 'A';
    if(tmp_object == 1)
        return 'S';
    if(tmp_object == 2)
        return 'P';
    else
        return '*';}

System *CreateSystem(System *prev, System *next)
{
    System *tmpNewSystem = calloc(1, sizeof(System));
    if (tmpNewSystem == NULL){
    fprintf(stderr, "ERROR : Create tmpNewSystemList failed.");
    exit(EXIT_FAILURE);
    }

    tmpNewSystem->sysColor = tmp_color;
    tmpNewSystem->sysName = randSystemName();
    tmpNewSystem->nbCelestObject = 1;
    tmpNewSystem->pListCelestObject = NULL; // Create Object

    tmpNewSystem->P = 0;
    tmpNewSystem->S = 0;
    tmpNewSystem->A = 0;

    if(prev)
        tmpNewSystem->prev = prev;
    else
        tmpNewSystem->prev = NULL;
    
    if(next)
        tmpNewSystem->next = next;
    else
        tmpNewSystem->next = NULL;

    return(tmpNewSystem);
}