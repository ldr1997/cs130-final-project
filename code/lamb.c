#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    //8th column = end, 9th = total
    int trans[7][9] = {
        {0, 2, 0, 0, 0, 0, 0, 1, 3},
        {3, 3, 4, 0, 0, 0, 0, 0, 10},
        {0, 5, 5, 0, 1, 0, 0, 0, 11},
        {0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1},
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
        //printf("\nRANDNUM: %d. CURR: %d.\n", randNum, currNote);
        //printf("\n-------\nIN LOOP\n-------\n");
        for (nextNote = 0; randNum >= 0; nextNote++) {
            randNum -= trans[currNote][nextNote];
            //printf("\nRANDNUM: %d. NEXT: %d. TRANS: %d.\n", randNum, nextNote, trans[currNote][nextNote]);
            if (randNum < 0) break;
        }
        //printf("\n-------\nOUTLOOP\n-------\n");
        currNote = nextNote;
        //printf("\nCURR: %d. NEXT: %d.\n", currNote, nextNote);
    }
    printf("\n");
    return 0;
}