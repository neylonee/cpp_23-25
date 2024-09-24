#include <iostream>
struct Structure{
    int a;
    Structure* next;
    Structure(){
        next = nullptr;
    }
};
int print(Structure* tail){
    Structure* temp = tail;
    unsigned int i = 0;
    while(temp->next != 0){
        std::cout<<i<<" element - "<<temp->a<<std::endl;
        temp = temp->next;
        i++;
    }
    std::cout<<i<<" element - "<<temp->a<<std::endl;

    return -1;
}
void insert(Structure* tail, int data){
    Structure* temp = tail;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new Structure;
    temp->next->a = data;
    temp = temp->next;
}
int remove(Structure* tail, int num){
    Structure* temp = tail;
    Structure* prev;
    while(temp -> next != nullptr && num>0){
        prev = temp;
        temp = temp -> next;
        num--;
    }
    if(num>0){
        std::cout<<"Num is out of range"<<std::endl;
        return -1;
    }
    prev -> next = temp -> next;
    temp -> next = nullptr;
    delete temp;
    return 0;

}
int main(){
    Structure s1;
    s1.a = 0;
    for(int i = 1; i <= 5; i++){
        insert(&s1,i*10);
    }
    print(&s1);
    remove(&s1,10);
    remove(&s1, 3);
    print(&s1);
    s1.~Structure();
}
