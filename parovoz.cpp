#include <iostream>
#include <time.h>
#include <chrono>
struct Wagon {
    bool lampOn;
    Wagon* next;
    Wagon* prev;
    
    Wagon(){

        lampOn = (rand()%2) & (1<<0);
        next = nullptr;
        prev = nullptr;
    }
};

struct Train {
    Wagon* head = nullptr;
    Train(int numWagons) {
        if (numWagons > 0) {
            head = new Wagon();
            Wagon* current = head;
            for (int i = 0; i < numWagons; i++) {
                Wagon* newWagon = new Wagon();
                current->next = newWagon;
                newWagon->prev = current;
                current = newWagon;
            }
            current->next = head;  // Замкнуть список
            head->prev = current;
        }

    }

    ~Train() {
        if (head != nullptr) {
            Wagon* current = head->next;
            while (current != head) {
                Wagon* temp = current;
                current = current->next;
                delete temp;
            }
            delete head;
        }
    }
    
    int print(){
        if (head == nullptr) return 0;
        Wagon* temp = head;
        while(temp->next != head->prev){
            std::cout<<temp->lampOn<<std::endl;
            temp = temp->next;
        }
        std::cout<<temp->lampOn<<std::endl;

        return -1;
    }
    void toggleLamp(Wagon* wagon) {
        wagon->lampOn = !wagon->lampOn;
    }

    int countWagons(){
        if(head == nullptr){
            return 0;
        }
        Wagon* temp = head;
        unsigned int count = 0;
        if(temp->lampOn == 0){
            toggleLamp(temp);
        }

        while(true){
            temp = temp->next;
            count++;
            while(temp->lampOn == 0){
                temp = temp->next;
                count++;
            }
            unsigned int precount = count;
            toggleLamp(temp);
            while(count != 0){
                count--;
                temp = temp->prev;
            }
            if(temp->lampOn == 0){
                return precount -1;
            }
            else{
                precount = 0;
                continue;
            }
    }
    }
};

int main() {
    for(int i = 0; i<10000; i+=100){
    Train* temp;
    for(int i = 0; i < 10000; i+=100){
        temp = new Train(i);
        auto start_time = std::chrono::steady_clock::now();
        std::cout<<"Real num wagons: "<<i<<std::endl;
        std::cout<<"Func says: "<<temp->countWagons()<<std::endl;
        auto end_time = std::chrono::steady_clock::now();
        auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        std::cout << elapsed_ns.count()<<" ms\n";
        delete temp;

    }
    }
    return 0;
}
//создание структуры
//написать функцию, котороая создает закольцованный поезд
//2 ф-я выводит содержимые каждого вагона (00011101010)
