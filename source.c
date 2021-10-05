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

ListElement* pourLargeIntoSmall(ListElement *listElement, WaterJug *source, WaterJug *dest) {
   WaterJug *waterJugNewSrc = newWaterJug(source->capacity, 0);
   WaterJug *waterJugNewDst = newWaterJug(dest->capacity, 0);
   int totalVolume = dest->fullness + source->fullness;
   int overSpill = totalVolume - waterJugNewDst->capacity;
   waterJugNewSrc->fullness = overSpill;
   waterJugNewDst->fullness = totalVolume - overSpill;
   ListElement *newlistElement = newListElement(waterJugNewDst, waterJugNewSrc);
   return newlistElement;
}

ListElement* pourSmallIntoLarge(ListElement *listElement, WaterJug *source, WaterJug *dest) {
    WaterJug *waterJugNewSrc = newWaterJug(source->capacity, 0);
    WaterJug *waterJugNewDst = newWaterJug(dest->capacity, 0);
    int totalVolume = dest->fullness + source->fullness;
    int overSpill = totalVolume - waterJugNewDst->capacity;
    waterJugNewSrc->fullness = overSpill;
    waterJugNewDst->fullness = totalVolume - overSpill;
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