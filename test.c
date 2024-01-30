#include <string.h>
#include <stdio.h>

int main(){
char str1[10]= "Hallo";
char str2[10]= {'H','A','L','\0'};

char* chrptr = strchr(str1,'l');
char* strptr = strstr(str1,"lo");
int position = chrptr - str1;
int stringposition = strptr - str1;

putchar(*chrptr); printf(" found at position %d\n",position);
printf(" String %s found at position %d\n",strptr,position);

printf("Length of str1: %d",strlen(str2));
printf("%s",str2);
    return 0;
}


void summary(char str1[],char str2[]){

strcmp(str1,str2); // vergleicht zwei strings, returned 0 wenn ident

strlen(str1); // returned länge des arrays des strings

strcpy(str2,str1); // kopiert str1 in str2 hinein.
//returned pointer auf str2 außerdem

strcat(str2,str1); //hängt str1 an str2 an.
//returned pointer auf str2 außerdem

char c,string[10];

strchr(str1,c); //sucht in str1 nach char c ; 
//returned pointer auf ersten c

strstr(str2,string); //sucht nach substring in string  
//returned pointer auf ersten gültigen String

}