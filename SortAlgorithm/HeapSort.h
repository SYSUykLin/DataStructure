//
// Created by root on 2018/10/7.
//

#ifndef DATA_STRUCTURE_HEAPSORT_H
#define DATA_STRUCTURE_HEAPSORT_H

#include <iostream>
#include <algorithm>
#include "../DataStucture/Heap/MaxHeap.h"

using namespace std;

template<typename T>
void __shiftDown(T arr[], int n, int i) {
    while (2 * i + 1 < n) {
        int change = 2 * i + 1;
        if (change + 1 < n && arr[change] < arr[change + 1]) {
            change++;
        }
        if (arr[i] >= arr[change]) {
            break;
        }
        swap(arr[i], arr[change]);
        i = change;
    }
}

template<typename T>
void HeapSort_version1(T arr[], int n) {
    MaxHeap<T> heap = MaxHeap<T>(arr, n);
    for (int j = n - 1; j >= 0; --j) {
        arr[j] = heap.pop();
    }
}

template<typename T>
void HeapSort_version2(T arr[], int n) {
    //heapify,create a max heap;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        __shiftDown(arr, n, i);
    }
    for (int j = n - 1; j > 0; --j) {
        swap(arr[0], arr[j]);
        __shiftDown(arr, j, 0);
    }
}

#endif //DATA_STRUCTURE_HEAPSORT_H
