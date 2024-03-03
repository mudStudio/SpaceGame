#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

//Other libraries
#ifdef _WIN32
    #include "SDL.h"
#else //#elif __linux__ 
    #include <SDL2/SDL.h>
#endif

//Materials
typedef struct Mouse {
    int MouseX;
    int MouseY;
    int MouseLeftClic;
    int MouseRightClic;
    int MouseWheelUp;
    int MouseWheelDown;
} Mouse;

typedef struct Keyboard {
    int ArrowUp;
    int ArrowLeft;
    int ArrowDown;
    int ArrowRight;
    int Keyz;
    int Keyq;
    int Keys;
    int Keyd;
    int KeySpace;
} Keyboard;

//Software
typedef struct Planet
{
    SDL_Color   plaColor;

    char        *plaName;
    short       nbSite;
};

typedef struct System
{
    SDL_Color   sysColor;

    char        *sysName;
    short       nbPlanet;
};

typedef struct Map // next map ? 
{
    SDL_Rect rectMax;
    SDL_Rect rect;

    char **Map;
    char *representation;
} Map;

typedef struct Dungeon
{
    Map **listMap; // database or hash, next ? 
    Map *pActualMap;

} Dungeon;

//Convergence
typedef struct Game {
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    Mouse *pMouse;
    Keyboard *pKeyboard;

    Dungeon *pDungeon;
} Game;

#endif // STRUCT_H_INCLUDED
