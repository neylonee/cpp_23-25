#include "Train.h"
#include <iostream>
Train::Train(int numWagons) {
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

Train::~Train() {
    Wagon* temp = head;
    temp = temp->next;
    while(temp!=head){
        temp = temp->next;
        delete temp->prev;
    }
    delete head;
}

int Train::print(){
    if (head == nullptr) return 0;
    Wagon* temp = head;
    while(temp->next != head->prev){
        std::cout<<temp->lampOn<<std::endl;
        temp = temp->next;
    }
    std::cout<<temp->lampOn<<std::endl;

    return -1;
}
void Train::toggleLamp(Wagon* wagon) {
    wagon->lampOn = !wagon->lampOn;
}

int Train::countWagons(){
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

