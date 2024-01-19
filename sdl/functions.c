#include "sdlinterf.h"
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int x=0,iy=0,y=iy,a;
  srand(time(NULL));
  sdlInit();       // mach das Grafik-Fenster auf
  sdlSetBlack();   // mach alle Pixel schwarz

while(a<SDL_X_SIZE){
    a++;
    x=a/10;
  iy=x;
  y=SDL_Y_SIZE-iy/720;
  if(y<SDL_Y_SIZE && y>0){
    sdlDrawPoint(x,y,0,255,0);
  }
  sdlUpdate(); 
  sdlMilliSleep(8);
}
  sdlUpdate();          // zeige die gezeichneten Striche wirklich an
  sdlMilliSleep(10000);  // warte vor Beenden des Programms 3 Sekunden 
  sdlExit();            // mach das Grafikfenster wieder zu

  exit(EXIT_SUCCESS);
}