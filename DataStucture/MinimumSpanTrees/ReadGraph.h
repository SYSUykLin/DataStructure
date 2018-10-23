//
// Created by root on 2018/10/19.
//

#ifndef DATA_STRUCTURE_READ_H
#define DATA_STRUCTURE_READ_H

#include <iostream>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <fstream>

using namespace std;
namespace Read {
    template<typename Graph, typename Weight>
    class ReadGraph {
    public:
        ReadGraph(Graph &graph, const string &filename) {
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
                Weight w;
                ss >> a >> b >> w;
                graph.addEdge(a, b, w);
            }
        }
    };
}
#endif //DATA_STRUCTURE_READ_H
