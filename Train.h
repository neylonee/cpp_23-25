#pragma once
#include "Node.h"
struct Train{
    Wagon* head;
    Train(int numWagons);
    ~Train();
    int print();
    void toggleLamp(Wagon* wagon);
    int countWagons();

};
