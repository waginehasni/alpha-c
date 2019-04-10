# alpha-c
#ifndef FICHIER_H
#define FICHIER_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <string.h>

typedef struct BACKGROUND
{ 
SDL_Surface* fond[3];
SDL_Rect position;

}BACKGROUND ;

void intialiser_back(BACKGROUND *back);
void affichback(BACKGROUND *back,SDL_Surface *ecran);

#endif
