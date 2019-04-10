# alpha-c 
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h>

	
void pause();
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL;
    SDL_Rect positionFond;
	int continuer=1; 

    positionFond.x = 0;
    positionFond.y = 0;
imageDeFond = SDL_LoadBMP("back.bmp");
    SDL_Init(SDL_INIT_VIDEO);   
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("MAjd ", NULL);
    
	SDL_Event event;
	while(continuer)
	{SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    SDL_Flip(ecran);
	SDL_WaitEvent(&event);
	if(event.type==SDL_QUIT)
	{continuer=0;}


	}

	
	SDL_FreeSurface(imageDeFond);
    SDL_Quit();

	return EXIT_SUCCESS;

}

