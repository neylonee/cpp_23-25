#pragma once
struct Wagon{
    bool lampOn;
    Wagon* next;
    Wagon* prev;
    Wagon();
    ~Wagon();
};
