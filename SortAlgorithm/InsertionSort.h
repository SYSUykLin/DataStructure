//
// Created by root on 2018/9/30.
//

#ifndef DATA_STRUCTURE_INSERTIONSORT_H
#define DATA_STRUCTURE_INSERTIONSORT_H

#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;
template<typename T>
void InsertionSort(T arr[], int n){
    for (int i = 1; i < n; i ++){
        for (int j = i; j > 0; j --){
            if (arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            } else
                break;
        }
    }
}
template<typename T>
void InsertionSort_version2(T arr[], int n){
    for (int i = 1; i < n; i ++){
        T temp = arr[i];
        int j = 0;
        for (j = i; j > 0 && arr[j-1] > temp; j --){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}
#endif //DATA_STRUCTURE_INSERTIONSORT_H
