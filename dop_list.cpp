#include <iostream>
struct Node {
    Node *next;

    Node *prev;
    int numNode;
    int data;
    Node() {
        next = nullptr;
        prev = nullptr;
        numNode = 0;
    }
};
// что такое head
int remove(Node *head, int numElement) {
    // найти эелемент в массиве
    // удалить его
    // вернуть
    Node *temp = head;
    while (temp != nullptr && numElement > 0) {
        temp = temp->next;
        numElement--; // уменьшаем нумэл пока он не станет 0Ъ
    }
    if (numElement > 0) {
        return -1;
    }
    Node *next = temp->next;
    Node *prev = temp->prev;

    prev->next = next;
    next->prev = prev;
    delete temp;
    return 0;
}

int print(Node *tail) {
    if (tail->next == nullptr) {
        std::cout << tail->data;
        return 0;

    } else {
        while (tail->next != nullptr) {
            std::cout << tail->data << std::endl;
            tail->next++;
        }
    }
    return 0;
}

int main() {
    Node *first;
    first->data =10;
    Node* second = new Node();
    second->next = nullptr;
    second->data = 20;
    print(first);

    return 0;
}
