//
// Created by root on 2018/9/30.
//

#ifndef DATA_STRUCTURE_SORTTESTHELPER_H
#define DATA_STRUCTURE_SORTTESTHELPER_H

#include <cstring>
#include <ctime>
#include <iostream>
#include <cassert>

using namespace std;


namespace SortTestHelper {

    template<typename T>
    bool isSorted(T arr[], int n);

    struct student {
        string name;
        float score;

        bool operator<(const student &otherStudent) {
            return score < otherStudent.score;
        }

        friend ostream &operator<<(ostream &os, const student &otherStudent) {
            os << "Student: " << otherStudent.name << " " << otherStudent.score << endl;
            return os;
        }
    };

    //generate a array of n elements, range [rangL, rangeR]
    int *generateRandomArray(int n, int rangL, int rangeR) {
        assert(rangeR >= rangL);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (rangeR - rangL + 1) + rangL;
        }
        return arr;
    }

    template<typename T>
    void showArray(T arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << ": " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        return;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    template<typename T>
    T *CopyArray(T arr[], int n) {
        T *copy = new T[n];
        for (int i = 0; i < n; i++) {
            copy[i] = arr[i];
        }
        return copy;
    }
}
#endif //DATA_STRUCTURE_SORTTESTHELPER_H
