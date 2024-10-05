#include <iostream>
struct Structure{
    int ar[128];
    Structure* next;
    Structure* prev;
    Structure(Structure&,Structure&,int);
    int print(Structure* tail);
    void insert_front(Structure* tail, int data);
    void insert_behind(Structure* tail, int data);
    void remove(Structure* tail, int num);
};

