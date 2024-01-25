#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sdlinterf.h"
#include <stdbool.h>
void drawarr(int* arr,int balken);
void bogosort(int* arr, int balken, int ms);
void bubblesort(int* arr, int balken, int ms);

int cnt=0;

int main(int argc, const char *argv[]){
int ms = atoi(argv[2]);
    int balken = atoi(argv[1]);
    printf("%d",balken);
if(argc> 3) return 1;
srand(time(NULL));
int arr[balken];
sdlInit();
sdlSetBlack();
for(int i=0;i<balken;i++){
    int r = rand() % SDL_Y_SIZE ;
    arr[i]=r;
}   //initialisiere Array


drawarr(arr,balken);


//randomsort
bogosort(arr, balken, ms);

sdlUpdate();
sdlMilliSleep(20000);
sdlExit();
    return 0;
}



void drawarr(int* arr,int balken){

for(int i=0;i<balken;i++){
 sdlDrawRectFromTo(SDL_X_SIZE*i/balken+1,SDL_Y_SIZE-1,SDL_X_SIZE*(i+1)/balken-1,SDL_Y_SIZE-1-arr[i],255,0,0);   
 sdlUpdate();
}

}

void bogosort(int* arr, int balken, int ms){
    
while(true){
    cnt++;
    sdlSetBlack();
    for(int i=0;i<balken;i++){
    int r = rand() % SDL_Y_SIZE ;
    arr[i]=r;
}

bool isordered = true;
for(int i=1;i<balken;i++){
if(isordered == false){break;}
if(arr[i]>arr[i-1]){
    isordered = true;
}else{
    isordered = false;
}

}
if(isordered){
    drawarr(arr,balken);
    printf("\n%d mal generiert",cnt);
    sdlMilliSleep(10000);
    exit(EXIT_SUCCESS);
}

sdlMilliSleep(ms);
drawarr(arr,balken);
}

}
void bubblesort(int* arr, int balken, int ms){
    
while(true){
    cnt++;
    sdlSetBlack();
    for(int i=0;i<balken;i++){
    int r = rand() % SDL_Y_SIZE ;
    arr[i]=r;
}

bool isordered = true;
for(int i=1;i<balken;i++){
if(isordered == false){break;}
if(arr[i]>arr[i-1]){
    isordered = true;
}else{
    isordered = false;
}

}
if(isordered){
    drawarr(arr,balken);
    printf("\n%d mal generiert",cnt);
    sdlMilliSleep(10000);
    exit(EXIT_SUCCESS);
}

sdlMilliSleep(ms);
drawarr(arr,balken);
}

}