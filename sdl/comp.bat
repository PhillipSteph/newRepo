gcc -o sand.exe -I C:\Users\phill_9k2xq1z\Documents\SDL\SDL2-2.28.5\x86_64-w64-mingw32\include\ sand.c sdlinterf.c -L C:\Users\phill_9k2xq1z\Documents\SDL\SDL2-2.28.5\x86_64-w64-mingw32\lib\ -static -lmingw32 -lSDL2main -lSDL2 -Wl,--no-undefined -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc -lhid -lsetupapi