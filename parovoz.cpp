#include <iostream>
#include <time.h>
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

        int count = 0;
        Wagon* current = head;
        bool corelight = !current->lampOn; 

        while(true){
            current = current->next;
            if(current->lampOn != corelight){
                toggleLamp(current);
            }
            if(head->lampOn == corelight){
                head->lampOn = !corelight;
                break; 
                
            }
        } 
        Wagon* temp = head->next;
        while(temp->lampOn != !corelight){
            count+=1;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    srand(time(nullptr));
    int numWagons = std::rand() % 30;
    Train train(numWagons);
    train.print();
    std::cout<<"Number of wagons - "<<numWagons<<std::endl;
    std::cout << "Func says: " << train.countWagons() << std::endl;
    train.print();

    
    return 0;
}
//создание структуры
//написать функцию, котороая создает закольцованный поезд
//2 ф-я выводит содержимые каждого вагона (00011101010)
