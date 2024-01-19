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
int arr2[SDL_X_SIZE][SDL_Y_SIZE];
int r;
int main(void)
{
  srand(time(NULL));
  sdlInit();       // mach das Grafik-Fenster auf
  sdlSetBlack();   // mach alle Pixel schwarz


  for(int i=1;i<SDL_X_SIZE-1;i++){
    for(int j=1;j<SDL_Y_SIZE-1;j++){

        r = rand() % 2;
        arr[i][j]=r;
        if(r==1){
        sdlDrawPoint(i,j,255,0,0);
        }
        r=0;
    }

  }

while(1){
  for(int i=1;i<SDL_X_SIZE-1;i++){
    for(int j=1;j<SDL_Y_SIZE-1;j++){

      r=rand()%100;
      if(r==2){
        arr[i][j]=1;
        sdlDrawPoint(i,j,255,0,0);
      }
      

    int nachbarsumme=0;

if(arr[i-1][j-1]==1 || arr[i-1][j-1]==2){
  nachbarsumme++;
}
if(arr[i][j-1]==1 || arr[i][j-1]==2){
  nachbarsumme++;
}
if(arr[i-1][j]==1 || arr[i-1][j]==2){
  nachbarsumme++;
}
if(arr[i+1][j-1]==1 || arr[i+1][j-1]==2){
  nachbarsumme++;
}
if(arr[i+1][j]==1 || arr[i+1][j]==2){
  nachbarsumme++;
}
if(arr[i][j+1]==1 || arr[i][j+1]==2){
  nachbarsumme++;
}
if(arr[i+1][j+1]==1 || arr[i+1][j+1]==2){
  nachbarsumme++;
}
if(arr[i-1][j+1]==1 || arr[i-1][j+1]==2){
  nachbarsumme++;
}
if(arr[i][j]==0){
  if(nachbarsumme==3){
  arr[i][j]=1;
  sdlDrawPoint(i,j,0,255,0);
}
}else{

if(nachbarsumme==3 || nachbarsumme==2){
  arr[i][j]=1;
  sdlDrawPoint(i,j,255,0,0);
}else{
  
arr[i][j]=0;
sdlDrawPoint(i,j,0,0,0);
        }
      }

    }
  }
  sdlMilliSleep(8);
  sdlUpdate(); 
}

  sdlUpdate();          // zeige die gezeichneten Striche wirklich an
  sdlMilliSleep(30000);  // warte vor Beenden des Programms 3 Sekunden 
  sdlExit();            // mach das Grafikfenster wieder zu

  exit(EXIT_SUCCESS);
}