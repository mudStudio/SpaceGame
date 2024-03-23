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
    InitFillUnivers(pGame->pUnivers, true);
    
    //display -> Term
    displayUniversMapTerm(pGame->pUnivers);

/* Init System */
    InitSystem(pGame->pUnivers);

/* Init Celestes Objects */
    InitSystemObject(pGame->pUnivers);
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

void    InitFillUnivers(Univers *pUnivers, bool randlen){

    if(randlen){
        pUnivers->rect.h = Random(H_MIN, H_MAX);
        pUnivers->rect.w = Random(W_MIN, W_MAX);
    }
    else{
        pUnivers->rect.h = H_MAX;
        pUnivers->rect.w = W_MAX;
    }

    pUnivers->Map = (char***)malloc(sizeof(char**) * (pUnivers->rect.h + 1));
    for (int i = 0; i < pUnivers->rect.h; ++i)
        pUnivers->Map[i] = (char**)malloc(sizeof(char*) * (pUnivers->rect.w + 1));

    // insert -- make control of this shit
    for (int i = 0; i < pUnivers->rect.h; ++i)
    {
        for (int j = 0; j < pUnivers->rect.w; ++j)
        {
            int tmp_rand = Random(MIN_PLANET, MAX_PLANET);

            pUnivers->Map[i][j] = (char*)malloc(sizeof(char) * (tmp_rand + 1));
            pUnivers->Map[i][j][tmp_rand + 1] = '\0';
            
            if (Random(0,100) > 10) // -> define.h
            {
                pUnivers->Map[i][j][0] = ' ';
                for (int k = 1; k <= tmp_rand; ++k)
                    pUnivers->Map[i][j][k] = '\0';
            }
            else
            {
                char tmp_system_nb = Random(MIN_PLANET, tmp_rand) + '0'; // ?
                pUnivers->Map[i][j][0] = tmp_system_nb;
                
                /** FILL SYSTEM WITH OBJECTS **/
                for (int k = 1; k <= tmp_rand; ++k)
                {
                    pUnivers->Map[i][j][k] = InitMapSystem();
                    if(pUnivers->Map[i][j][k] == 'P')
                        total_planet += 1;
                    else if(pUnivers->Map[i][j][k] == 'S')
                        total_satelite += 1;
                    else if(pUnivers->Map[i][j][k] == 'A')
                        total_asteroid += 1;
                }
            }
        }
    }}

System  *CreateSystem(System *prev, System *next){
    System *tmpNewSystem = calloc(1, sizeof(System));
    if (tmpNewSystem == NULL){
    fprintf(stderr, "ERROR : Create tmpNewSystemList failed.");
    exit(EXIT_FAILURE);
    }

    tmpNewSystem->sysColor = tmp_color;
    tmpNewSystem->sysName = randSystemName();
    tmpNewSystem->nbCelestObject = 1;
    tmpNewSystem->pListCelestObject = NULL; // Create Object

    if(prev)
        tmpNewSystem->prev = prev;
    else
        tmpNewSystem->prev = NULL;
    
    if(next)
        tmpNewSystem->next = next;
    else
        tmpNewSystem->next = NULL;

    return(tmpNewSystem);}

void    InitSystem(Univers *pUnivers){
    pUnivers->pSystemList = CreateSystem(NULL, NULL);

    int nb_system = 1;
    System *tmp = pUnivers->pSystemList;

    for (int i = 0; i < pUnivers->rect.h; ++i){
        for (int j = 0; j < pUnivers->rect.w; ++j)
            if (pUnivers->Map[i][j][0] != ' ')
                {
                    nb_system++;
                    pUnivers->pSystemList->next = CreateSystem(pUnivers->pSystemList, NULL);
                    pUnivers->pSystemList = pUnivers->pSystemList->next;
                }
    }
    pUnivers->pSystemList = tmp;

    printf("\nCreation of %d news systems with %d Planet(s), %d Satelite(s) and %d Asteroïd(s).\n", \
        nb_system, total_planet, total_satelite, total_asteroid);fflush(stdout);}

void    InitSystemObject(pGame->pUnivers){
    pUnivers->pSystemList->pListCelestObject = CreateCelectObject(NULL, NULL);
}
