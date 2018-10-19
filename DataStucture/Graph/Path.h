//
// Created by root on 2018/10/19.
//

#ifndef DATA_STRUCTURE_PATH_H
#define DATA_STRUCTURE_PATH_H

#include <stack>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

template<typename Graph>
class Path {
private:
    bool *visited;
    int *from;
    Graph &G;
    int s;

    void dfs(int v) {
        visited[v] = true;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                from[i] = v;
                dfs(i);
            }
        }
    }

public:
    Path(Graph graph, int s) : G(graph) {
        assert(s >= 0 && s < G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;
        dfs(s);
    }

    ~Path() {
        delete[] from;
        delete[] visited;
    }

    void path(int w, vector<int> &vec) {
        stack<int> s;
        int p = w;
        while (p != -1) {
            s.push(p);
            p = from[p];
        }
        vec.clear();
        while (!s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }
    }

    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void showPath(int w) {
        vector<int> vec;
        path(w, vec);
        for (auto v: vec) {
            cout << v << " ";
        }
        cout << endl;
    }
};

#endif //DATA_STRUCTURE_PATH_H
