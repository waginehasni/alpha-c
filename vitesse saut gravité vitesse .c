# alpha-c
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#ifdef WIN32
#pragma comment(lib,"sdl.lib")
#pragma comment(lib,"sdlmain.lib")
#endif

#define STAT_SOL 0
#define STAT_AIR 1

typedef struct
{
	int status;
	float x,y;
	float vx,vy;
	SDL_Rect dimensions;
} Sprite;

void InitSprite(Sprite* Sp)
{
	Sp->x = 100.0f;
	Sp->y = 220.0f;
	Sp->status = STAT_SOL;
	Sp->vx = Sp->vy = 0.0f;
	
	Sp->dimensions.x=0;
        Sp->dimensions.y=0;
        Sp->dimensions.h=200;
        Sp->dimensions.w=60;
}

void Render(Sprite* Sp,SDL_Surface* screen,SDL_Surface *image,SDL_Rect camera,SDL_Surface * background )
{

	SDL_Rect R;
	R.x = (Sint16)Sp->x;
	R.y = (Sint16)Sp->y+140;

	SDL_BlitSurface(background,&camera,screen,NULL);
	SDL_BlitSurface(image,&Sp->dimensions,screen,&R);
	//SDL_FillRect(screen,&R,SDL_MapRGB(screen->format,0,255,0));
	
}

void Saute(Sprite* Sp,float impulsion)
{
	Sp->vy = -impulsion;
	Sp->status = STAT_AIR;
}

void ControleSol(Sprite* Sp)
{
	if (Sp->y>250.0f)
	{
		Sp->y = 250.0f;
		if (Sp->vy>0)
			Sp->vy = 0.0f;
		Sp->status = STAT_SOL;
	}
}

void Gravite(Sprite* Sp,float factgravite,float factsautmaintenu,Uint8* keys)
 {
	if (Sp->status == STAT_AIR && keys[SDLK_SPACE])
		factgravite/=factsautmaintenu;
	Sp->vy += factgravite;
}

void Evolue(Sprite* Sp,Uint8* keys,SDL_Rect * camera)
{
	float lateralspeed = 0.5f;
	float airlateralspeedfacteur = 1.0f;
	float maxhspeed = 3.0f; 
	float adherance = 1.5f;
	float impulsion = 6.0f;
	float factgravite = 0.5f;
	float factsautmaintenu = 3.0f;
 //controle lateral(acceleration)
	if (Sp->status == STAT_AIR) // (*2)
		lateralspeed*= airlateralspeedfacteur;
	if (keys[SDLK_LEFT]) // (*1)
		{Sp->vx-=lateralspeed;
	  
	if (keys[SDLK_RIGHT])
		{
		if(Sp->dimensions.x!=240)
                    Sp->dimensions.x=Sp->dimensions.x+60;
                 else
                  Sp->dimensions.x=0;
		 Sp->vx+=lateralspeed;
		 
		//Sp->vx+=20;

		}//+speed nik rouhk}
	if (Sp->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
		Sp->vx/=adherance;
// limite vitesse
	if (Sp->vx>maxhspeed) // (*4)
		Sp->vx = maxhspeed;
	if (Sp->vx<-maxhspeed)
		Sp->vx = -maxhspeed;
// saut
	if (keys[SDLK_SPACE] && Sp->status == STAT_SOL)
		Saute(Sp,impulsion);
	Gravite(Sp,factgravite,factsautmaintenu,keys);
	ControleSol(Sp);
// application du vecteur à la position.
	if(Sp->x<640)	
	{
	 Sp->x +=Sp->vx;
	 if(Sp->x<0)
	Sp->x -=Sp->vx;
	}	
	
         else 
	camera->x+=Sp->vx;
	if(camera->x<0)
	camera->x-=Sp->vx;
	Sp->y +=Sp->vy;

}

int main(int argc,char** argv)
{
	SDL_Surface* screen;
	SDL_Surface *image;
//--------------------------------------------	
	SDL_Surface *background;
	background =IMG_Load("adam.png");
	image=IMG_Load("ghada.png");
	SDL_Rect camera;
	camera.x=0;
	camera.y=0;
	camera.h=720;
	camera.w=1280;
	int cont=1;
	

//-----------------------------------------
	int numkeys;
	Uint8 * keys;
	Sprite S;
	Uint32 timer,elapsed;
	SDL_Init(SDL_INIT_VIDEO);
	screen=SDL_SetVideoMode(1280,720,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
	InitSprite(&S);
	do 
	{
		if(camera.x > 2000)
		cont=0;		
		timer = SDL_GetTicks();
		SDL_FillRect(screen,NULL,0);
		SDL_PumpEvents();
		keys = SDL_GetKeyState(&numkeys);
		Evolue(&S,keys,&camera);
		Render(&S,screen,image,camera,background);
		SDL_Flip(screen);
		elapsed = SDL_GetTicks() - timer;
		if (elapsed<20)
		SDL_Delay(20-elapsed);
	} while (!keys[SDLK_ESCAPE] && cont==1);
	SDL_Quit();
	return 0;
}
  
