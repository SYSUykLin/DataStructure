//
// Created by root on 2018/10/17.
//

#ifndef DATA_STRUCTURE_SPARSE_H
#define DATA_STRUCTURE_SPARSE_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "Edge.h"

using namespace std;
namespace Sparse {
    template<typename Weight>
    class SparseGraph {
    private:
        int n, m;
        bool directed;
        vector<vector<Edge<Weight> *>> g;
    public:
        void show() {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < g[i].size(); ++j) {
                    cout << g[i][j]->wt() << " ";
                }
                cout << endl;
            }
        }
        SparseGraph(int n, bool directed) {
            this->n = n;
            this->directed = directed;
            this->m = 0;
            for (int i = 0; i < n; ++i) {
                g.emplace_back(vector<Edge<Weight> *>());
            }
        }

        ~SparseGraph() {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < g[i].size(); ++j) {
                    delete g[i][j];
                }
            }
        }

        int V() {
            return n;
        }

        int E() {
            return m;
        }

        void addEdge(int v, int w, Weight weight) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);
            if (haveEdge(v, w)) {
                return;
            }
            g[v].emplace_back(new Edge<Weight>(v, w, weight));
            if (v != w && !this->directed) {
                g[w].emplace_back(new Edge<Weight>(w, v, weight));
            }
            this->m++;
        }

        bool haveEdge(int v, int w) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);
            for (auto var : g[v]) {
                if (var->Other(v) == w) {
                    return true;
                }
            }
            return false;
        }

        //interator
        class adjIterator {
        private:
            SparseGraph &G;
            int v;
            int index;
        public:


            adjIterator(SparseGraph &graph, int v) : G(graph) {
                assert(v < graph.n);
                this->v = v;
                this->index = 0;
            }

            Edge<Weight>* begin() {
                if (!G.g[v].empty()) {
                    return G.g[v][this->index];
                }
                return NULL;
            }

            Edge<Weight>* next() {
                index++;
                if (index < G.g[v].size()) {
                    return G.g[v][index];
                }
                return NULL;
            }

            bool end() {
                return index >= G.g[v].size();
            }
        };
    };
}
#endif //DATA_STRUCTURE_SPARSE_H
