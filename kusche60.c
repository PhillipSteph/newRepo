// Text zeilenweise sortieren (qsort), von stdin nach stdout
// mit Zeilennummern
// 
// Aufruf: textsort-struct
// 
// Klaus Kusche, 2010

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max. Zeilenlänge der eingelesenen Zeilen (incl. \n\0) 
#define MAX_LEN 82
// Max. Anzahl der Zeilen
#define MAX_LINES 100

// Struktur für unser Array von Zeilen
typedef struct {
  char text[MAX_LEN];    // Text der Zeile
  int lineNr;            // Zeilennummer der Zeile
} line_t;

int lineCmp(const void *p1, const void *p2);

// Vergleichsfunktion für qsort
// p1 und p2 zeigen auf die zu vergleichenden Elemente des Arrays "lines"
// Diese Elemente sind Strukturen (also sind p1 und p2 struct-Pointer),
// und die Zeilentexte im Member "text" dieser beiden struct's
// müssen verglichen werden
int lineCmp(const void *p1, const void *p2)
{
// Möglichkeit 1:
  const line_t *s1 = (const line_t *) p1;
  const line_t *s2 = (const line_t *) p2;
  return strcmp(s1->text, s2->text);

// Möglichkeit 2:
  //return strcmp(((const line_t *) p1)->text,
  //              ((const line_t *) p2)->text);
}

int main(int argc, const char *argv[])
{
  if (argc != 1) {
    fprintf(stderr, "Aufruf: %s\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  line_t lines[MAX_LINES];  // Fixes Array von Zeilen-Strukturen
  int lineCnt;              // Anzahl der belegten Zeilen in lines

  // Input zeilenweise verarbeiten bis der File zu Ende ist, mitzählen
  for (lineCnt = 0; ; ++lineCnt) {
    if (lineCnt == MAX_LINES) {
      fprintf(stderr, "%s: Limit of %d lines exceeded\n", argv[0], MAX_LINES);
      exit(EXIT_FAILURE);
    }

    // Lies eine Zeile und speichere sie im text-Array der aktuellen Struktur
    if (fgets(lines[lineCnt].text, sizeof(lines[lineCnt].text), stdin)
        == NULL) {
      // Input ist zu Ende
      break;      
    }

    if (strchr(lines[lineCnt].text, '\n') == NULL) {
      // Eingelesene Zeile enthält kein \n
      // ==> passiert nur, wenn kein Platz mehr für das \n war
      // ==> Zeile ist länger als MAX_LEN Zeichen
      // Problem unter Windows:
      // Letzte Zeile von Textfiles hat oft kein \n ==> falsche Fehlermeldung!
      // (in Linux hat auch die letzte Zeile immer ein \n)
      fprintf(stderr, "%s: input line too long\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    lines[lineCnt].lineNr = lineCnt + 1;  // "Menschliche" Zeilennummern ab 1
  }

  // sortieren, Elementgröße = Größe einer Struktur
  qsort(lines, lineCnt, sizeof(line_t), lineCmp);

  // zeilenweise ausgeben
  for (int i = 0; i < lineCnt; ++i) {
    printf("%08d: %s", lines[i].lineNr, lines[i].text);
  }
  
  exit(EXIT_SUCCESS);
}