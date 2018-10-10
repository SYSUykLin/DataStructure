//
// Created by root on 2018/10/10.
//

#ifndef DATA_STRUCTURE_INDEXHEAP_H
#define DATA_STRUCTURE_INDEXHEAP_H

template<typename item>
class IndexHeap {
private:
    item *indexes;
    item *data;
    int count;
    int capacity;
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
};

#endif //DATA_STRUCTURE_INDEXHEAP_H
