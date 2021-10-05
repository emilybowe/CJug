#include "header.h"
#include <stdlib.h>

ListElement* newListElement(WaterJug *smallJ, WaterJug *largeJ) {
    ListElement *h = malloc(sizeof (struct ListElement));
    h -> next = NULL;
    h -> waterJugS = smallJ;
    h -> waterJugL = largeJ;
    return h;
}

WaterJug *newWaterJug(int cap, int full) {
    WaterJug *newWaterJug = malloc(sizeof (WaterJug));
    newWaterJug ->fullness = full;
    newWaterJug -> capacity = cap;
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

ListElement* pour(ListElement *listElement, WaterJug *source, WaterJug *dest) { //5, 0
    WaterJug *waterJugNewSrc = newWaterJug(0, 0);
   waterJugNewSrc ->capacity = source ->capacity;
   WaterJug *waterJugNewDst = newWaterJug(0, 0);
   waterJugNewDst ->capacity = dest ->capacity;
   waterJugNewDst->fullness = dest -> fullness + source ->fullness; // newDest = 0 + 5 = 5
   int overSpill = waterJugNewDst -> fullness - waterJugNewDst ->capacity; // newDest full 5 - newDest cap 3 = overSpl 2
   waterJugNewSrc ->fullness = overSpill; // newSrc full = overSpl 2 = 2
   waterJugNewDst -> fullness -= overSpill; // newDest full = full 5 - overSpl 2 = 3
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