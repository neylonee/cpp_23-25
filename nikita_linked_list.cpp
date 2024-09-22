#include <stdexcept>


template<typename T> class ForwardList {
        struct Node {
                Node *next;
                T value;
        };

        class IsEmpty : public std::exception {
                public:
                        IsEmpty() = default;
                private:
                        const char* what() const noexcept override {
                                return "forward list is empty";
                        }
        };


        Node* head;

        public:
                ForwardList() {
                        this->head = nullptr;
                }
                ~ForwardList() {
                        while (this->head != nullptr) {
                                this->erase_front();
                        }
                }
                void push_front(const T& value) {
                        Node* current = new Node();
                        current->next = this->head;
                        current->value = value;
                        this->head = current;
                }
                void erase_front() {
                        if (this->head == nullptr) {
                                throw IsEmpty();
                        }
                        Node* next = this->head->next;
                        delete this->head;
                        this->head = next;
                }
                Node* begin() {
                        return this->head;
                }
};
int main(){
}
