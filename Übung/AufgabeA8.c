#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define maxzeile 100

typedef struct listelem
{
    const char *filename;
    int znr;
    const char *text;
    struct listelem *next;
} listelem;

typedef struct liste
{
    listelem *head;
    listelem *tail;
} liste;

void anhang(liste arr[], const char *filename, int znr, const char *text)
{
    listelem *e = (listelem *)(malloc(sizeof(listelem)));

        e->text = strdup(text);
        e->filename = filename;
        e->znr = znr;
        e->next = NULL;
    int i = strlen(text);
    if(sizeof(arr)/sizeof(arr[0])==0){
        arr[i].head = e;
    }else{
        arr[i].tail->next = e;
    }
    arr[i].tail = e;
    
}
void verarbeitung(liste arr[],const char *filename){
    FILE *input = fopen(filename, "r");
    char string[maxzeile];
    fgets(string,maxzeile,input);
   for (int znr = 1; fgets(string, sizeof (string), input); ++znr) {
    // Wurde die Zeile komplett incl. \n gelesen, oder fehlt das hinteren Ende?
    if (strchr(string, '\n') == NULL) {
      exit(EXIT_FAILURE);
    }
    save_line(arr, filename, znr, string);
  }


    fclose(input);
}
void print(liste arr[]){
    for(int i = 0; i< maxzeile; ++i){
        for(listelem *p = arr[i].head; p!=NULL; p = p->next){
            if (printf("%s:%d: %s", p->filename, p->znr, p->text) < 0) {
            exit(EXIT_FAILURE);
      }
        }
    }
}
int main(int argc, char const *argv[])
{

      // Pro möglicher Zeilenlänge eine eigene Liste
  liste lines[maxzeile];

  if (argc == 1) {
    exit(EXIT_FAILURE);
  }

  // Alle Listen auf "leer" initialisieren
  for (int i = 0; i < maxzeile; ++i) {
    lines[i].head = lines[i].tail = NULL;
  }

  for (int i = 1; i < argc; ++i) {
    read_file(lines, argv[i]);
  }

  write_lines(lines);
  
  exit(EXIT_SUCCESS);
}
