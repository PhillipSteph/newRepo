#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, const char *argv[]){
int max=atoi(argv[1]);
int min=max;
   
    for(int i=1;i<argc;i++){
        
        if(atoi(argv[i])<min){
            min=atoi(argv[i]);
        }
        if(atoi(argv[i])>max){
            max=atoi(argv[i]);
        }

    }
printf("min is %d and max is %d",min,max);
    return 0;
}