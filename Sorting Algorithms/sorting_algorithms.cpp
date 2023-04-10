#include "sorting_algorithms.hpp"

using namespace std;

void swap(long int* i,long int* j) {
    int tmp = *i;
    *j = *i;
    *i = tmp;
}

void copyData(vector<int>& data, vector<int>& dataCopy) {
    for(int i = 0; i<data.size(); i++) {
        dataCopy[i] = data[i];
    }
}
// ******************************************************
void maxHeap(vector<int>& data, int size, int i) {
    int k = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && data[left] > data[k]) k = left;
    if(right < size && data[right] > data[k]) k = right;
    if(k != i) {
        swap(data[i], data[k]);
        maxHeap(data, size, k);
    }

}

void heapSort(vector<int>& data, int size) {
    for(int i = size / 2 - 1; i >= 0; i--) {
        maxHeap(data, size, i);
    }

    for(int i = size - 1; i>0; i--) {
        swap(data[0], data[i]);
        maxHeap(data, i, 0);
    }
}

int partitionHoare(vector<int>& data, int left, int right) {
    int i = left - 1;
    int j = right + 1;
    int pivot = data[(left+right)/2];

    while(1) {
        while(data[++i] < pivot);
        while(data[--j] > pivot);

        if(i >= j) return j;
        swap(data[i], data[j]);
    }
}
void quickSort(vector<int>& data, int left, int right) {
    if(left >= 0 && right >= 0 && left < right) {
        int p = partitionHoare(data, left, right);
        quickSort(data, left, p);
        quickSort(data, p + 1, right);
    }
}

void insertionSort(vector<int>& data) {
    int j;
    for(int i = 1; i<data.size(); i++) {
        j = i;
        while(j>0 && data[j] < data[j-1]) {
            swap(data[j], data[j-1]);
            j -= 1;
        }
    }
}
void selectionSort(vector<int>& data) {
    for(int i = 0; i<data.size()-1; i++) {
        int min = i;
        for(int j = i+1; j<data.size(); j++) {
            if(data[j] < data[min]) min = j;
        }
        if(min != i) {
            swap(data[i], data[min]);
        }
    }
}

void merge(vector<int>& data, int left, int right, int mid) { 
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    for(int i = 0; i<size1; i++) {
        arr1[i] = data[left + i];
    }
    for(int i = 0; i<size2; i++) {
        arr2[i] = data[mid + i + 1];
    }
    
    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    while(i < size1 && j < size2) {
        if(arr1[i] <= arr2[j]) {
            data[k] = arr1[i];
            i++;
        }
        else {
            data[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < size1) {
        data[k] = arr1[i];
        i++;
        k++;
    }
    while(j < size2) {
        data[k] = arr2[j];
        j++;
        k++;
    }
    delete[] arr1;
    delete[] arr2;
}

void mergeSort(vector<int>& data, int left, int right) {
    if(left >= right) return;

    int mid = left + (right - left)/2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);

    merge(data, left, right, mid);
}

void bubbleSort(vector<int>& data) {
    int temp;
    int size = data.size();
    for(int i = 0; i<size-1; i++) {
        for(int j = 0; j<size-i-1; j++) {
            if(data[j] > data[j+1]) {
                temp = data[j+1];
                data[j+1] = data[j];
                data[j] = temp;
            }
        }
    }
}