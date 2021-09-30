#include <stdio.h>
#include "header.h"

ListElement *head = NULL;

int other(void){
    WaterJug smallJ;
    WaterJug largeJ;
    smallJ.fullness = 0;
    largeJ.fullness = 0;
    smallJ.capacity = 3;
    largeJ.capacity = 5;

    ListElement *listElement = newListElement(&smallJ, &largeJ);

    printf("%p\n", listElement -> next);
    printf("%i\n", listElement  -> waterJugL->fullness);
    printf("%i\n", listElement  -> waterJugS->fullness);

    printf("%i\n", listElement -> waterJugL->capacity);
    printf("%i\n", listElement -> waterJugS->capacity);
    return 0;
}