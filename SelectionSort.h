//
// Created by root on 2018/9/30.
//

#ifndef DATA_STRUCTURE_SELECTIONSORT_H
#define DATA_STRUCTURE_SELECTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void SelectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

#endif //DATA_STRUCTURE_SELECTIONSORT_H
