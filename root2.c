#include<stdio.h>#include<stdl
ib.h>#include<math.h>intmain(i
ntargc,constchar*argv[]){if(ar
gc<=1||atof(argv[1])<0){printf
("ungueltigerZahlenbereich");r
eturn1;}doublebasis=atof(argv[
1]);doubleergebnis=basis;while
(!(fabs(ergebnis*ergebnis-basi
s)<basis*10e-10)){printf("%.15
g\n",ergebnis);ergebnis=(ergeb
nis+(basis/ergebnis))/2;}print
f("%.15g",ergebnis);return0;}