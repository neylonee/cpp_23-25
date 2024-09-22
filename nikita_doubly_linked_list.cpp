#include <stdexcept>


template<typename T> class List {
        struct Node {
                Node* prev;
                Node* next;
                T value;
        };

        class IsEmpty : public std::exception {
                public:
                        IsEmpty() = default;
                private:
                        const char* what() const noexcept override {
                                return "list is empty";
                        }
        };


        Node *head;
        Node *tail;

        public:
                List() {
                        this->head = nullptr;
                        this->tail = nullptr;
                }

                ~List() {
                        while (this->head != nullptr) {
                                this->erase_front();
                        }
                }

                void push_front(const T& value) {
                        Node* a = new Node();
                        a->value = value;
                        a->prev = nullptr;
                        a->next = this->head;

                        if (a->next != nullptr) {
                                a->next->prev = a;
                        }

                        this->head = a;
                        if (this->tail == nullptr) {
                                this->tail = a;
                        }
                }
                void push_back(const T& value) {
                        Node* a = new Node();
                        a->value = value;
                        a->prev = this->tail;
                        a->next = nullptr;

                        if (a->prev != nullptr) {
                                a->prev->next = a;
                        }

                        this->tail = a;
                        if (this->head == nullptr) {
                                this->head = a;
                        }
                }

                void erase_front() {
                        if (this->head == nullptr) {
                                throw IsEmpty();
                        }
                        Node* next = this->head->next;
                        delete this->head;
                        this->head = next;
                        if (next != nullptr) {
                                next->prev = nullptr;
                        }
                }
                void erase_back() {
                        if (this->tail == nullptr) {
                                throw IsEmpty();
                        }
                        Node* prev = this->tail->prev;
                        delete this->tail;
                        this->tail = prev;
                        if (prev != nullptr) {
                                prev->next = nullptr;
                        }
                }

                void swap(Node* a, Node* b) {
                        T c = a->value;
                        a->value = b->value;
                        b->value = c;
                }

                Node* begin() {
                        return this->head;
                }
                Node* end() {
                        return this->tail;
                }
};

