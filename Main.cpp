#include <chrono>
#include <iostream>
#include "Train.h"
#include "time.h"
#include "chrono"
int main(){
    Train* temp;
    for(int i = 0; i < 10000; i+=100){
        srand(time(nullptr));
        int numWagons = std::rand() % 1000;
        temp = new Train(numWagons);
        auto start_time = std::chrono::steady_clock::now();
        std::cout<<"Real num wagons: "<<numWagons<<std::endl;
        std::cout<<"Func says: "<<temp->countWagons()<<std::endl;
        auto end_time = std::chrono::steady_clock::now();
        auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        std::cout << elapsed_ns.count()<<" ms\n";
        delete temp;

    }
    return 0;
}
