//
// Created by root on 2018/10/19.
//

#ifndef DATA_STRUCTURE_READGRAPH_H
#define DATA_STRUCTURE_READGRAPH_H

#include <iostream>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <fstream>

using namespace std;
template <typename Graph>
class ReadGraph{
public:
    ReadGraph(Graph &graph, const string &filename){
        ifstream file(filename);
        string line;
        int V, E;
        assert(file.is_open());
        assert(getline(file, line));
        stringstream ss(line);
        ss >> V >> E;
        assert(V == graph.V());
        for (int i = 0; i < E; ++i) {
            assert(getline(file, line));
            stringstream ss(line);
            int a, b;
            ss >> a >> b;
            graph.addEdge(a, b);
        }
    }
};
#endif //DATA_STRUCTURE_READGRAPH_H
