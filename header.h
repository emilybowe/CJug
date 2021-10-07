#include <stdbool.h>

typedef struct WaterJug {
    int capacity;
    int fullness;
}WaterJug;

typedef struct ListElement {
    struct ListElement *next;
    WaterJug *waterJugL;
    WaterJug *waterJugS;
}ListElement;

struct ListElement* pourLargeIntoSmall(struct WaterJug *source, struct WaterJug *dest); //c needs to be told when it's a pointer
struct ListElement* pourSmallIntoLarge(struct WaterJug *source, struct WaterJug *dest);
struct ListElement* newListElement(struct WaterJug *waterJug1, struct WaterJug *waterJug2);
ListElement* newListElement(WaterJug *waterJug1, WaterJug *waterJug2) ;
WaterJug *newWaterJug(int cap, int full);
ListElement* addHead(struct ListElement *head, struct ListElement *obj);
ListElement* addTail(struct ListElement *head, struct ListElement *obj);
ListElement* fillSmall(ListElement *listElement);
ListElement* fillLarge(ListElement *listElement);
ListElement* emptyLarge(ListElement *listElement);
ListElement* emptySmall(ListElement *listElement);
ListElement* generateNewStates(ListElement *currentState, int startingJug);
bool checkGoalState();
ListElement* setup(ListElement *currentState, int startingJug);
ListElement* pour(ListElement *currentState, int startingJug);