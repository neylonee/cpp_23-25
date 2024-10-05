#include <iostream>
#include <vector>

struct Node {
    Node* next;
    Node* prev;
    int nameNode;
    std::vector<Node*> neighbors;
    static int countNodes;
    Node();
    Node(const Node& newNode);
    ~Node();
};

int Node::countNodes = 0;

Node::Node() {
    next = nullptr;
    prev = nullptr;
    countNodes++;
    nameNode = countNodes;
}

Node::Node(const Node& newNode) {
    prev = nullptr;
    next = nullptr;
    nameNode = newNode.nameNode;
    neighbors = newNode.neighbors;

    countNodes++;
}

Node::~Node() {
    countNodes--;
    if (next) {
        delete next;
    }
}

void push_back(Node* head, Node* newNode) {
    if (head == nullptr) {
        head = new Node(*newNode);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(*newNode);
    temp->next->prev = temp;
    temp->neighbors.push_back(temp->next);
}

void add_to_end(Node* head) {
    if (head == nullptr) {
        head = new Node;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node;
    temp->next->prev = temp;
    temp->neighbors.push_back(temp->next);
}

void push_front(Node** head, Node* newNode) {
    (*head)->prev = new Node(*newNode);
    (*head)->prev->next = (*head);
    (*head) = (*head)->prev;
    (*head)->next->neighbors.push_back(*head);
}

void printElements(const Node* head) {
    if (head == nullptr) {
        std::cout << "No elements" << std::endl;
        return;
    }
    const Node* temp = head;
    int i = 0;
    while (temp != nullptr) {
        std::cout << ++i << '\t' << temp->nameNode << std::endl;
        temp = temp->next;
    }
}

void delete_list(Node* head) {
    Node* temp = head;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node();
    Node* temp;
    
    for (int i = 0; i < 10; i++) {
        temp = new Node();
        push_back(head, temp);
        delete temp;
    }

    for (int i = 0; i < 10; i++) {
        temp = new Node();
        push_front(&head, temp);
        delete temp;
    }

    printElements(head);

    delete_list(head);

    return 0;
}
