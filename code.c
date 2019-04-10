#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#define speed  6
int main ()
{
int continuer=1;
SDL_Surface*ecran=NULL, *background=NULL,*herod=NULL,*herog=NULL,*heroactu=NULL;
SDL_Rect posback,poshero,framed[8],posspell ;
int i=0,j=0,x=0,y=0,p=0,k=-1,e=2;
SDL_Event event;
Uint8 *keystates = SDL_GetKeyState( NULL );
posback.x=0;
posback.y=0;
poshero.x=1150;
poshero.y=460; 
SDL_Init(SDL_INIT_VIDEO);
ecran= SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE);
background=IMG_Load ("image/stage/maison.png");
herog=IMG_Load ("image/perso/wl.png");
herod=IMG_Load ("image/perso/wr.png");
heroactu=herog;
SDL_BlitSurface(background, NULL, ecran, &posback);
SDL_BlitSurface(heroactu, &framed[i/4], ecran, &poshero);
SDL_Flip(ecran);
for (i=0; i<8;i++)
	{
		if (j==4)
		{
			x=0;
			y=y+250;
			j=0;
		}
		framed[ i ].x=x;
		framed[ i ].y=y;
    		framed[ i ].w =140;
    		framed[ i ].h = 250;
    		x=x+140;
    		j++;
	}
    	x=0;
    	y=0;
    	j=0;

while(continuer)
{
while (SDL_PollEvent(&event))
       		switch(event.type)
        	{
       			case SDL_QUIT:
            		continuer = 0;
            		break;
            		
			
            		
		}
  		if(keystates[SDLK_d])
		{
			        heroactu=herod;
            			i++;
            			e=1;
                                 if (i==32)
                                 {
                                          i=0;
                                 }
				poshero.x+=speed;
		}
		if(keystates[SDLK_q])
		{          			
            			  heroactu=herog;
            			i++;
            			e=2 ;
                                 if (i==32)
                                 {
                                          i=0;
                                 }
            			poshero.x-=speed;
		}
		if ((poshero.x-poshero.w)>=1100)
		poshero.x-=speed ;
		SDL_BlitSurface(background, NULL, ecran, &posback);
		
       	 	SDL_BlitSurface(heroactu, &framed[i/4], ecran, &poshero);
       	 	SDL_Flip(ecran);


}
}

