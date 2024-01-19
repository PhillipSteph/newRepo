#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sdlinterf.h"

int main(int argc, const char *argv[]){
if(argc!= 1) return 1;
srand(time(NULL));
static int arr[10];
sdlInit();
sdlSetBlack();
for(int i=0;i<10;i++){
    int r = rand() % 10 + 1 ;
    arr[i]=r;
 sdlDrawRectFromTo(SDL_X_SIZE-(SDL_X_SIZE)/(SDL_X_SIZE)/i,1-());   
}
    return 0;
}