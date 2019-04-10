//fonctions
#include "fonction.h"
#include "option.h"
#include "sound.h"
#include "debut.h"
#include "stage1.h"
#define speed 6
void scrolling (Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,Sint16 *pose1,Sint16 *pose2,Sint16 *pose3 ,Sint16 *pose4 ,Sint16 *pose5 ,Sint16 *pose6 ,Sint16 *pose7 ,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera,SDL_Surface **ecran, SDL_Surface **heroactu, int e)
{
if (e==1)
{
	(*camera)+=speed;
	(*poshero)+=speed;
	if((*poshero)>=1366/3 && (*camera)<1366*5) //fixe personnage, deplacement decor
	{
		(*posenigme1)-=speed;
		(*postrap1)-=speed;
		(*posterre1)-=speed;
		(*posterre2)-=speed;
		(*posterre3)-=speed;
		(*posterre4)-=speed;
		(*posterre5)-=speed;
		(*posterre6)-=speed;
		(*posterre7)-=speed;
		(*posterre8)-=speed;
		(*posterre9)-=speed;
		(*poshpup)-=speed;
		(*posmagicien)-=speed;
		(*posrock1)-=speed;
		(*poshero)-=speed;
		(*posback)-=speed;
		(*pospolice)-=speed;
		(*pose1)-=speed;
		(*pose2)-=speed;
		(*pose3)-=speed;
		(*pose4)-=speed;
		(*pose5)-=speed;
		(*pose6)-=speed;
		(*pose7)-=speed;
	}
	if((*poshero)>=((1366/4)*3 +150)) //collision ecran droite
	{
		(*poshero)-=speed;
		(*camera)-=speed;
	}
}
else if (e==2)
{
	(*camera)-=speed;
	(*poshero)-=speed;
	if((*poshero)<=(*ecran)->w/5)
	{
		(*posenigme1)+=speed;
		(*posterre1)+=speed;
		(*posterre2)+=speed;
		(*posterre3)+=speed;
		(*posterre4)+=speed;
		(*posterre5)+=speed;
		(*posterre6)+=speed;
		(*posterre7)+=speed;
		(*posterre8)+=speed;
		(*posterre9)+=speed;
		(*posmagicien)+=speed;
		(*poshpup)+=speed;
		(*postrap1)+=speed;
		(*posrock1)+=speed;
		(*pose1)+=speed;
		(*pose2)+=speed;
		(*pose3)+=speed;
		(*pose4)+=speed;
		(*pose5)+=speed;
		(*pose6)+=speed;
		(*pose7)+=speed;
		(*posback)+=speed;
		(*pospolice)+=speed;
		(*poshero)+=speed;
		if((*camera)<0)
		{
			(*poshero)+=speed;
			(*camera)+=speed;
		}
	}
	if ((*posback)>0)
	{	
		(*posenigme1)=6700;
		(*posterre1)=1300;
		(*posterre2)=1800;
		(*posterre3)=2300;
		(*posterre4)=3300;
		(*posterre5)=3800;
		(*posterre6)=4300;
		(*posterre7)=5300;
		(*posterre8)=5800;
		(*posterre9)=6300;
		(*posmagicien)=7500;
		(*poshpup)=2360;
		(*postrap1)=2800;
		(*posrock1)=500;
		(*pospolice)=800;
		(*pose1)=1000;
		(*pose2)=2000;
		(*pose3)=3000;
		(*pose4)=4000;
		(*pose5)=5000;
		(*pose6)=6000;
		(*pose7)=7000;
		(*posback)=0;
		(*poshero)-=speed;
		if ((*poshero)<0)
		{
			(*poshero)+=speed;
		}
	}
}
}
void animation ( SDL_Surface **a, SDL_Surface *b, int *i)
{
	(*i)++;
        if ((*i)==32)
        {
            (*i)=0;
        }
        (*a)=b;
}

int collision(SDL_Rect hero,SDL_Rect autre)
{
   if((autre.x <= hero.x + hero.w)&& (autre.x + autre.w >= hero.x)&& (autre.y <= hero.y + hero.h)&& (autre.y +autre.h>= hero.y))
          return 1; 
   else
          return 0; 
}
SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	//determine position
	char* pPosition = ( char* ) surface->pixels ;

	//offset by y
	pPosition += ( surface->pitch * y ) ;

	//offset by x
	pPosition += ( surface->format->BytesPerPixel * x ) ;

	//copy pixel data
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;

	//convert color
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}
int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,int decalage,int d)
{

  SDL_Color col;
  if(d==0)//imin
  {
    col=GetPixel(calque,posperso.x+perso->w +decalage,posperso.y+(perso->h/2));
  }
else  if(d==1)//issarr
  {
    col=GetPixel(calque,posperso.x +decalage,posperso.y+(perso->h/2));
  }
else  if(d==2)//lfou9
  {
    col=GetPixel(calque,posperso.x+(perso->w/2)+decalage ,posperso.y);
  }
else  if(d==3)//louta
  {
    col=GetPixel(calque,posperso.x+(perso->w/2) +decalage,posperso.y+perso->h);
  }
  //printf("%d    %d   %d\n",col.r,col.b,col.g );
if ((col.r==255)&&(col.b==255)&&(col.g==255))
{
  return 1;
}
else return 0;
}


