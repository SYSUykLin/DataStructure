//
// Created by root on 2018/10/19.
//

#ifndef DATA_STRUCTURE_COMPONENT_H
#define DATA_STRUCTURE_COMPONENT_H

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template<typename Graph>
class Component {
private:
    int *id;
    Graph &G;
    bool *visited;
    int Ccount;

    void dfs(int v) {
        visited[v] = true;
        id[v] = Ccount;
        cout << v << " ";
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

public:
    Component(Graph &graph) : G(graph) {
        visited = new bool[G.V()];
        id = new int[G.V()];
        Ccount = 0;
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            id[i] = -1;
        }
        for (int i = 0; i < G.V(); ++i) {
            if (!visited[i]) {
                dfs(i);
                Ccount++;
            }
        }
    }

    int count() {
        return Ccount;
    }

    bool isConnected(int v, int w) {
        return id[v] == id[w];
    }

    ~Component() {
        delete[] visited;
    }


};

#endif //DATA_STRUCTURE_COMPONENT_H
