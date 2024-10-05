
#include <iostream>
struct Node{
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;
    Node();
    Node(const Node& newNode);
    ~Node();
};
int Node::countNodes = 0;
Node::Node(){
    next = nullptr;
    prev = nullptr;
    countNodes++;
    nameNode = countNodes;
}
Node::Node(const Node& newNode){
    prev = newNode.prev;
    next = newNode.next;
    nameNode = newNode.nameNode;

    countNodes++;//надо или нет?
}
Node::~Node(){
    countNodes--;
    if(next != nullptr){
        delete next;
    }
}
class LinkedList{
    private://свва массивы функции переменные объявляются в private
        Node* head;
        Node* tail;
        int countNodes;
    public:  //только методы: конструкторы, деструкторы
        
    protected://сам нод, это пиздец короч
};
void push_back(Node* head, Node* newNode){
    if(head == nullptr){
        head = new Node((const Node&)*newNode);
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new Node((const Node&)*newNode);
    temp->next->prev = temp;
}
void add_to_end(Node* head){
    if(head == nullptr){
        head = new Node;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new Node;
    temp->next->prev = temp;
}

void push_front(Node** head, Node* newNode){ //node** - указатель на адрес; ПЕРЕДАЕМ САМ АДРЕС
    (*head)->prev = new Node((const Node&)*newNode); //*head - адрес хеда; разыминовывание хеда
    (*head)->prev->next = (*head);
    (*head) = (*head)->prev;
}
void printElement(const Node* head){
    if(head==nullptr){
        std::cout<<"no one element"<<std::endl;
    }
    Node* temp =(Node*)head;
    int i = 0;
    while(head -> next != nullptr){
        std::cout<<++i<<'\t' << temp->nameNode<<std::endl;
        temp = temp->next;
    }
    //do{
    //   std::cout << i++ << '\t' << temp -> nameNode << std::endl; //постинкрементео увеличене ++i
    //   temp = temp->next;
    //}while(head != nullptr);
}
int main(){
    Node* head = new Node();
    Node* temp;
    for(int i = 0; i<10;i++){
        temp = new Node();
        push_back(head,temp);
        delete temp;
    }
    for(int i = 0; i< 10; i++){
        temp = new Node();
        push_front(&head, temp);
        delete temp;
    }
    printElement(head);
    delete head;
    delete temp;
    return 0;
}
