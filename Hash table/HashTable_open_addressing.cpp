#include <iostream>

using namespace std;

#define ARRAY_SIZE 100000
#define FREE -1
#define DELETED -2

class HashTableOpen {
private:
    int* array;

    int hashFunction(unsigned int key) {
        return key % ARRAY_SIZE;
    }
public:
    HashTableOpen() {
        array = new int[ARRAY_SIZE];
        for(int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = FREE;
        }
    }

    ~HashTableOpen() {
        delete[] array;
    }

    bool insert(unsigned int key) {
        int index = hashFunction(key);
        if(array[index] == FREE) {
            array[index] = key;
            return true;
        }

        int i = index;
        while(array[i] != FREE && array[i] != DELETED) {
            i = (i+1) % ARRAY_SIZE;
            if(i == index)
                return false;
        }
        array[i] = key;
        return true;
    }

    bool find(unsigned int key) {
        int index = hashFunction(key);
        int i = index;
        
        while(array[i] != FREE) {
            if(array[i] == key)
                return true;

            i = (i+1) % ARRAY_SIZE;
            if(i == index)
                return false;
        }
        return false;
    }

    bool remove(unsigned int key) {
        int index = hashFunction(key);
        int i = index;

        while(array[i] != FREE) {
            if(array[i] == key) {
                array[i] = DELETED;
                return true;
            }

            i = (i+1) % ARRAY_SIZE;
            if(i == index)
                return false;
        }
        return false;
    }
};