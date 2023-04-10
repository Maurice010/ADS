#include <vector>

void swap(long int* i,long int* j);
void copyData(std::vector<int>& data, std::vector<int>& dataCopy);

void maxHeap(std::vector<int>& data, int size, int i);
void heapSort(std::vector<int>& data, int size);

int partitionHoare(std::vector<int>& data, int left, int right);
void quickSort(std::vector<int>& data, int left, int right);

void insertionSort(std::vector<int>& data);
void selectionSort(std::vector<int>& data);

void merge(std::vector<int>& data, int left, int right, int mid);
void mergeSort(std::vector<int>& data, int left, int right);

void bubbleSort(std::vector<int>& data);