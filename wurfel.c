#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, const char *argv[]){
int temp=0;
int r=1;
srand(time(NULL));

while(temp!=r){

r = rand() % 6 + 1;
printf("\nGewurfelt wurde %d",r);

if(temp==r){
    printf(" %d == %d ",r,temp);
    return 0;
}

temp = r;
r=0;
}

    return 0;
}