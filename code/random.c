#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    int trans[7][9] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 8},
        {1, 1, 1, 1, 1, 1, 1, 1, 8},
        {1, 1, 1, 1, 1, 1, 1, 1, 8},
        {1, 1, 1, 1, 1, 1, 1, 1, 8},
        {1, 1, 1, 1, 1, 1, 1, 1, 8},
        {1, 1, 1, 1, 1, 1, 1, 1, 8},
        {1, 1, 1, 1, 1, 1, 1, 1, 8},
    };
    char start;
    int currNote, randNum, nextNote;
    printf("Enter starting note: ");
    scanf("%c", &start);
    switch(start) {
        case 'c':
        case 'C':
            currNote = 0;
            break;
        case 'd':
        case 'D':
            currNote = 1;
            break;
        case 'e':
        case 'E':
            currNote = 2;
            break;
        case 'f':
        case 'F':
            currNote = 3;
            break;
        case 'g':
        case 'G':
            currNote = 4;
            break;
        case 'a':
        case 'A':
            currNote = 5;
            break;
        case 'b':
        case 'B':
            currNote = 6;
            break;
        default:
            printf("ERROR: Invalid input\n");
            currNote = 7;
    }

    printf("Melody: ");
    while (currNote != 7) {
        switch(currNote){
            case 0:
                printf("C ");
                break;
            case 1:
                printf("D ");
                break;
            case 2:
                printf("E ");
                break;
            case 3:
                printf("F ");
                break;
            case 4:
                printf("G ");
                break;
            case 5:
                printf("A ");
                break;
            case 6:
                printf("B ");
        }
        randNum = rand() % trans[currNote][8];
        for (nextNote = 0; randNum >= 0; nextNote++) {
            randNum -= trans[currNote][nextNote];
            if (randNum < 0) break;
        }
        currNote = nextNote;
    }
    printf("\n");
    return 0;
}