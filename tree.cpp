
#include <time.h>
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void inorder() {
        inorderRec(root);
    }

    void FillRandom(int countEl) {

        for(int i = 0;i<countEl;i++){
            root = insertRec(root,(rand()%1000>>1000)); 
        }

    }
private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            std::cout << node->data << " ";
            inorderRec(node->right);
        }
    }
};

int main() {
    BinaryTree tree;
    tree.FillRandom(5);
    tree.insert(5);
//    tree.insert(3);
//    tree.insert(7);
//    tree.insert(2);
//    tree.insert(4);
    
    std::cout << "Inorder traversal: ";
    tree.inorder();

    return 0;
}
