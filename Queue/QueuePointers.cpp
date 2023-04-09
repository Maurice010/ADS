#include <iostream>

template <typename T>
class QueuePointers {
public:
    struct Node {
        T data;
        Node* next;
    };

    QueuePointers() {
        currentSize = 0;
    }

    ~QueuePointers() {
        Node* node = first;
        while(first != nullptr) {
            first = first->next;
            delete node;
            node = first;
        }
    }

    void enqueue(T element) {

        Node* temp = new Node;
        if(currentSize > 0) 
            last->next = temp;

        temp->data = element;
        last = temp;

        if(currentSize == 0)
            first = last;

        currentSize++;
        std::cout << "Inserted: " << element << std::endl;
    }

    T dequeue() {
        if(currentSize == 0) {
            std::cout<<"Queue is empty\n";
            return T();
        }

        T element = first->data;
        Node* temp = first->next;
        delete first;
        first = temp;
        currentSize--;

        std::cout<< "Returned: " << element << std::endl;
        return element;
    }
private:
    Node* first;
    Node* last;
    int currentSize;
};