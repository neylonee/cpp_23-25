#include <iostream>
struct Structure{
    int a;
    Structure* next;
    Structure* prev;
    Structure(){
        next = nullptr;
        prev = nullptr;
    }

    ~Structure();
};

int print(Structure* tail){
    Structure* temp = tail;
    int i = 0;
    while(temp->prev != nullptr){
        temp = temp->prev;
    }
    while(temp->next != nullptr){
        std::cout<<i<<" element - "<<temp->a<<std::endl;
        i++;
        temp = temp->next;
    }
    std::cout<<i<<" element - "<<temp->a<<std::endl;

    return -1;
}
void insert_front(Structure* tail, int data){
    Structure* temp = tail;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new Structure;
    temp->next->prev = temp;
    temp->next->a = data;
    temp = temp->next;
    delete temp;
}
void insert_behind(Structure* tail, int data){
    Structure* temp = tail;
    while(temp->prev!=nullptr){
        temp = temp->prev;
    }
    tail = new Structure();
    tail->a = data;
    temp->prev = tail;
    tail->next = temp;
    delete temp;
}
int remove(Structure* tail, int num){
    Structure *temp = tail;
    while(temp->prev != nullptr){
        temp = temp->prev;
    }
    if(num==0){
        temp->next->prev = nullptr;
        temp->next = temp->next->next;
        delete temp;
        return -1;
    }
    while(temp!=nullptr && num > 0){
        temp = temp->next;
        num--;
    }

    if(num>0){
        std::cout<<"Out of range"<<std::endl;
        return -1;
    }
    else if(num == 0 && temp->next == nullptr){
        temp->prev->next = nullptr;
        delete temp;
        return 0;
    }
    else{
        Structure* next = temp->next;
        Structure* prev = temp->prev;
        prev->next = next;
        next->prev = prev;
        delete temp;
        return 0;

    }
}
int main(){
    Structure s1;
    s1.a = 0;
    for(int i = 1; i<=5; i++){
        insert_behind(&s1, i*-10);
        insert_front(&s1,i*10);
    }
    remove(&s1, 3);

    print(&s1);
    s1.~Structure();
}
