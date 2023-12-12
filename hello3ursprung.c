#include <stdio.h>

int main(int argc, const char *argv[])
{
    switch(argc){
        case 1: printf("Hallo, wer bist du?\n");
        break;
        case 2: printf("Hallo, %s!\n", argv[1]);
        break;
        default:
            printf("Hallo, %s", argv[1]);
            for(int i = 2; i<argc-1;++i){
            printf(", %s", argv[i]);
            };
            printf(" und %s!", argv[argc-1]);
        break;
    }
  return 0;
}