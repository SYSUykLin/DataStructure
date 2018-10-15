//
// Created by root on 2018/10/15.
//

#ifndef DATA_STRUCTURE_UNIONFIND_H
#define DATA_STRUCTURE_UNIONFIND_H

#include <iostream>
#include <algorithm>
#include <cassert>

namespace UF_version1 {
    class unionFind {
    private:
        int *id;
        int count;
    public:
        explicit unionFind(int n) {
            count = n;
            id = new int(n);
            for (int i = 0; i < n; ++i) {
                id[i] = i;
            }
        }

        ~unionFind() {
            delete[] id;
        }

        int find(int p) {
            assert(p >= 0 && p <= count);
            return id[p];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pID = find(p);
            int qID = find(q);
            if (pID == qID) {
                return;
            }
            for (int i = 0; i < count; ++i) {
                if (id[i] == pID) {
                    id[i] = qID;
                }
            }
        }
    };
}
#endif //DATA_STRUCTURE_UNIONFIND_H
