#include <iostream>
#include <time.h>
#include "Node.h"
Wagon::Wagon() {
    lampOn = (rand()%2) & (1<<0);
    next = nullptr;
    prev = nullptr;
}

