#include <iostream>
#include <vector>
#include <ctime>
#include "sorting_algorithms.hpp"

using namespace std;

int main() {
    int n = 10000;
    clock_t start, end;

    double time1[10], time2[10], time3[10], time4[10], time5[10], time6[10];

    for(int i = 0; i<10; i++) {

        vector<int> data(n);
        vector<int> dataCopy(n);
        // filling up data vector with random numbers
        for(int j = 0; j<data.size(); j++) {
            data[j] = rand() % n;
        }
        copyData(data, dataCopy);

        // 1. Bubble sort
        // *************
        start = clock();
        bubbleSort(dataCopy);
        end = clock();
        time1[i] = static_cast<double>(end - start);
        copyData(data, dataCopy);
        // *************

        // 2. Selection sort
        // *************
        start = clock();
        selectionSort(dataCopy);
        end = clock();
        time2[i] = static_cast<double>(end - start);
        copyData(data, dataCopy);
        // *************

        // 3. Insertion sort
        // *************
        start = clock();
        insertionSort(dataCopy);
        end = clock();
        time3[i] = static_cast<double>(end - start);
        copyData(data, dataCopy);
        // *************

        // 4. Merge sort
        // *************
        start = clock();
        mergeSort(dataCopy, 0, dataCopy.size()-1);
        end = clock();
        time4[i] = static_cast<double>(end - start);
        copyData(data, dataCopy);
        // *************

        // 5. Quicksort
        // *************
        start = clock();
        quickSort(dataCopy, 0, dataCopy.size()-1);
        end = clock();
        time5[i] = static_cast<double>(end - start);
        copyData(data, dataCopy);
        // *************

        // 6. Heap sort
        // *************
        start = clock();
        heapSort(dataCopy, dataCopy.size()-1);
        end = clock();
        time6[i] = static_cast<double>(end - start);
        // *************

        cout<<n<<", "
        <<static_cast<long int>(time1[i])<<", "
        <<static_cast<long int>(time2[i])<<", "
        <<static_cast<long int>(time3[i])<<", "
        <<static_cast<long int>(time4[i])<<", "
        <<static_cast<long int>(time5[i])<<", "
        <<static_cast<long int>(time6[i])<<endl;

        n += 10000;
    }

    return 0;
}