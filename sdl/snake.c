// Kleines Grafik-Demo-Beispiel: 2 Linien
//
// Aufruf: demo0
//
// Klaus Kusche, 2010

#include "sdlinterf.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int arr[SDL_X_SIZE][SDL_Y_SIZE];
int x=SDL_X_SIZE/2,y=SDL_Y_SIZE/2,r;
int main(void)
{
  srand(time(NULL));
  sdlInit();       // mach das Grafik-Fenster auf
  sdlSetBlack();   // mach alle Pixel schwarz


        for(int i=1;i<SDL_X_SIZE-1;i++){
    for(int j=1;j<SDL_Y_SIZE-1;j++){
        arr[i][j]=0;
        sdlDrawPoint(i,j,130,18,10);
    }
        sdlDrawPoint(x,y,0,0,100);
        arr[x][y]=1;
  }

  int direction=1;
  while (direction==1){
    	r = rand() % 4;

    if(arr[x+1][y]==1 && arr[x][y+1]==1 && arr[x-1][y]==1 && arr[x][y-1]==1){
        for(int i=1;i<SDL_X_SIZE-1;i++){
    for(int j=1;j<SDL_Y_SIZE-1;j++){
        arr[i][j]=0;
        sdlDrawPoint(i,j,130,18,10);
    }
        sdlDrawPoint(x,y,0,0,100);
        arr[x][y]=1;
  }
    };

        switch(r){
            case 0: if(x+3<=SDL_X_SIZE-2){arr[x+1][y]=1; sdlDrawCirc(x+1,y,1,1,0,0,100);x+=2;};
            break;
            case 1: if(y+3<=SDL_Y_SIZE-2){arr[x][y+1]=1; sdlDrawCirc(x,y+1,1,1,0,0,100);y+=2;};
            break;
            case 2: if(arr[x-1][y]!=1 && x>4){arr[x-1][y]=1; sdlDrawCirc(x-1,y,1,1,0,0,100);x-=2;};
            break;
            case 3: if(arr[x][y-1]!=1 && y>4){arr[x][y-1]=1; sdlDrawCirc(x,y-1,1,1,0,0,100);y-=2;};
            break;
            default:
            break;
        }
        sdlUpdate();
  }
/*
    sdlDrawLine(
      SDL_X_SIZE / 4,      // Anfangs-X-Koordinate, 0 ... SDL_X_SIZE - 1
      SDL_Y_SIZE / 4,      // Anfangs-Y-Koordinate, 0 ... SDL_Y_SIZE - 1
      3 * SDL_X_SIZE / 4,  // End-X-Koordinate, 0 ... SDL_X_SIZE - 1
      3 * SDL_Y_SIZE / 4,  // End-Y-Koordinate, 0 ... SDL_Y_SIZE - 1
      255,                 // Farb-Rot-Anteil, 0 ... 255
      0,                   // Farb-Grün-Anteil, 0 ... 255
      0);                  // Farb-Blau-Anteil, 0 ... 255
    sdlDrawLine(
      SDL_X_SIZE / 4,      // Anfangs-X-Koordinate, 0 ... SDL_X_SIZE - 1
      3 * SDL_Y_SIZE / 4,  // Anfangs-Y-Koordinate, 0 ... SDL_Y_SIZE - 1
      1 * SDL_X_SIZE / 4,  // End-X-Koordinate, 0 ... SDL_X_SIZE - 1
      SDL_Y_SIZE / 4,      // End-Y-Koordinate, 0 ... SDL_Y_SIZE - 1
      0,                   // Farb-Rot-Anteil, 0 ... 255
      255,                 // Farb-Grün-Anteil, 0 ... 255
      0);                  // Farb-Blau-Anteil, 0 ... 255

      for(int i=5;i<SDL_X_SIZE-5;i+=10){
       sdlDrawPoint(
         i,100,255,0,0
       );
      }
*/


  sdlUpdate();          // zeige die gezeichneten Striche wirklich an
  sdlMilliSleep(30000);  // warte vor Beenden des Programms 3 Sekunden 
  sdlExit();            // mach das Grafikfenster wieder zu

  exit(EXIT_SUCCESS);
}