#include <stdio.h>
#include <stdlib.h>
#include "header.h"

typedef struct WaterJug {
    int capacity;
    int fullness;
}WaterJug;

typedef struct ListElement { //typedef - define a type
    struct ListElement *next; //is null default here?
    WaterJug *waterJugL;
    WaterJug *waterJugS;
}ListElement; //listelement exists now

ListElement *head = NULL; //global pointer var on heap - pointers are variables, on stack, but they point to an address on heap.

ListElement* newListElement(WaterJug *waterJug1, WaterJug *waterJug2) { //allocates mem for a List Element, which contains a WJ pointer
    ListElement *h = malloc(sizeof (struct ListElement));
    h -> next = NULL;
    h -> waterJugL = waterJug1;
    h -> waterJugS = waterJug2;
    return h;
}

WaterJug *newWaterJug(int cap, int full) {
    WaterJug *newWaterJug = malloc(sizeof (WaterJug)); //have to dec as pointer
    newWaterJug ->fullness = full;
    newWaterJug -> capacity = cap;
    return newWaterJug;
}

void addHead(struct ListElement *obj) { //takes pointer
    if(head == NULL) {
        head = obj;
    } else {
        obj -> next = head; //address of new first element 'next' linking to address of old first element (the old head)
        head = obj; //setting new head to be the obj passed in
        /*
         ListElement *h = malloc(sizeof (struct ListElement)); //variables are on the stack- need a heap variable.
         Pointers referring to heap - there forever until you decide! managed by garbage collection.
        //pointers are just numbers - the important part is the address. and it will give the type.

        h .waterJug = obj .waterJug;
        h . next = head;*/
    }
}

void addTail(struct ListElement obj) {
    if(head == NULL) {
        *head = obj;
    } else {
        struct ListElement *thing;
        *thing = *head;
        while (thing ->next != NULL) {
            *thing = *thing ->next;
        }
        *thing -> next = obj;
    }
}

/* global variable declaration */
WaterJug smallWJ;
WaterJug largeWJ;

//here passing by value - should pass by reference (difference between reference and pointers)
#if 0
int pour (struct WaterJug source, struct WaterJug dest) {
    dest += source;
    source = 0;
    return 3;
}
#endif

//to declare as a pointer use *
ListElement* pour(ListElement *listElement, WaterJug *source, WaterJug *dest) {
    //*dest += *source; //de-reference
    if(source->fullness > dest->fullness) {
        int amountTransf = dest -> capacity - dest -> fullness;
        dest -> fullness = dest -> capacity;
        source -> fullness = source -> fullness - amountTransf;
    } else {
        dest ->fullness += source ->fullness; //-> pointer operator
        source -> fullness = 0;
    }
    if (source ->capacity = listElement -> waterJugS) {
       listElement -> waterJugS = source;
       listElement -> waterJugL = dest;
    } else {
        listElement -> waterJugS = dest;
        listElement -> waterJugL = source;
    }
    return listElement;
}

ListElement* fillLarge(ListElement *listElement) {
    int capacityLarge;
    capacityLarge = listElement -> waterJugL -> capacity;
    listElement -> waterJugL -> fullness = capacityLarge;
    return listElement;
}

ListElement* fillSmall(ListElement *listElement) {
    int capacitySmall;
    capacitySmall = listElement -> waterJugS -> capacity;
    listElement -> waterJugS -> fullness = capacitySmall;
    return listElement;
}

ListElement* emptyLarge(ListElement *listElement) {
    listElement -> waterJugL -> fullness = 0;
    return listElement;
}

ListElement* emptySmall(ListElement *listElement) {
    listElement -> waterJugS -> fullness = 0;
    return listElement;
}

//OO - the compiler is passing the references (inferring the 'this' pointer)
//need to know when passing value and when passing a pointer

void add_a(int a) {
    a++;
    printf("%i\n", a); //copy
}
//preferably pass by reference (less overhead but can have side effects)
//essentially never pass by copy
//func programming - no side effects. c non func programming
//pointer - literally an address
//if you point to something random..your program will crash
//OOO languages obfuscate all of these

void add_b(int *b) {
    *b = *b+1;
}



int main(void){
    WaterJug smallJ;
    WaterJug largeJ;
    smallJ.fullness = 0;
    largeJ.fullness = 0;
    smallJ.capacity = 3;
    largeJ.capacity = 5;
    //ListElement testElement(*smallJ, *largeJ);
/*  testElement.waterJugL->fullness = 0;
    testElement.waterJugL->capacity = 5;

    testElement.waterJugS->fullness = 0;
    testElement.waterJugS->capacity = 3;*/

    ListElement *listElement = newListElement(&smallJ, &largeJ); //pass address of stack var waterjugs - not a good idea


    printf("%p\n", listElement -> next); //null is 0, prints as 0000000
    printf("%i\n", listElement  -> waterJugL->fullness);
    printf("%i\n", listElement  -> waterJugS->fullness);

    printf("%i\n", listElement -> waterJugL->capacity);
    printf("%i\n", listElement -> waterJugS->capacity);

    return 0;
    /*addTail(testElement);
    printf("%s\n", testElement .next);
    printf("%s\n", testElement .waterJug1);
    addHead(testElement);
    printf("%s\n", testElement .next);
    printf("%s\n", testElement .waterJug1);*/

/*  int a = 5;
    add_a(a);
    printf("%i\n", a);
    add_b(&a);
    printf("%i\n", a);
    printf("%i %i %i\n", sizeof(a), sizeof(&a), sizeof(WaterJug));
    //4, 4, 8 = Waterjug is so big because it is two ints. we also have to *return* it as a copy
*/

 /*   smallWJ.capacity = 3;
    smallWJ.fullness = 0;

    largeWJ.capacity = 5;
    largeWJ.fullness = 5;

    printf("%i\n", largeWJ.fullness);
    printf("%i\n", smallWJ.fullness);

    pour(&largeWJ, &smallWJ); //&take the address of this object - the address is a pointer

    printf("%i\n", largeWJ.fullness);
    printf("%i\n", smallWJ.fullness);*/


}