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
            id = new int[n];
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

namespace UF_version2 {
    class unionFind {
    private:
        int *parent;
        int *sz;
        int count;
    public:
        explicit unionFind(int n) {
            parent = new int[n];
            sz = new int[n];
            count = n;
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                sz[i] = 1;
            }
        }

        ~unionFind() {
            delete[] parent;
        }

        int find(int p) {
            assert(p >= 0 && p <= count);
            while (parent[p] != p) {
                p = parent[p];
            }
            return p;
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot) {
                return;
            }
            if (sz[pRoot] < sz[pRoot]){
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            } else{
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }
    };
}
#endif //DATA_STRUCTURE_UNIONFIND_H
