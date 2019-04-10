# alpha-c
#include "fichier.h"

void affichback(BACKGROUND *back,SDL_Surface *ecran)
{  

SDL_Delay(20);
SDL_BlitSurface( back->fond[0],NULL, ecran,&back->position);


}


