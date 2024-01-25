#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
int main(int argc, const char *argv[]){
srand(time(NULL));

const char *liste[] = { "haeelbarth",
                        "stephan",
                        "funktion",
                        "programmierung",
                        "rindfleischetikettierungsueberwachungsaufgabenuebertragungsgesetz",
                        "terminal",
                        "kommandozeile",
                        "string",
                        "integer" };
int size = sizeof(liste)/sizeof(liste[0]);

static char eingabe[100];
static char ausgabe[100];

int r = rand()%size;

int wordlength = strlen(liste[r]);
for (int i = 0; i < wordlength; ++i) {
    ausgabe[i] = '*';
  }
  ausgabe[wordlength] = '\0';
  int a,i=0;
  while (a!=0) {
    i=0;
    char c=ausgabe[i];

    while(c!='\0'){
        c= ausgabe[i];
        printf("%c",c);
        i++;
    }
    printf("\n");
    printf("Rate: ");
    scanf("%s", eingabe);
    if(strlen(eingabe)==1){

    }else{
    
       a = strcmp(eingabe, ausgabe);
    	if(a==0){
            printf("success");
            exit(EXIT_SUCCESS);
        }
    }
  }
     return 0;
}