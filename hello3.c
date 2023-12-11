#include <stdio.h>

int main(int argc, const char *argv[])
{
  if (argc == 1) {
    printf("Hallo, ich bin %s wer bist du?\n",argv[0]);
  }
  else if(argc>11){
    printf("Hallo an alle!");
     printf("Ihr seid %d Leute!",argc-1);
  }
   else {
    for (int i = argc-1; i >= 1; --i) {

      printf("Hallo, %s!\n", argv[i]);
      if(i==1){
        printf(" Du bist der Erste!\n");
      }else{
        printf(" Du bist Nummer %d\n",i);
      }

    }
     printf("Ihr seid %d Leute!",argc-1);
  }
  return 0;
}