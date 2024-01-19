#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool minmax(double* arrptr, int laenge, double* min, double* max);

int main(int argc, const char *argv[]){
    if(argc==1){
        printf("zu wenig Argumente");
        return 1;
    }

double min,max;
int laenge=argc-1;
double arr[argc-1];
for(int i=argc-1;i>0;i--){
    arr[i-1]=atof(argv[i]);
}

printf("Your boolean variable is: %s", minmax(arr,laenge,&min,&max) ? "true" : "false");
printf("\n%f, %f",min,max);
    return 0;
}

bool minmax(double* arrptr, int laenge, double* min, double* max){
    if(laenge <= 0){
        return false;
    }

*min = *max = *arrptr;

    for(int i=1;i<laenge;i++){
              arrptr++;
        if(*arrptr<*min){
            *min=*arrptr;
        }
        if(*arrptr>*max){
            *max=*arrptr;
        }
    }
    return true;

}