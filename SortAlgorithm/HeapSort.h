//
// Created by root on 2018/10/7.
//

#ifndef DATA_STRUCTURE_HEAPSORT_H
#define DATA_STRUCTURE_HEAPSORT_H

#include <iostream>
#include <algorithm>
#include "../DataStucture/MaxHeap.h"

using namespace std;
template<typename T>
void HeapSort_version1(T arr[], int n){
    MaxHeap<T> heap = MaxHeap<T>(arr, n);
    for (int j = n-1; j >= 0; --j) {
        arr[j] = heap.pop();
    }
}
#endif //DATA_STRUCTURE_HEAPSORT_H
