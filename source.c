#include "header.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

int GOAL_STATE = 4;

int decideNextAction() {
    return rand() % 6;
}

ListElement* addToList(ListElement *headElement, ListElement *currentElement) {
    while (!checkGoalState()) {
        ListElement *newState = generateStates(currentElement);
        addTail(headElement, newState);
        printf("New element WaterJugL %i\n", newState->waterJugL->fullness);
        printf("New element WaterJugS %i\n", newState->waterJugS->fullness);
    }
}

ListElement* generateStates(ListElement *currentElement) {
    int decider = decideNextAction();
    if(decider == 0) {
        ListElement *newElement = fillSmall(currentElement);
        return newElement;
    } else if(decider == 1) {
        ListElement *newElement = fillLarge(currentElement);
        return newElement;
    } else if(decider == 2) {
        ListElement *newElement =
                pourSmallIntoLarge(currentElement->waterJugS, currentElement->waterJugL);
        return newElement;
    } else if(decider == 3) {
        ListElement *newElement =
                pourLargeIntoSmall(currentElement->waterJugL, currentElement->waterJugS);
        return newElement;
    } else if(decider == 4) {
        ListElement *newElement = emptySmall(currentElement);
        return newElement;
    } else if(decider == 5) {
        ListElement *newElement = emptyLarge(currentElement);
        return newElement;
    } else {
        return currentElement;
    }
}

bool checkGoalState(ListElement *currentElement) {
    currentElement->waterJugL->fullness = GOAL_STATE;
}

ListElement* newListElement(WaterJug *smallJ, WaterJug *largeJ) {
    ListElement *h = malloc(sizeof (struct ListElement));
    h -> next = NULL;
    h -> waterJugS = smallJ;
    h -> waterJugL = largeJ;
    return h;
}

WaterJug *newWaterJug(int cap, int full) {
    WaterJug *newWaterJug = malloc(sizeof (WaterJug));
    newWaterJug->fullness = full;
    newWaterJug->capacity = cap;
    return newWaterJug;
}

ListElement* addHead(struct ListElement *head, struct ListElement *obj) {
    if(head == NULL) {
        head = obj;
    } else {
        obj -> next = head;
        head = obj;
    }
    return head;
}

ListElement* addTail(struct ListElement *head, struct ListElement *obj) {
    if(head == NULL) {
        head = obj;
    } else {
        struct ListElement *thing;
        thing = head;
        while (thing ->next != NULL) {
            thing = thing ->next;
        }
        thing -> next = obj;
    }
    return head;
}

void pourAIntoB(WaterJug *A, WaterJug *B, WaterJug **newA, WaterJug **newB) { // pointers to pointers; tell it it's an address
    *newA = newWaterJug(A->capacity, 0); //de-reference
    *newB = newWaterJug(B->capacity, 0);
    int totalVolume = B->fullness + A->fullness;
    int overSpill = totalVolume - (*newB)->capacity; //brackets for operation order
    (*newA)->fullness = overSpill;
    (*newB)->fullness = totalVolume - overSpill;
}

ListElement* pourLargeIntoSmall(WaterJug *source, WaterJug *dest) {
   WaterJug *waterJugNewSrc = NULL;
   WaterJug *waterJugNewDst = NULL;
   pourAIntoB(source, dest, &waterJugNewSrc, &waterJugNewDst);
   ListElement *newlistElement = newListElement(waterJugNewDst, waterJugNewSrc);
   return newlistElement;
}

ListElement* pourSmallIntoLarge(WaterJug *source, WaterJug *dest) {
    WaterJug *waterJugNewSrc = NULL;
    WaterJug *waterJugNewDst = NULL;
    pourAIntoB(source, dest, &waterJugNewSrc, &waterJugNewDst);
    ListElement *newlistElement = newListElement(waterJugNewSrc, waterJugNewDst);
    return newlistElement;
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