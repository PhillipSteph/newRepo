// Kleines Grafik-Demo-Beispiel: 2 Linien
//
// Aufruf: demo0
//
// Klaus Kusche, 2010

#include "sdlinterf.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x=SDL_X_SIZE/2,y=SDL_Y_SIZE/2,r,k,l,m;
  srand(time(NULL));
  sdlInit();       // mach das Grafik-Fenster auf
  //sdlSetBlack();   // mach alle Pixel schwarz


  for(int i=1;i<SDL_X_SIZE-1;i++){
    for(int j=1;j<SDL_Y_SIZE-1;j++){
        sdlDrawPoint(i,j,144,0,0);

    }

  }
sdlSetBlack();
while(1){
  
r = rand() % 5;
k = 255;
l = 0;
m = 0;
    switch(r){
            case 0: if(x<SDL_X_SIZE-2){sdlDrawPoint(x+1,y,k,l,m);sdlDrawPoint(x+2,y,k,l,m);x+=2;};
            break;
            case 1: if(y<SDL_Y_SIZE-2){sdlDrawPoint(x,y+1,k,l,m);sdlDrawPoint(x,y+2,k,l,m);y+=2;};
            break;
            case 2: if(x>3){sdlDrawPoint(x-1,y,k,l,m);sdlDrawPoint(x-2,y,k,l,m);x-=2;};
            break;
            case 3: if(y>3){sdlDrawPoint(x,y-1,k,l,m);sdlDrawPoint(x,y-2,k,l,m);y-=2;};
            break;
            default:
            break;
        }
    sdlUpdate(); 
}
  sdlUpdate();          // zeige die gezeichneten Striche wirklich an
  sdlMilliSleep(30000);  // warte vor Beenden des Programms 3 Sekunden 
  sdlExit();            // mach das Grafikfenster wieder zu

  exit(EXIT_SUCCESS);
}