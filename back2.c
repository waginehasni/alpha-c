# alpha-c
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <string.h>
#include "fichier.h"
void main()
{  int running=1;
 BACKGROUND back;
  SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *ecran=NULL;




      

	ecran=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("WELCOME",NULL);

intialiser_back(&back);







while(running==1)
{SDL_PollEvent(&event);

affichback(&back,ecran);
SDL_Flip(ecran);



//SDL_WaitEvent(&event);
 switch(event.type)
        { 
            case SDL_QUIT:
                running= 0;
                break;
            case SDL_KEYDOWN :
  switch(event.key.keysym.sym)
        {
     case SDLK_ESCAPE :
      running = 0;
      break;
       }
        }

}
SDL_FreeSurface(back.fond[0]);
SDL_FreeSurface(ecran);		
SDL_Quit();
}
