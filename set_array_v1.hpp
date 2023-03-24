#pragma once

#include <iostream>

template <typename T>
class Set {
    int arraySize;
    int elemNum;
    float loadFactor;
    T* array;
public:
    Set(int defaultArraySize = 4) {
        arraySize = defaultArraySize;
        elemNum = 0;
        array = new T[arraySize];
    }

    ~Set() {
        delete[] array;
    }

    void resizeArray() {
        // scaling up the array
        if(elemNum == arraySize) {
            arraySize = arraySize * 2;
            T* temp = new T[arraySize];
            for(int i = 0; i < elemNum; i++) {
                temp[i] = array[i];
            }

            delete[] array;
            array = temp;
            return;
        }

        // scaling down the array
        loadFactor = static_cast<float>(elemNum) / static_cast<float>(arraySize);
        if(loadFactor < 0.25) {
            arraySize = arraySize / 2;
            T* temp = new T[arraySize];
            for(int i = 0; i < elemNum; i++) {
                temp[i] = array[i];
            }

            delete[] array;
            array = temp;
        }
    }

    int binarySearchNearest(T x) {
        int low = 0;
        int high = elemNum - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(array[mid] < x) {
                low = mid + 1;
            }
            else if(array[mid] > x) {
                high = mid - 1;
            }
            else {
                return mid;
            }
        }
        return high + 1;
    }
    
    void insert(T x) {
        int index = binarySearchNearest(x);
        if(elemNum == 0) {
            array[0] = x;
        }
        else if(index == elemNum) {
            array[elemNum] = x;
        }
        else if(array[index] == x) {
            return;
        }
        else {
            for(int i = index; i <= elemNum; i++) {
                T temp = array[i];
                array[i] = x;
                x = temp;
            }
        }
        elemNum++;

        resizeArray();
    }

    bool remove(T x) {
        if(elemNum == 0) {
            return false;
        }

        int index = binarySearchNearest(x);
        if(index == elemNum) {
            return false;
        }
        else if(array[index] == x) {
            for(int i = index; i <= elemNum; i++) {
                array[i] = array[i + 1];
            }
            elemNum--;
            resizeArray();
            return true;
        }
        else {
            return false;
        }
    }

    T pop(T x) {
        if(elemNum == 0) {
            throw std::invalid_argument("Provided element wasn't found");
        }

        int index = binarySearchNearest(x);
        if(index == elemNum) {
            throw std::invalid_argument("Provided element wasn't found");
        }
        if(array[index] == x) {
            for(int i = index; i <= elemNum; i++) {
                array[i] = array[i + 1];
            }
            elemNum--;
            resizeArray();
            return x;
        }
        else {
            throw std::invalid_argument("Provided element wasn't found");
        }
    }

    T pop() {
        if(elemNum > 0) {
            T x = array[elemNum - 1];
            array[elemNum - 1] = array[elemNum];
            elemNum--;
            resizeArray();
            return x;
        }
        else {
            throw std::invalid_argument("Provided element wasn't found");
        }
    }

    int size() {
        return elemNum;
    }

    bool isMember(T x) {
        if(elemNum == 0) {
            return false;
        }

        int index = binarySearchNearest(x);
        if(index == elemNum) {
            return false;
        }
        else if(array[index] == x) {
            return true;
        }
    }

    void printSet() {
        for(int i = 0; i < elemNum; i++) {
            std::cout << array[i] << std::endl;
        }
    }

    Set setUnion(Set<T>& x) {
        Set<T> newSet(elemNum + x.elemNum);
        int i = 0, j = 0;

        while(i < elemNum && j < x.elemNum) {
            if(array[i] > x.array[j]) {
                newSet.array[newSet.elemNum++] = x.array[j];
                j++;
            }
            else if(array[i] == x.array[j]) {
                newSet.array[newSet.elemNum++] = x.array[j];
                i++;
                j++;
            }
            else {
                newSet.array[newSet.elemNum++] = array[i];
                i++;
            }
        }
        while(i < elemNum) {
            newSet.array[newSet.elemNum++] = array[i];
            i++;
        }
        while(j < x.elemNum) {
            newSet.array[newSet.elemNum++] = x.array[j];
            j++;
        }

        newSet.resizeArray();
        return newSet;
    }

    Set setDifference(Set<T>& x) {
        Set<T> newSet(elemNum);
        int i = 0, j = 0;
        
        while(i < elemNum && j < x.elemNum) {
            if(array[i] > x.array[j]) {
                j++;
            }
            else if(array[i] == x.array[j]) {
                i++;
                j++;
            }
            else {
                newSet.array[newSet.elemNum++] = array[i];
                i++;
            }
        }
        while(i < elemNum) {
            newSet.array[newSet.elemNum++] = array[i];
            i++;
        }

        newSet.resizeArray();
        return newSet;
    }

    Set setIntersection(Set<T>& x) {
        Set<T> newSet(elemNum + x.elemNum);
        int i = 0, j = 0;

        while(i < elemNum && j < x.elemNum) {
            if(array[i] > x.array[j]) {
                j++;
            }
            else if(array[i] == x.array[j]) {
                newSet.array[newSet.elemNum++] = x.array[j];
                i++;
                j++;
            }
            else {
                i++;
            }
        }

        newSet.resizeArray();
        return newSet;
    }
};