void chargerTous(SDL_Surface **ecran,SDL_Surface **star,SDL_Surface **shab1,SDL_Surface **shab2,SDL_Surface **shab3,SDL_Surface **menu,SDL_Surface **texteplay,SDL_Surface **textemulti,SDL_Surface **texteoption,SDL_Surface **textequit,Mix_Music **musique,Mix_Chunk **effet,Mix_Chunk **sonspell,Mix_Chunk **dying,Mix_Chunk **hit, Mix_Chunk **effet2,TTF_Font **police,TTF_Font **police1,SDL_Color couleur)
{
    
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    SDL_WM_SetIcon(IMG_Load("image/icon.png"), NULL);
    (*ecran) = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE); //|SDL_FULLSCREEN);
    SDL_WM_SetCaption("WITCH : Undo The Spell", NULL);
	(*star)=IMG_Load("image/star.png");
	(*shab1)=IMG_Load("image/shab1.png");
	(*shab2)=IMG_Load("image/shab2.png");
	(*shab3)=IMG_Load("image/shab3.png");
    	(*menu) = IMG_Load("image/menu.png");
   

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    (*effet) = Mix_LoadWAV("music/boutonn.wav");
    (*effet2) = Mix_LoadWAV("music/boutofff.wav");
    (*sonspell)= Mix_LoadWAV("music/sonspell.wav");
    //(*hit)=Mix_LoadWAV("music/
    (*dying)=Mix_LoadWAV("music/hero dying2.wav");
    (*musique) = Mix_LoadMUS("music/menu.mp3");

    (*police) = TTF_OpenFont("fonts/Takota.ttf", 70);
    (*police1)= TTF_OpenFont("fonts/calibri.ttf", 20);
    (*texteplay) = TTF_RenderText_Blended((*police), "PLAY", couleur);
    (*textemulti) = TTF_RenderText_Blended((*police), "MULTI", couleur);
    (*texteoption) = TTF_RenderText_Blended((*police), "OPTION", couleur);
    (*textequit) = TTF_RenderText_Blended((*police), "QUIT", couleur);
}
void remplirlesposition(SDL_Rect *positionFond,SDL_Rect *posquit,SDL_Rect *posmulti,SDL_Rect *posoption, SDL_Rect *posplay,SDL_Rect *posstar,SDL_Rect *poscquit,SDL_Rect *poscmulti,SDL_Rect *poscoption,SDL_Rect *poscplay,SDL_Rect *posshab1,SDL_Rect *posshab2,SDL_Rect *posshab3,SDL_Rect *posvolb)
{
    posvolb->x=610;
    posvolb->y=363;
    posshab1->x=10;
    posshab1->y=40;
    posshab2->x=500;
    posshab2->y=200;
    posshab3->x=1170;
    posshab3->y=190;
    posstar->x=655;
    posstar->y=130;
    positionFond->x = 0;
    positionFond->y =0;
    posplay->x=120;
    posplay->y=200;
    posquit->x=120;
    posquit->y=560;
    posmulti->x=120;
    posmulti->y=320;
    posoption->x=120;
    posoption->y=440;
    poscplay->x=250;
    poscplay->y=200;
    poscquit->x=260;
    poscquit->y=560;
    poscmulti->x=300;
    poscmulti->y=320;
    poscoption->x=310;
    poscoption->y=440;

}


