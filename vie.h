# alpha-c
#ifndef SCORE_H_INCLUDED
	
#define SCORE_H_INCLUDED
	
#include<SDL/SDL.h>
	#include<stdio.h>

	#include<stdlib.h>
	
#include<SDL/SDL_audio.h>

	#include<SDL/SDL_mixer.h>

	#include<SDL/SDL_image.h>

	
	typedef struct vie
	
{
		int nb;
		
SDL_Rect position;
		

SDL_Surface *fond1;
		
SDL_Surface *fond2;
	
	SDL_Surface *fond3;

		SDL_Surface *fond4;
	
	SDL_Surface *fond5;
	

}vie;
	
	
void initialiservie(vie *vie);

	void affichervie(vie *vie,SDL_Surface *ecran);


#endif
