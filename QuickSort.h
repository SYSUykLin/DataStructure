//
// Created by root on 2018/10/2.
//

#ifndef DATA_STRUCTURE_QUICKSORT_H
#define DATA_STRUCTURE_QUICKSORT_H

#include <ctime>
#include <algorithm>
#include <iostream>
#include <cstring>

template<typename T>
int __partition_version3(T arr[], int l, int r){
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];
    int lt = l, gt = r+1, i = l+1;
    while (i < gt){
        if (arr[i] < v){
            swap(arr[i], arr[lt+1]);
            lt++;
            i++;
        } else if (arr[i] > v){
            swap(arr[i], arr[gt-1]);
            gt--;
        } else{
            i++;
        }
    }
    swap(arr[l], arr[lt]);
    return lt;
}

template<typename T>
int __partition_version2(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];
    int i = l+1, j = r;
    while (true){
        while (i <= r && arr[i] < v){
            i++;
        }
        while (j >= l+1 && arr[j] > v){
            j--;
        }
        if (i > j){
            break;
        } else{
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
int __partition(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < v) {
            swap(arr[j + 1], arr[i]);
            j++;
        }
    }
    swap(arr[j], arr[l]);
    return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int p = __partition_version3(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template<typename T>
void QuickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}

#endif //DATA_STRUCTURE_QUICKSORT_H
