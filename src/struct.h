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
typedef struct AsObject
{
    SDL_Color   asObjColor;

    char        *asObjName;
    short       nbSite;

    void    *prev;
    void    *next;

} AsObject;

typedef struct System
{
    SDL_Color   sysColor;

    char        *sysName;
    short       nbAsObject;
    AsObject    *pListAsObject;

    void      *prev;
    void      *next;

} System;

typedef struct UniversMap
{
    SDL_Rect    rect;
    System      *pSystemList;

    char        **Map;
    char        *representation;
} UniversMap;

//Convergence
typedef struct Game {
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    Mouse *pMouse;
    Keyboard *pKeyboard;

    UniversMap *pUniversMap;
} Game;

#endif // STRUCT_H_INCLUDED
