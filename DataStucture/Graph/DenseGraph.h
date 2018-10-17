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
namespace Matrix{
    class DenseGraph{
    private:
        int n, m;
        bool directed;
        vector<vector<bool>> g;
    public:
        DenseGraph(int n, bool directed){
            this->n = n;
            this->m = m;
            this->directed = directed;
            for (int i = 0; i < n; ++i) {
                g.emplace_back(vector<bool>(n, false));
            }
        }
        ~DenseGraph(){

        }
        int V(){
            return n;
        }
        int E(){
            return m;
        }
    };
}
#endif //DATA_STRUCTURE_DENSEGRAPH_H
