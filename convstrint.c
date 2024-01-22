#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int strtoint(const char arr[]);
char* inttostring(int input, char* string);
int main(int argc, const char *argv[]){

    if(argc<=1) return 1;

    for(int j=1;j<argc;j++){
        if((argv[j][0]<'0' || argv[j][0]>'9') && argv[j][0]!='-'){
            int zahl = strtoint( argv[j] );
            printf("\n%d",zahl);
        }
        else {
            char* string = inttostring(atoi(argv[j]));
            char a;
            while(a!=0){
                a = *string++;
                printf("%c",a);
            }
        }
    }
    return 0;
}

int strtoint(const char arr[]){

    int length = strlen(arr);
    int wert=0,a,i;
    if(arr[0]=='-'){
        i=1;
        a=-1;
    }else{
        i=0;
        a=1;
    }
    for(i;i<length;++i){

        if(arr[i]<'0' || arr[i]>'9'){
            exit(EXIT_FAILURE);
        }
        
         wert = wert*10+(arr[i]-'0');

    }
return wert*a;
}

char* inttostring(int input, char* string){
    int temp=input;
    int laenge=0;
while(temp>=1){   
    temp/=10;
    laenge++;       //bestimmt länge des Integers, indem Wert solange durch 10 geteilt wird bis <1, jede division wird länge++
}
for(int i=0;i<laenge;i++){
    string[laenge-1-i] = input%10;
    input = (input - input % 10)/10;
}
return string;


}