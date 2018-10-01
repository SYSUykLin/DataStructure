//
// Created by root on 2018/10/1.
//

#ifndef DATA_STRUCTURE_MERGESORT_H
#define DATA_STRUCTURE_MERGESORT_H

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T *temp = new T[r - l + 1];
    for (int i = l; i <= r; i++) {
        temp[i - l] = arr[i];
    }
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = temp[j - l];
            j++;
        } else if (j > r) {
            arr[k] = temp[i - l];
            i++;
        } else if (temp[i - l] < temp[j - l]) {
            arr[k] = temp[i - l];
            i++;
        } else {
            arr[k] = temp[j - l];
            j++;
        }
    }
    delete[] temp;
}

template<typename T>
void __mergeSort(T arr, int l, int r) {
    if (l >= r) {
        return;
    } else {
        int mid = (l + r) / 2;
        __mergeSort(arr, l, mid);
        __mergeSort(arr, mid + 1, r);
        if (arr[mid] > arr[mid + 1]) {
            __merge(arr, l, mid, r);
        }
    }
}

template<typename T>
void MergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}

template<typename T>
void upMergeSort(T arr[], int n){
    for (int sz = 1; sz <= n; sz = sz + sz){
        for (int i = 0; i + sz < n; i += sz + sz){
            __merge(arr, i, i+sz-1, min(i+sz+sz-1, n-1));
        }
    }
}

#endif //DATA_STRUCTURE_MERGESORT_H
