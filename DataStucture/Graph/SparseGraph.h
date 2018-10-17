//
// Created by root on 2018/10/17.
//

#ifndef DATA_STRUCTURE_SPARSEGRAPH_H
#define DATA_STRUCTURE_SPARSEGRAPH_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;
namespace list {
    class SparseGraph {
    private:
        int n, m;
        bool directed;
        vector<vector<int>> g;
    public:
        SparseGraph(int n, bool directed) {
            this->n = n;
            this->directed = directed;
            this->m = 0;
            for (int i = 0; i < n; ++i) {
                g.emplace_back(vector<int>());
            }
        }

        ~SparseGraph() = default;

        int V() {
            return n;
        }

        int E() {
            return m;
        }

        void addEdge(int v, int w) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);
            if (haveEdge(v, w)) {
                return;
            }
            g[v].emplace_back(w);
            if (v != w && !this->directed) {
                g[w].emplace_back(v);
            }
            this->m++;
        }

        bool haveEdge(int v, int w) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);
            for (auto var : g[v]) {
                if (var == w) {
                    return true;
                }
            }
            return false;
        }
    };
}
#endif //DATA_STRUCTURE_SPARSEGRAPH_H
