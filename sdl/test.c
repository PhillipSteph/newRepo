// Kruskal's Algorithmus: Minimum Cost Spanning Tree, grafisch
// für eine gegebene Anzahl zufällig innerhalb eines Rechtecks erzeugter Städte
// mit Standard-qsort und Vater-Pointer für Union-Find
//
// Aufruf: kruskal anzahl
//
// Klaus Kusche, 2010

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sdlinterf.h"

// Größe des "Landes" in x- und y-Richtung
// Rundherum lassen wir 10 Pixel Rand
#define PIXEL_OFFSET 10
#define X_SIZE (SDL_X_SIZE - 2 * PIXEL_OFFSET)
#define Y_SIZE (SDL_Y_SIZE - 2 * PIXEL_OFFSET)

// für die Grafik-Ausgabe: Farb-Komponenten für Städte und die Linien
#define CITY_R 255
#define CITY_G 0
#define CITY_B 255
#define LINE_R 0
#define LINE_G 255
#define LINE_B 0

// Wartezeit (Millisekunden) pro angezeigter Verbindung
#define SLEEP_PER_LINE 30

// Typ einer Stadt
typedef struct _city_t {
  int x, y;                  // Pixel-Koordinaten der Stadt
  struct _city_t *up;        // Zeiger zum Vater im Teilbaum
} city_t;

// Typ einer Verbindung
typedef struct {
  city_t *a, *b;             // Die beiden verbundenen Städte
  double dist;               // deren Abstand = Länge der Verbindung
} line_t;

city_t *root(city_t *city);
int lineCmp(const void *l1, const void *l2);
double getDist(city_t *a, city_t *b);

// suche die Stadt,
// die Wurzel jenes Teilbaumes ist, zu dem die Stadt city gehört
city_t *root(city_t *city)
{
  while (city->up != NULL) {
    city = city->up;
  }
  return city;
}

// vergleiche die Länge zweier Verbindungen, Ergebnis wie strcmp (für qsort)
int lineCmp(const void *l1, const void *l2)
{
  double d1 = ((const line_t *) l1)->dist;
  double d2 = ((const line_t *) l2)->dist;
  if (d1 < d2) return -1;
  if (d1 > d2) return 1;
  return 0;
}

// berechne die Entfernung zwischen den Städten a und b
double getDist(city_t *a, city_t *b)
{
  int dx, dy;             // x- und y-Abstand von a und b
  
  dx = b->x - a->x;
  dy = b->y - a->y;
  return sqrt(dx * dx + dy * dy);
}

int main(int argc, const char *argv[])
{
  int cityCnt;               // Anzahl der Städte
  city_t *cities;            // Pointer auf das Array der Städte
  city_t *a, *b;             // Pointer darin
  
  int lineCnt;               // Anzahl der Verbindungen
  line_t *lines;             // Pointer auf das Array der Verbindungen
  line_t *line;              // Pointer darin
  
  if ((argc != 1) || ((cityCnt = 7) <= 0)) {
    fprintf(stderr, "Usage: %s city_count\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  sdlInit();

  srand((unsigned int)(time(NULL)));

  // Städte erzeugen
  while(1){
  cities = (city_t *) (malloc(cityCnt * sizeof (city_t)));
  if (cities == NULL) {
    fprintf(stderr, "%s: Out of memory\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  for (a = cities; a < cities + cityCnt; ++a) {
    int x = a->x = rand() % X_SIZE + PIXEL_OFFSET;
    int y = a->y = rand() % Y_SIZE + PIXEL_OFFSET;
    a->up = NULL;
    sdlDrawLine(x - 2, y - 2, x + 2, y + 2, CITY_R, CITY_G, CITY_B);
    sdlDrawLine(x - 2, y + 2, x + 2, y - 2, CITY_R, CITY_G, CITY_B);
  }
  sdlUpdate();

  // Verbindungen erzeugen
  lineCnt = (cityCnt * (cityCnt - 1)) / 2;
  lines = (line_t *) (malloc(lineCnt * sizeof (line_t)));
  if (lines == NULL) {
    fprintf(stderr, "%s: Out of memory\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  line = lines;
  // Alle Paare, wobei a immer größer als b ist
  // Das verhindert, dass sowohl a<-->b als auch b<-->a gespeichert werden
  for (a = cities + 1; a < cities + cityCnt; ++a) {
    for (b = cities; b < a; ++b) {
      line->a = a;
      line->b = b;
      line->dist = getDist(a, b);
      ++line;
    }
  }

  // Verbindungen sortieren
  qsort(lines, lineCnt, sizeof(line_t), lineCmp);

  int takenLines = 0;    // Anzahl der bisher gewählten Verbindungen
  double totalLen = 0;   // deren Gesamtlänge
  // Baum erstellen:
  // Verbindungen der Reihe nach (in aufsteigender Länge) durchgehen,
  // bis wir genug Verbindungen haben
  // Für einen Baum über cityCnt Städte brauchen wir (cityCnt - 1) Verbindungen
  for (line = lines; takenLines < (cityCnt - 1); ++line) {
    a = line->a;              // die beiden Städte der Verbindung
    b = line->b;
    city_t *aRoot = root(a);  // Wurzeln der Teilbäume der Städte von line:
    city_t *bRoot = root(b);  // Zu welchen Teilbäumen gehören die 2 Städte?
    if (aRoot == bRoot) {
      // Verbindung innerhalb desselben Teilbaumes: Ignorieren
      continue;
    }
    ++takenLines;           // Verbindung zur Lösung dazugeben
    totalLen += line->dist;
    aRoot->up = bRoot;      // verbundene Bäume zusammenhängen
    sdlDrawLine(a->x, a->y, b->x, b->y, LINE_R, LINE_G, LINE_B);
    sdlUpdate();
    sdlMilliSleep(SLEEP_PER_LINE);
  }
  printf("\n%d Verbindungen, Gesamtlänge %g\n", takenLines, totalLen);
  
  // periodisches sdlMilliSleep, damit periodisch auf Close-Events geprüft wird
  sdlMilliSleep(500);
  sdlSetBlack();
  }
  sdlExit();
  
  exit(EXIT_SUCCESS);
}