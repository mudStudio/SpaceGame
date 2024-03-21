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
typedef struct CelestObject
{
    SDL_Color       celestObjColor;

    char            *celestObjName;
    unsigned int    nbSite;


    void            *prev;
    void            *next;

} CelestObject;

typedef struct System
{
    SDL_Color       sysColor;

    char            *sysName;
    unsigned int    nbCelestObject;
    CelestObject    *pListCelestObject;
    
    unsigned int    P;
    unsigned int    S;
    unsigned int    A;

    void            *prev;
    void            *next;

} System;

typedef struct Univers
{
    SDL_Rect    rect;
    System      *pSystemList;

    char        ***Map;
    char        *representation;
} Univers;

//Convergence
typedef struct Game {
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    Mouse *pMouse;
    Keyboard *pKeyboard;

    Univers *pUnivers;
} Game;

#endif // STRUCT_H_INCLUDED
