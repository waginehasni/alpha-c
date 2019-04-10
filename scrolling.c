# alpha-c
#include<stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main()
{
SDL_Surface *screen;
SDL_Surface *image=NULL;
int continuer=1;
SDL_Init(SDL_INIT_VIDEO);
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("unable to set video mode SDL : %s\n",SDL_GetError());
return 1;
}

     
    screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (!screen){
printf("unable to set 600x400 video: %s\n",SDL_GetError());
                                         return (-1);
              }

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
  SDL_Flip(screen);
    
image=SDL_LoadBMP("back2.bmp");
SDL_Rect camera;
camera.x=0;
camera.y=0;
camera.w=640;
camera.h=480;
SDL_Event event;
while(continuer)
{
SDL_BlitSurface(image,&camera,screen,NULL);


SDL_Flip(screen);
SDL_PollEvent(&event);
switch(event.type)
{


case SDL_KEYDOWN:

switch(event.key.keysym.sym)
{
case SDLK_ESCAPE:
continuer=0;
break;
case SDLK_RIGHT:
camera.x++;
break;
case SDLK_LEFT:
camera.x--;
break;
}
break;
}
}
SDL_Quit();
return 0;
}
