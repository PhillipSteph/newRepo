#include "sdlinterf.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  srand(time(NULL));
  sdlInit();       // mach das Grafik-Fenster auf
  sdlSetBlack();   // mach alle Pixel schwarz

    int x1=SDL_X_SIZE/2-10,x2=SDL_X_SIZE/2+10,y1=SDL_Y_SIZE/2-10,y2=SDL_Y_SIZE/2+10;
    sdlDrawRectFromTo(x1,y1,x2,y2,255,0,0);

char direction;
sdlUpdate();
while(1){
    scanf("%c", &direction);
    switch(direction){
        case 'w': y1= y1 - 10; y2 = y2-10;
        case 'a': x1-= 10; x2-=10;
        case 's': y1+= 10; y2+=10;
        case 'd': x1+= 10; x2+=10;
    }
    sdlSetBlack();
    sdlDrawRectFromTo(x1,y1,x2,y2,255,0,0);
    sdlUpdate();
}

  sdlUpdate();          // zeige die gezeichneten Striche wirklich an
  sdlMilliSleep(30000);  // warte vor Beenden des Programms 3 Sekunden 
  sdlExit();            // mach das Grafikfenster wieder zu

  exit(EXIT_SUCCESS);
}