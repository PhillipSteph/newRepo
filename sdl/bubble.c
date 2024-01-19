// Bubblesort-Funktion mit Pointern (Sortieren durch Vertauschen)
//
// Aufruf: bubblesort-ptr anzahl
//
// Klaus Kusche, 2021

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "sdlinterf.h"

// Verzögerungen (in Millisekunden) für die Grafik-Anzeige
// ... beim Start
#define START_MS 200
// ... am Ende (bevor das Fenster verschwindet)
#define ENDE_MS 3000
// ... bei jedem Vergleich
#define VERGL_MS 50
// ... bei jeder Vertauschung
#define TAUSCH_MS 100

// die Farbwwerte
const int farbe_normal[] = { 0, 255, 0 };     // normaler Balken
const int farbe_vergl[] = { 255, 255, 0 };    // zu vergleichender Balken
const int farbe_tausch[] = { 255, 0, 255 };   // zu vertauschender Balken
const int farbe_schwarz[] = { 0, 0, 0 };      // schwarz (zum Weglöschen)

// Konstanten (in Pixeln) für das Grafik-Layout
// initialisiert in "main", benutzt in "balken"
// Breite eines Balkens
int breite;
// Eine Höhen-Einheit
int hoehe;
// Linker Rand = Startposition des ersten Balkens in X-Richtung
// (gleicher Rand links & rechts,
// damit die Balken im Fenster schön in der Mitte stehen)
int xstart;

// Zähler für die Vergleiche und Vertauschungen
int vergl = 0;
int vertau = 0;

// Pointer auf den Anfang unseres Arrays
// Für die Funktion "balken", damit sie ausrechnen kann,
// das wievielte Element im Array sie zeichnen soll
int *arr_beg;

// Zeichne den Balken für das Array-Element, auf das p zeigt, in Farbe farbe
void balken(const int *p, const int farbe[])
{
  int xpos = xstart + (p - arr_beg) * breite;
  sdlDrawRectFromTo(xpos + 1, SDL_Y_SIZE - 1,
                    xpos + breite - 1, SDL_Y_SIZE - *p * hoehe,
                    farbe[0], farbe[1], farbe[2]);
  sdlUpdate();
}

// Vergleiche mit farbiger Anzeige und Verzögerung:
// Ist das Element, auf das p1 zeigt, kleiner als das Element, auf das p2 zeigt?
// Ergebnis: true / false
// Da wir das Array mit lauter verschiedenen Elementen initialisieren,
// kommt "gleich" nicht vor!
bool kleiner(const int *p1, const int *p2)
{
  ++vergl;

  balken(p1, farbe_vergl);
  balken(p2, farbe_vergl);
  sdlMilliSleep(VERGL_MS);
  balken(p1, farbe_normal);
  balken(p2, farbe_normal);
  
  return (*p1 < *p2);
}

// Vertausche das Element, auf das p1 zeigt, mit dem Element, auf das p2 zeigt
// mit farbiger Anzeige und Verzögerung
void tausche(int *p1, int *p2)
{
  ++vertau;

  // zeichne die zu vertauschenden Balken färbig
  balken(p1, farbe_tausch);
  balken(p2, farbe_tausch);
  sdlMilliSleep(TAUSCH_MS);

  // zeichne den längeren alten Balken schwarz,
  // weil sonst würde nach dem Tausch beim Überzeichnen mit dem kürzeren Balken
  // oben ein Rest sichtbar bleiben!
  if (*p1 > *p2) {
    balken(p1, farbe_schwarz);
  } else {
    balken(p2, farbe_schwarz);
  }

  // tausche
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;

  // zeichne die vertauschten Balken normal
  balken(p1, farbe_normal);
  balken(p2, farbe_normal);
}

// Befülle das Array zufällig mit den Zahlen 1 bis anzahl
// und zeige den Anfangszustand an
void fuelle(int arr[], int anzahl)
{
  // Array aufsteigend mit den Zahlen 1 bis anzahl füllen (daher ...+1)
  for (int *p = arr; p < arr + anzahl; ++p) {
    *p = (p - arr) + 1;
  }

  // Array mischen:
  // 3000 mal zwei zufällige Positionen im Array ermitteln
  // und die Werte an diesen Positionen vertauschen
  // (es gibt bessere Verfahren, aber die sind nicht gefragt)
  for (int i = 0; i < 3000; ++i) {
    int *p1 = arr + rand() % anzahl;
    int *p2 = arr + rand() % anzahl;
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
  }  

  for (int *p = arr; p < arr + anzahl; ++p) {
    balken(p, farbe_normal);
  }
}

/*
// sortiere das Array, Grundversion
void sort(int arr[], int anzahl)
{
  // Für jede Position pos von der letzten bis zur zweiten (rückwärts) ...
  for (int *pos = arr + anzahl - 1; pos > arr; --pos) {
    // ... Geh alle Positionen p von der ersten bis vor pos durch, ...
    for (int *p = arr; p < pos; ++p) {
      // ... vergleiche den Wert an dieser Position mit dem folgenden Wert ...
      if (kleiner(p + 1, p)) {
        // ... und vertausche die beiden, wenn sie in falscher Reihenfolge sind.
        tausche(p, p+1);
      }
    }
  }
}
*/

// sortiere das Array, verbesserte Version
void sort(int arr[], int anzahl)
{
  // pos ist das Ende der inneren Schleife und beginnt ganz hinten
  // und wenn es ganz vorne oder -1 ist, sind wir fertig
  // zur Abwechslung einmal mit &(...) statt Pointer-Rechnung
  for (int *pos = &(arr[anzahl - 1]); pos > arr; /* unten! */ ) {
    int *letzter = arr;  // Position der letzten Vertauschung
                         // Wert arr ==> keine Vertauschung
    // ... Geh alle Positionen i von der ersten bis *vor* pos durch, ...
    for (int *p = arr; p < pos; ++p) {
      // ... vergleiche den Wert an dieser Position mit dem folgenden Wert ...
      if (kleiner(p + 1, p)) {
        // und vertausche wenn er größer als sein Nachfolger ist
        tausche(p, p + 1);
        letzter = p;
      }
    }
    // Position der letzten Vertauschung
    // = hinteres Ende des nächsten Schleifen-Durchlaufes
    // (oder -1, wenn gar keine Vertauschung mehr stattgefunden hat)
    pos = letzter; 
  }
}

int main(int argc, const char *argv[])
{
  if (argc != 2) {
    printf("Aufruf: %s anzahl\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  int anzahl = atoi(argv[1]);
  if ((anzahl <= 0) || (anzahl > SDL_X_SIZE / 2) || (anzahl > SDL_Y_SIZE)) {
    printf("%s: Die Anzahl muss größer 0 sein "
          "und in das Grafikfenster passen\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  // Geometrie aus der Anzahl berechnen
  breite = SDL_X_SIZE / anzahl;
  hoehe = SDL_Y_SIZE / anzahl;
  xstart = (SDL_X_SIZE % anzahl) / 2;

  int array[anzahl];
  arr_beg = array;

  srand(time(NULL));

  sdlInit();
  sdlSetBlack();

  fuelle(array, anzahl);
  
  sdlMilliSleep(START_MS);  

  sort(array, anzahl);

  printf("%d Vergleiche\n%d Vertauschungen\n", vergl, vertau);

  sdlMilliSleep(ENDE_MS);
  sdlExit();
  
  exit(EXIT_SUCCESS);
}