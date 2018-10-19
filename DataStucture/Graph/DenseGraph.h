//
// Created by root on 2018/10/17.
//

#ifndef DATA_STRUCTURE_DENSEGRAPH_H
#define DATA_STRUCTURE_DENSEGRAPH_H

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <vector>

using namespace std;
namespace Matrix {
    class DenseGraph {
    private:
        int n, m;
        bool directed;
        vector<vector<bool>> g;
    public:
        DenseGraph(int n, bool directed) {
            this->n = n;
            this->m = 0;
            this->directed = directed;
            for (int i = 0; i < n; ++i) {
                g.emplace_back(vector<bool>(n, false));
            }
        }

        ~DenseGraph() = default;

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
            g[v][w] = true;
            if (!this->directed) {
                g[w][v] = true;
            }
            this->m++;
        }

        bool haveEdge(int v, int w) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);
            return g[v][w];
        }

        void show(){
            for (int i = 0; i < g.size(); ++i) {
                for (int j = 0; j < g[i].size(); ++j) {
                    cout << g[i][j] << " ";
                }
                cout << endl;
            }
        }

        class adjIterator {
        private:
            DenseGraph &G;
            int v;
            int index;
        public:
            adjIterator(DenseGraph &graph, int v) : G(graph) {
                this->v = v;
                this->index = -1;
            }

            int begin() {
                index = -1;
                return next();
            }

            int next() {
                for (index += 1; index < G.V(); index++) {
                    if (G.g[v][index]) {
                        return index;
                    }
                }
                return -1;
            }

            bool end() {
                return index >= G.V();
            }
        };
    };
}
#endif //DATA_STRUCTURE_DENSEGRAPH_H
