#include <stdio.h>
#include "header.h"

typedef struct WaterJug {
    int capacity;
    int fullness;
}WaterJug;

int main(void){
    printf("%d", returnSeven());
    WaterJug smallWJ;
    WaterJug largeWJ;

    smallWJ.capacity = 3;
    smallWJ.fullness = 0;

    largeWJ.capacity = 5;
    largeWJ.fullness = 0;

    pour(smallWJ.fullness, largeWJ.fullness);

    return 0;
}