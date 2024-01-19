#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, const char *argv[]){

if(argc!=2 || atoi(argv[1])<1){
    return 1;
}
int zeilen = atoi(argv[1]);
int arr[zeilen][zeilen];

for(int i=0;i<zeilen;i++){
    arr[i][0]=1;
}
for(int i=0;i<zeilen;i++){
    for(int j=1;j<zeilen;j++){
        arr[i][j]=0;
    }
}
for(int i=1;i<zeilen;i++){
    for(int j=1;j<zeilen;j++){

            arr[i][j]=arr[i-1][j]+arr[i-1][j-1];

    }
}
//print
for(int i=0;i<zeilen;i++){
    printf("\n");
    for(int j=0;j<zeilen;j++){
        printf(" %3d",arr[i][j]);
    }
}

    return 0;
}