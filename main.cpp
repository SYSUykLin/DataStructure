#include <iostream>
#include "SortAlgorithm/SortTestHelper.h"
#include "SortAlgorithm/SelectionSort.h"
#include "SortAlgorithm/InsertionSort.h"
#include "SortAlgorithm/MergeSort.h"
#include <cstring>
#include "SortAlgorithm/QuickSort.h"
#include "DataStucture/MaxHeap.h"
#include <ctime>
using namespace std;

int main() {
    int n = 1000000, rangL = 0, rangR = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, rangL, rangR);
    int *arr1 = SortTestHelper::CopyArray(arr, n);
    int *arr2 = SortTestHelper::CopyArray(arr, n);
    int *arr3 = SortTestHelper::CopyArray(arr, n);
    int *arr4 = SortTestHelper::CopyArray(arr, n);
    int *arr5 = SortTestHelper::CopyArray(arr, n);
    MaxHeap<int> heap = MaxHeap<int>(100);
    for (int i = 0; i < 15; ++i){
        time(NULL);
        heap.insert(rand()%100);
    }
    for (int j = 0; j < 15; ++j) {
        cout << heap.pop() << " ";
    }
    cout<<endl;
    cout << heap.size() << endl;

//    SortTestHelper::testSort("SelectionSort", SelectionSort, arr, n);
//    SortTestHelper::testSort("InsertionSort", InsertionSort, arr1, n);
//    SortTestHelper::testSort("InsertionSort_version2", InsertionSort_version2, arr2, n);
    SortTestHelper::testSort("MergeSort", MergeSort, arr3, n);
    SortTestHelper::testSort("upMergeSort", upMergeSort, arr4, n);
    SortTestHelper::testSort("QuickSort", QuickSort, arr5, n);
    delete[] arr4;
    delete[] arr3;
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
 }