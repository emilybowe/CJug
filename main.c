#include <stdio.h>
#include "header.h"

typedef struct WaterJug {
    int capacity;
    int fullness;
}WaterJug;

typedef struct ListElement {
    struct ListElement *next; //is null default here?
    WaterJug *waterJug;
}ListElement;

struct ListElement *head = NULL;

void addHead(struct ListElement obj) {
    if(head == NULL) {
        *head = obj;
    } else {
        ListElement h;
        h .waterJug = obj .waterJug;
        h . next = head;
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
void pour (WaterJug *source, WaterJug *dest) {
    //*dest += *source; //de-reference
    if(source->fullness > dest->fullness) {
        int amountTransf = dest -> capacity - dest -> fullness;
        dest -> fullness = dest -> capacity;
        source -> fullness = source -> fullness - amountTransf;
    } else {
        dest ->fullness += source ->fullness; //-> pointer operator
        source -> fullness = 0;
    }
}

void fill(WaterJug *jug) {
    jug -> fullness = jug -> capacity;
}

void empty(WaterJug *jug) {
    jug -> fullness = 0;
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

    struct ListElement testElement;
    testElement .next = NULL;
    testElement .waterJug = NULL;

/*    printf("%s\n", testElement .next);
    printf("%s\n", testElement .waterJug);
    addTail(testElement);
    printf("%s\n", testElement .next);
    printf("%s\n", testElement .waterJug);
    addHead(testElement);
    printf("%s\n", testElement .next);
    printf("%s\n", testElement .waterJug);*/


    //return 0;

/*  int a = 5;
    add_a(a);
    printf("%i\n", a);
    add_b(&a);
    printf("%i\n", a);
    printf("%i %i %i\n", sizeof(a), sizeof(&a), sizeof(WaterJug));
    //4, 4, 8 = Waterjug is so big because it is two ints. we also have to *return* it as a copy
*/

    smallWJ.capacity = 3;
    smallWJ.fullness = 0;

    largeWJ.capacity = 5;
    largeWJ.fullness = 5;

    printf("%i\n", largeWJ.fullness);
    printf("%i\n", smallWJ.fullness);


    pour(&largeWJ, &smallWJ); //&take the address of this object - the address is a pointer

    printf("%i\n", largeWJ.fullness);
    printf("%i\n", smallWJ.fullness);

    return 0;
}