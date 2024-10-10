#include <iostream>
#include "Train.h"
#include "time.h"
int main(){
    srand(time(nullptr));
    int numWagons = std::rand() % 30;
    Train Train(numWagons);
    Train.print();
    std::cout<<"Real num wagons: "<<numWagons<<std::endl;
    std::cout<<"Func says: "<<Train.countWagons()<<std::endl;
    return 0;
}
