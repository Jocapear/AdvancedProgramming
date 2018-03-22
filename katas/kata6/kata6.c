#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);

    int top, bottom, left, right;
    top = 0;
    bottom = H;
    left = 0;
    right = W;
    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        fprintf("%s\n", bombDir);
        if(!strcmp(bombDir, "D")){
            top = Y0;
            Y0 = top + ((bottom - top)/2);
            
        }else if(!strcmp(bombDir, "DL")){
            top = Y0;
            Y0 = top + ((bottom - top)/2);
            
            right = X0;
            X0 = left + ((right - left)/2);
            
        }else if(!strcmp(bombDir, "DR")){
            top = Y0;
            Y0 = top + ((bottom - top)/2);
            
            left = X0;
            X0 = left +  ((right - left)/2);
        }else if(!strcmp(bombDir, "U")){
            bottom = Y0;
            Y0 = top + ((bottom - top)/2);
        }else if(!strcmp(bombDir, "UL")){
            bottom = Y0;
            Y0 = top + ((bottom - top)/2);
            
            right = X0;
            X0 = left +  ((right - left)/2);
            
        }else if(!strcmp(bombDir, "UR")){
            bottom = Y0;
            Y0 = top + ((bottom - top)/2);
            
            left = X0;
            X0 = left +  ((right - left)/2);
            
        }else if(!strcmp(bombDir, "L")){
            right = X0;
            X0 = left + ((right - left)/2);
            
        }else if(!strcmp(bombDir, "R")){
            left = X0;
            X0 = left + ((right - left)/2);
        }
        //printf("%d\n", X0);
        // the location of the next window Batman should jump to.
        printf("%d %d\n",X0,Y0);
    }

    return 0;
}