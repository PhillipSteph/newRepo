#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
if(argc==1){
    printf("primfaktorzerlegung Zahl");
    return 1;
}

for(int i=1;i<argc;i++){
int wert = atoi(argv[i]);
int n=2;
while(wert>1)
    if(wert%n==0){
        printf("%d ",n);
        wert = wert / n;
    }else{
        n++;
    }
putchar('\n');
}

    return 0;
}
