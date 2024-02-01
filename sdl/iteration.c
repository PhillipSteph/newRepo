// Iterated Function Systems (mit Bewegung, ohne Farbe)
//
// Aufruf: ifs-bewegt
//
// Klaus Kusche, 2021

#include <stdlib.h>
#include <time.h>
#include "sdlinterf.h"

// Struktur für einen einzelnen Punkt
typedef struct {
  double x, y;   // Koordinaten des Punktes
} punkt;

// Struktur für die Farbberechnung eines Punktes
typedef struct {
  // Wieviel Prozent der Farbe des vorigen Punktes bekommt der neue Punkt
  // in rot, grün und blau? 
  int proz_rot, proz_gruen, proz_blau;
  // ... und wieviel wird dann zu dieser Farbe noch dazu- oder weggezählt?
  int dazu_rot, dazu_gruen, dazu_blau;
} farbinfo;

// Struktur für einen Koeffizienten in den Gleichungen
typedef struct {
  double wert;     // der aktuelle Wert
  double min_wert; // unterer Grenzwert
  double max_wert; // oberer Grenzwert
  double schritt;  // Schrittweite
                   // ändert bei Überschreiten des Grenzwertes das Vorzeichen!
} koeff;

// Der inkludierte File muss Folgendes enthalten:
//
// * Ein #define für GL_ANZ (Anzahl der Gleichungssysteme =
//   Anzahl der Elemente in den Arrays "prozent" und "c")
//
// * Ein #define für ANZAHL (Anzahl der zu berechnenden Punkte)
//
// * Ein #define für ERSTER (Nummer des ersten zu zeichnenden Punktes)
//
// * Eine Deklaration für ein int-Array "prozent" (mit Init-Werten)
//   mit GL_ANZ vielen Prozentwerten,
//   mit denen die einzelnen Gleichungssysteme ausgewählt werden:
//   Die Gleichungen Nummer i wird verwendet,
//   wenn eine Zufallszahl 0...99 >= prozent[i-1] und < prozent[i] ist
//   Der letzte Wert in "prozent" muss 100 sein!!!
//
// * Eine Deklaration für ein zweidimensionales Array "c" von koeff-Werten
//   mit Initialisierung (alle Gleichungskoeffizienten):
//   Für jeden Koeffizienten 0-5 gibt es GL_ANZ viele verschiedene Werte
//   Erster Index: Welche Möglichkeit bzw. welches Gleichungssystem?
//   Größe des ersten Index: GL_ANZ
//   Zweiter Index: Welcher Koeffizient im Gleichungssystem?
//   Zweite Größe ist fix 6, d.h. Index-Werte 0-5:
//   x = c[0] * x + c[1] * y + c[2]
//   y = c[3] * x + c[4] * y + c[5]

// Dieses #include muss nach den typedef's sein,
// weil der Header die definierten Typen benötigt!
#include "drache.h"

// Koordinaten der Punkte, global wegen der Größe der Arrays
punkt p[ANZAHL];  

int main(void)
{
  srand(time(NULL));

  sdlInit();

  for (;;) {
    // Grenzen der Koordinaten in beide Richtungen
    // beginne mit sehr großem positiven Wert für min
    // und sehr großem negativen Wert für max
    double xmin, xmax, ymin, ymax; 
    xmin = ymin = 1e300;
    xmax = ymax = -1e300;

    // Erster Punkt ist immer 0/0
    p[0].x = p[0].y = 0;
    
    // Die restlichen Punkte der Reihe nach berechnen
    for (int i = 1; i < ANZAHL; ++i) {
      // Gleichung Nummer n zufällig auswählen:
      // In welchen Bereich der Prozent-Angaben im Array prozent
      // fällt eine zufällige Zahl r zwischen 0 und 99 ?
      int n;
      int r = rand() % 100;
      for (n = 0; r >= prozent[n]; ++n) { }

      // neuen Punkt aus vorigem Punkt berechnen
      p[i].x = c[n][0].wert * p[i - 1].x +
               c[n][1].wert * p[i - 1].y +
               c[n][2].wert;
      p[i].y = c[n][3].wert * p[i - 1].x +
               c[n][4].wert * p[i - 1].y +
               c[n][5].wert;

      // die Bildgröße erweitern
      // wenn der neue Punkt außerhalb des bisherigen min und max liegt
      // nur für Punkte, die wirklich gezeichnet werden!
      if (i >= ERSTER) {
        if (p[i].x < xmin) xmin = p[i].x;
        if (p[i].x > xmax) xmax = p[i].x;
        if (p[i].y < ymin) ymin = p[i].y;
        if (p[i].y > ymax) ymax = p[i].y;
      }    
    }

    sdlSetBlack();
    // Punkte der Reihe nach zeichnen,
    // dabei Skalierung von double-Werten auf Pixel-Koordinaten im Fenster
    for (int i = ERSTER; i < ANZAHL; ++i) {
      sdlDrawPoint(((p[i].x - xmin) / (xmax - xmin)) * (SDL_X_SIZE - 1),
                   (1 - (p[i].y - ymin) / (ymax - ymin)) * (SDL_Y_SIZE - 1),
                   0, 255, 0);
    }
    sdlUpdate();
    sdlMilliSleep(50);

    // Für das nächste Bild:
    // Alle Gleichungs-Koeffizienten ein bisschen verändern
    for (int i = 0; i < GL_ANZ; ++i) {
      for (int j = 0; j < 6; ++j) {
        c[i][j].wert += c[i][j].schritt;
        if ((c[i][j].wert > c[i][j].max_wert) ||
            (c[i][j].wert < c[i][j].min_wert)) {
          // Wert außerhalb der Grenzen
          // ==> Veränderungs-Richtung für das nächste Mal umdrehen
          c[i][j].schritt = -c[i][j].schritt;
        }
      }
    }
  }
  
  sdlExit();

  exit(EXIT_SUCCESS);
}