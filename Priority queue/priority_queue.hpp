#pragma once

template <typename T>
class PriorityQueue {
    class QueueElement {
    public:
        int priority;
        T object;

        QueueElement() {}
        QueueElement(T object, int priority) : object(object), priority(priority) {}
    };

    int arraySize;
    int elemNum;
    float loadFactor;
    QueueElement* array;

    void heapifyDown(int index) {
        int k = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(left < elemNum && array[left].priority > array[k].priority) k = left;
        if(right < elemNum && array[right].priority > array[k].priority) k = right;
        if(k != index) {
            std::swap(array[index], array[k]);
            heapifyDown(k);
        }
    }

    void heapifyUp(int index) {
        if(index <= 0) {
            return;
        }
        int parent = (index - 1) / 2;
        if(array[parent].priority < array[index].priority) {
            std::swap(array[index], array[parent]);
            heapifyUp(parent);
        }
    }

    void expandArray() {
        arraySize = arraySize * 2;
        QueueElement* temp = new QueueElement[arraySize];
        for(int i = 0; i < elemNum; i++) {
            temp[i] = array[i];
        }

        delete[] array;
        array = temp;
        return;
    }

    void shrinkArray() {
        arraySize = arraySize / 2;
        QueueElement* temp = new QueueElement[arraySize];
        for(int i = 0; i < elemNum; i++) {
            temp[i] = array[i];
        }

        delete[] array;
        array = temp;
    }


public:
    PriorityQueue(int defaultArraySize = 4) {
        arraySize = defaultArraySize;
        elemNum = 0;
        array = new QueueElement[arraySize];
    }

    ~PriorityQueue() {
        delete[] array;
    }

    void insert(T object, int priority) {
        if(elemNum == arraySize) {
            expandArray();
        }
        array[elemNum] = QueueElement(object, priority);
        elemNum++;
        heapifyUp(elemNum - 1);
    }

    QueueElement max() {
        if(elemNum == 0) {
            throw std::invalid_argument("Queue is empty");
        }
        return array[0];
    }

    QueueElement extractMax() {
        if(elemNum == 0) {
            throw std::invalid_argument("Queue is empty");
        }
        
        QueueElement element = array[0];
        array[0] = array[elemNum - 1];
        elemNum--;
        heapifyDown(0);
        loadFactor = static_cast<float>(elemNum) / static_cast<float>(arraySize);
        if(loadFactor < 0.25 && arraySize > 4) {
            shrinkArray();
        }
        return element;
    }
};