#include "header.h"
#include <stdlib.h>
#include <stdbool.h>

int SMALL_JUG = 3;
int LARGE_JUG = 5;
int GOAL_STATE = 4;

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

WaterJug smallWJ;
WaterJug largeWJ;

ListElement* generateNewStates(ListElement *currentState, int startingJug) {
    ListElement *newCurrentState = setup(currentState, startingJug);
    addTail(currentState, newCurrentState);
    ListElement *newerCurrentState = pour(newCurrentState, startingJug);
    addTail(currentState, newerCurrentState);


    while (!checkGoalState(currentState)) {

        checkGoalState(currentState);
    }


}

ListElement* pour(ListElement *currentState, int startingJug) {
    if(startingJug == SMALL_JUG) {
        ListElement *newCurrentState =
                pourSmallIntoLarge(currentState->waterJugS, currentState->waterJugL);
        return newCurrentState;
    } else {
        ListElement *newCurrentState =
                pourLargeIntoSmall(currentState->waterJugL, currentState->waterJugS);
        return newCurrentState;
    }
}

ListElement* setup(ListElement *currentState, int startingJug) {
    if(startingJug == SMALL_JUG) {
        ListElement *newCurrentState = fillSmall(currentState);
        return newCurrentState;
    } else {
        ListElement *newCurrentState = fillLarge(currentState);
        return newCurrentState;
    }
}

bool checkGoalState(ListElement *currentState) {
    return currentState->waterJugL = GOAL_STATE;
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
//   int totalVolume = dest->fullness + source->fullness;
//   int overSpill = totalVolume - waterJugNewDst->capacity;
//   waterJugNewSrc->fullness = overSpill;
//   waterJugNewDst->fullness = totalVolume - overSpill;
   ListElement *newlistElement = newListElement(waterJugNewDst, waterJugNewSrc);
   return newlistElement;
}

ListElement* pourSmallIntoLarge(WaterJug *source, WaterJug *dest) {
    WaterJug *waterJugNewSrc = NULL;
    WaterJug *waterJugNewDst = NULL;
    pourAIntoB(source, dest, &waterJugNewSrc, &waterJugNewDst);
//    int totalVolume = dest->fullness + source->fullness;
//    int overSpill = totalVolume - waterJugNewDst->capacity;
//    waterJugNewSrc->fullness = overSpill;
//    waterJugNewDst->fullness = totalVolume - overSpill;
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