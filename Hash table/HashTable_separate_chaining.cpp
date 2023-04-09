#include <iostream>
#include <list>

using namespace std;

#define ARRAY_SIZE 10000

class HashTableChaining {
private:
    list<unsigned int>* array;

    int hashFunction(unsigned int key) {
        return key % ARRAY_SIZE;
    }
public:
    HashTableChaining() {
        array = new list<unsigned int>[ARRAY_SIZE];
    }

    ~HashTableChaining() {
        delete[] array;
    }

    void insert(unsigned int key) {
        array[hashFunction(key)].push_back(key);
    }

    bool find(unsigned int key) {
        int bucketIndex = hashFunction(key);
        for(list<unsigned int>::iterator it = array[bucketIndex].begin(); it != array[bucketIndex].end(); it++) {
            if(*it == key)
                return true;
        }
        return false;
    }

    bool remove(unsigned int key) {
        int bucketIndex = hashFunction(key);
        for(list<unsigned int>::iterator it = array[bucketIndex].begin(); it != array[bucketIndex].end(); it++) {
            if(*it == key) {
                array[hashFunction(key)].erase(it);
                return true;
            }
        }
        return false;
    }
};