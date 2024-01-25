#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct listenknoten {
    int wert;
    struct listenknoten *next;
};
typedef struct listenknoten* knoten;


int main(int argc, const char *argv[]){

struct listenknoten ende = {3,NULL};
struct listenknoten mitte = {2, &ende};
struct listenknoten start = {1,&mitte};
struct listenknoten *ptr = &start;

for(int i=0;i<3;i++){

struct listenknoten a = *ptr;
if(a.wert==3){
    printf("\ngefunden");
    break;
}else {
    printf("\nnicht gefunden");
    ptr = a.next;
}

}
    return 0;
}