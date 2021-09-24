struct WaterJug; //forward declaring a reference
struct ListElement;
struct ListElement* pour(struct ListElement *listElement, struct WaterJug *source, struct WaterJug *dest); //c needs to be told when it's a pointer
struct ListElement* newListElement(struct WaterJug *waterJug1, struct WaterJug *waterJug2);
//struct WaterJug *newWaterJug(int cap, int full);
//void addHead(struct ListElement *obj);
//void addTail(struct ListElement obj);