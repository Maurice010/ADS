#include <iostream>

template <typename T>
class StackPointer {
public:
    struct Node {
        T data;
        Node* next;
    };

    StackPointer() {
        currentSize = 0;
        top = nullptr;
    }

    ~StackPointer() {
        Node* node = top;
        while(top != nullptr) {
            top = top->next;
            delete node;
            node = top;
        }
    }

    void push(T element) {
        Node* temp = top;
        top = new Node;
        top->data = element;
        top->next = temp;
        currentSize++;

        std::cout<< "Inserted: " << element << std::endl;
    }

    T pop() {
        // mozna zainicjowac top = nullptr po prostu sprawdzac czy top nie rowna sie nullptr
        if(currentSize == 0) {
            std::cout<<"Stack is empty\n";
            return T();
        }

        T element = top->data;
        Node* temp = top->next;
        delete top;
        top = temp;
        currentSize--;

        std::cout<< "Returned: " << element << std::endl;
        return element;
    }
private:
    Node* top;
    int currentSize;
};