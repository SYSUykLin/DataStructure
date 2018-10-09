//
// Created by root on 2018/10/7.
//

#ifndef DATA_STRUCTURE_MAXHEAP_H
#define DATA_STRUCTURE_MAXHEAP_H

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cassert>

using namespace std;

template<typename item>
class MaxHeap {
private:
    item *data;
    int count = 0;
    int capacity = 0;

    void shiftUp(int index) {
        while (index > 1 && data[index / 2] < data[index]) {
            swap(data[index / 2], data[index]);
            index /= 2;
        }
    }

    void shiftDown(int index) {
        while (2 * index <= count) {
            int change = 2 * index;
            if (change + 1 < count && data[change + 1] > data[change]) {
                change++;
            }
            if (data[change] <= data[index]) {
                break;
            }
            swap(data[change], data[index]);
            index = change;
        }
    }

public:
    MaxHeap(int capacity) {
        data = new item[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }

    ~MaxHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(item number) {
        assert(count + 1 <= capacity);
        data[count + 1] = number;
        count++;
        shiftUp(count);
    }

    item pop() {
        assert(count > 0);
        item target = data[1];
        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return target;
    }

    void heapify(item arr[]){
        data = arr;

    }

};

#endif //DATA_STRUCTURE_MAXHEAP_H
