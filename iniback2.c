# alpha-c
#include "fichier.h"

void intialiser_back(BACKGROUND *back)
{ 
back->fond[0]=IMG_Load("fond.png");

if(back->fond[0]==NULL)
		exit(EXIT_FAILURE);

back->position.x=0;
back->position.y=0;




}


