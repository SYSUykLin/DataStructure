//
// Created by root on 2018/10/10.
//

#ifndef DATA_STRUCTURE_INDEXHEAP_H
#define DATA_STRUCTURE_INDEXHEAP_H

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>

template<typename item>
class IndexHeap {
private:
    item *indexes;
    item *data;
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
            swap(indexes[k / 2], indexes[k]);
            k /= 2;
        }
    }

    void shitDown(int k) {
        while (2 * k <= count) {
            int change = 2 * k;
            if (change + 1 <= count && data[indexes[change]] < data[indexes[change + 1]]) {
                change++;
            }
            if (data[indexes[change]] <= data[indexes[k]]) {
                break;
            }
            swap(indexes[change], indexes[k]);
            k = change;
        }
    }

public:
    IndexHeap(int capacity) {
        indexes = new int[capacity + 1];
        data = new item[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }

    ~IndexHeap() {
        delete[] data;
        delete[] indexes;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(int i, item itemNumber) {
        assert(count + 1 <= capacity);
        assert(i + 1 >= 1 && i + 1 < capacity);
        i++;
        data[i] = itemNumber;
        indexes[++count] = i;
        shiftUp(count);
    }

    item extractMax(){
        item num = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        count -- ;
        shitDown(1);
        return num;
    }

    void change(int i, item itemNumber){
        i += 1;
        data[i] = itemNumber;
        for (int j = 1; j <= count; ++j) {
            if (indexes[j] == i){
                shiftUp(j);
                shitDown(j);
                return;
            }
        }
    }
};

#endif //DATA_STRUCTURE_INDEXHEAP_H
