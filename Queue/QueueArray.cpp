#include <iostream>

template <typename T>
class QueueArray {
private:
    int maxSize;
    int currentSize;
    T* array;
    int first;
    int last;
public:
    QueueArray(int newSize = 5) {
        maxSize = newSize;
        array = new T[maxSize];
        first = -1;
        last = 0;
        currentSize = 0;
    }

    ~QueueArray() {
        delete[] array;
    }

    void enqueue(T element) {
        if(currentSize == maxSize) {
            std::cout<<"Queue is full\n";
            return;
        }

        array[last] = element;
        last++;
        last = last % maxSize;
        currentSize++;
        std::cout << "Inserted: " << element << std::endl;
    }
    
    T dequeue() {
        if(currentSize == 0) {
            std::cout<<"Queue is empty\n";
            return T();
        }

        first++;
        first = first % maxSize;
        currentSize--;
        std::cout<< "Returned: " << array[first] << std::endl;
        return array[first];
    }
};