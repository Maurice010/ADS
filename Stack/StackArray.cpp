#include <iostream>

template <typename T>
class StackArray {
private:
    T* array;
    int size;
    int top;

public:
    StackArray(int maxSize = 5) {
        size = maxSize;
        array = new T[maxSize];
        top = -1;
    }

    ~StackArray() {
        delete[] array;
    }

    void push(T element) {
        if(top == size - 1) {
            std::cout<<"Stack is full\n";
            return;
        }
        array[++top] = element;
        std::cout << "Inserted: " << element << std::endl;
    }

    T pop() {
        if(top == -1) {
            std::cout<<"Stack is empty\n";
            return T();
        }
        std::cout<< "Returned: " << array[top] << std::endl;
        return array[top--];
    }
};