void transparent(int *a,int*b)
{
(*a)+=(*b);
			if (((*a)==254)||((*a)==0))
				(*b)=-(*b);

}
void affichagetextmenu(TTF_Font **police,TTF_Font **police1,SDL_Color couleur,SDL_Color couleur2,SDL_Event event,SDL_Surface **texteplay,SDL_Surface **textemulti,SDL_Surface **texteoption,SDL_Surface  **textequit,SDL_Surface **commentaireplay,SDL_Surface  **commentaireoption,SDL_Surface **commentairemulti,SDL_Surface **commentairequit,Mix_Chunk *effet,int *son,int *mute)
{


if (event.motion.x<250  && event.motion.x>120 && event.motion.y<290 && event.motion.y>200)
                {
                    TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
                    (*texteplay)= TTF_RenderText_Blended((*police), "PLAY", couleur2);
                    TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
                    (*commentaireplay) = TTF_RenderText_Blended((*police1), "play solo game", couleur);
                    if ((*son)==0 && *mute==0)
                    {
                        (*son)=1;
                        Mix_PlayChannel( -1, effet, 0 ) ;
                    }
                }
                else if (event.motion.x<285  && event.motion.x>120 && event.motion.y<400 && event.motion.y>340)
                {
                   TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
                    (*textemulti)= TTF_RenderText_Blended((*police), "MULTI", couleur2);
                     TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
                    (*commentairemulti)= TTF_RenderText_Blended((*police1), "play Multiplayer game", couleur);
                    if ((*son)==0 && *mute==0)
                    {
                        (*son)=1;
                        Mix_PlayChannel( -1, effet, 0 ) ;
                    }
                }
                else if (event.motion.x<315  && event.motion.x>120 && event.motion.y<520 && event.motion.y>450)
                {
                    TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
                    (*texteoption) = TTF_RenderText_Blended((*police), "OPTION", couleur2);
                    TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
                    (*commentaireoption)= TTF_RenderText_Blended((*police1), "go to menu option", couleur);
                    if ((*son)==0 && *mute==0)
                    {
                        (*son)=1;
                        Mix_PlayChannel( -1, effet, 0 ) ;
                    }
                }
                else if (event.motion.x<250  && event.motion.x>120 && event.motion.y<640 && event.motion.y>560)
                {
                    TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
                    (*textequit) = TTF_RenderText_Blended((*police), "QUIT", couleur2);
                    TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
	  	    (*commentairequit)= TTF_RenderText_Blended((*police1), "leave game", couleur);
                    if ((*son)==0 && *mute==0)
                    {
                        (*son)=1;
                        Mix_PlayChannel( -1, effet, 0 ) ;
                    }
                }
                else
                {
                    (*son)=0;
                 TTF_SetFontStyle((*police), TTF_STYLE_NORMAL);
                    (*texteplay)= TTF_RenderText_Blended((*police), "PLAY", couleur);
                   (*textemulti)= TTF_RenderText_Blended((*police), "MULTI", couleur);
                    (*texteoption)= TTF_RenderText_Blended((*police), "OPTION", couleur);
                    (*textequit)= TTF_RenderText_Blended((*police), "QUIT", couleur);
                   (*commentaireplay)= NULL;
		   (*commentaireoption)= NULL ;
		   (*commentairequit)= NULL;
		   (*commentairemulti) =NULL;
		}
}
void buttons(SDL_Surface *ecran,SDL_Event event,Mix_Chunk *effet,Mix_Chunk *effet2,int *continuer,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Music *intro,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit)
{
		while (SDL_PollEvent(&event))
		switch(event.type)
		{
            	/*case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
			case SDLK_KP1:
			stage0(ecran,continuer,intro,effet,effet2,musique,mute,posvolb);
			stage1(ecran,continuer,intro,effet,effet2,musique,mute,posvolb);
			break;
			case SDLK_KP3:
			option(ecran,effet,effet2,musique,mute,continuer,posvolb);
			break;
			case SDLK_KP4:
			continuer=0;
			break;
                }*/ 
                }
if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<250  && event.motion.x>120 && event.motion.y<290 && event.motion.y>200)
		{
			//debut(ecran);
			//stage0(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell);
			stage1(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit);
		}
if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<315  && event.motion.x>120 && event.motion.y<520 && event.motion.y>450)
                {
                        if ((*mute)==0)
           		{
           			Mix_PlayChannel( -1, effet2, 0 ) ;
           		}
                    option(ecran,effet,effet2,musique,mute,continuer,posvolb);
                }
                else if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<250  && event.motion.x>120 && event.motion.y<640 && event.motion.y>560)
                {
                        if ((*mute)==0)
           		{
           		Mix_PlayChannel( -1, effet2, 0 ) ;
           		}
                    (*continuer) = 0;
                }
}
void positionenemie(int *i,int *k)
{       if((*k)==2)
                (*i)--;
	if((*k)==1)
		(*i)++;
	if((*i)==20)
	(*k)=2;
	if((*i)==0)
	(*k)=1;	
}
void positionshab(SDL_Rect *posshab1,SDL_Rect *posshab2,SDL_Rect *posshab3, int *direction,int *direction2,int *direction3)
{
    posshab1->x=posshab1->x+(*direction);
    if(posshab1->x==200 || posshab1->x==10)
        (*direction)=-(*direction);
    posshab2->x=posshab2->x+(*direction2);
    if(posshab2->x==500 || posshab2->x==700)
        (*direction2)=-(*direction2);
    posshab3->x=posshab3->x+(*direction3);
    if(posshab3->x==1170 || posshab3->x==1250)
        (*direction3)=-(*direction3);
}


