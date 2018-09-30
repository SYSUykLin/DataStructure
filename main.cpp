#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include <cstring>
using namespace std;

int main() {
    int n = 10000, rangL = 0, rangR = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, rangL, rangR);
    int *arr1 = SortTestHelper::CopyArray(arr, n);
    int *arr2 = SortTestHelper::CopyArray(arr, n);
    SortTestHelper::testSort("SelectionSort", SelectionSort, arr, n);
    SortTestHelper::testSort("InsertionSort", InsertionSort, arr1, n);
    SortTestHelper::testSort("InsertionSort_version2", InsertionSort_version2, arr2, n);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
 }