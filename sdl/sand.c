#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sdlinterf.h"
#include <stdbool.h>
#define color(r, g, b) r, g, b

int main(int argc, const char *argv[])
{
    srand(time(NULL));
    sdlInit();
    sdlDrawRectFromTo(1, 1, SDL_X_SIZE - 1, SDL_Y_SIZE - 1, 0, 0, 250);
    const int size = atoi(argv[1]);
    const int possibility = atoi(argv[2]);
    const int ms = atoi(argv[3]);
    int colorarr[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            colorarr[i][j] = 255 * j / size;
        }
    }

    int arr[size][size]; // N-dimensionale Matrix für darstellung.
    int sarr[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
            sarr[i][j] = 0;
        }
    }
    /* drawing function
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j])
            {
                sdlDrawRectFromTo((SDL_X_SIZE * i / size) + 1, (SDL_Y_SIZE * j / size) + 1, (SDL_X_SIZE * (i + 1) / size) - 1, (SDL_Y_SIZE * (j + 1) / size) - 1, 250, 0, 0);
            }
        }
    }*/
    int cnt = size * size * 5;
    int r;

    while (cnt > 0) // start repeat
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = size / 5 + 1; j >= 0; j--)
            {
                if (!arr[i][j])
                {
                    r = rand() % possibility;
                    if (r == 1)
                    {
                        arr[i][j] = 1;
                        cnt--;
                    }
                }
            }
        }
        for (int i = 0; i < size; i++)
        {
            arr[i][size - 1] = 1;
        }
        for (int k = 0; k < size; k++)
        {
            for (int l = 0; l < size; l++)
            {
                if (arr[k][l])
                {
                    sdlDrawRectFromTo((SDL_X_SIZE * k / size) + 1, (SDL_Y_SIZE * l / size) + 1, (SDL_X_SIZE * (k + 1) / size) - 1, (SDL_Y_SIZE * (l + 1) / size) - 1, color(k, 255-l, 0));
                }
            }
        }
        sdlUpdate();
        sdlMilliSleep(ms);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (arr[i][j] == 1 && arr[i][j + 1] == 0)
                {
                    sarr[i][j + 1] = 1; // kopiere array in sarray
                    sarr[i][j] = 0;
                }
            }
        }
        int x = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size-1; j++)
            {
                if (sarr[i][j] == 0)
                {
                    x++;
                }
            }
            if(x==size){
                for(int k=0;k<size;k++){
                    sarr[i][k]==0;
                }
            }
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                arr[i][j] = sarr[i][j]; // kopiere sarray in array
            }
        }
        sdlDrawRectFromTo(0, 0, SDL_X_SIZE - 1, SDL_Y_SIZE - 1, 0, 0, 0);
    } // end of while
    sdlUpdate();
    sdlMilliSleep(2000);
    sdlExit();
    return 0;
}
