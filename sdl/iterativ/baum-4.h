// Anzahl der Gleichungen
#define GL_ANZ 6

// Anzahl der Punkte
#define ANZAHL 500000

// Nummer des ersten anzuzeigenden Punktes
#define ERSTER 300

// Wahrscheinlichkeit der Gleichungssysteme: Sei x zufällig 0...99:
// Nimm die Gleichung i mit prozent[i-1] <= x < prozent[i]
int prozent[GL_ANZ] = { 16, 32, 49, 66, 83, 100 };

// GL_ANZ mal 6 Koeffizienten
koeff c[GL_ANZ][6] =
{
  {
    { 0.05, 0.044, 0.056, 0.0003 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0.6, 0.52, 0.68, 0.009 },
    { 0, 0, 0, 0 }
  },
  {
    { 0.05, 0.044, 0.056, 0.0007 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { -0.5, -0.57, -0.43, 0.01 },
    { 1, 0.8, 1.2, 0.015 }
  },
  {
    { 0.46, 0.41, 0.51, 0.0035 },
    { -0.33, -0.38, -0.28, 0.005 },
    { 0, 0, 0, 0 },
    { 0.39, 0.34, 0.44, 0.007 },
    { 0.38, 0.34, 0.42, 0.006 },
    { 0.6, 0.5, 0.7, 0.011 }
  },
  {
    { 0.47, 0.42, 0.52, 0.0045 },
    { -0.15, -0.18, -0.12, 0.003 },
    { 0, 0, 0, 0 },
    { 0.17, 0.13, 0.21, 0.003 },
    { 0.42, 0.38, 0.46, 0.008 },
    { 1.1, 0.9, 1.3, 0.017 }
  },
  {
    { 0.43, 0.38, 0.48, 0.0055 },
    { 0.28, 0.24, 0.32, 0.0025 },
    { 0, 0, 0, 0 },
    { -0.25, -0.29, -0.21, 0.0035 },
    { 0.48, 0.43, 0.53, 0.01 },
    { 1, 0.8, 1.2, 0.013 }
  },
  {
    { 0.42, 0.37, 0.47, 0.0065 },
    { 0.26, 0.22, 0.3, 0.002 },
    { 0, 0, 0, 0 },
    { -0.35, -0.3, -0.2, 0.004 },
    { 0.31, 0.27, 0.35, 0.0055 },
    { 0.7, 0.6, 0.8, 0.013 }
  }
};

// Farbwerte des ersten Punktes:
#define ROT 255
#define GRUEN 0
#define BLAU 0

// Farbänderungstabelle
farbinfo farbe[GL_ANZ] = {
  { 30, 30, 30, 220, 80, 0 },
  { 0, 30, 30, 255, 30, 0 },
  { 70, 100, 130, 0, 20, 40 },
  { 80, 150, 70, 0, 80, 0 },
  { 120, 100, 80, 10, 10, 0 },
  { 150, 80, 70, 20, 10, 0 }
};
