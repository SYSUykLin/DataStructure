//
// Created by root on 2018/10/19.
//

#ifndef DATA_STRUCTURE_BFS_H
#define DATA_STRUCTURE_BFS_H

#include <queue>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;
template <typename Graph>
class bfs{
private:
    Graph &G;
    int s;
    bool *visited;
    int *from;
    int *ord;
public:
    bfs(Graph &graph, int s): G(graph){
        assert(s >= 0 && s < graph.V());
        from = new int[graph.V()];
        ord = new int[graph.V()];
        visited = new bool[graph.V()];
        for (int i = 0; i < graph.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }
        this->s = s;
        queue<int> q;
        q.push(s);
        ord[s] = 0;
        visited[s] = true;
        while (!q.empty()){
            int w = q.front();
            cout << w << " ";
            q.pop();
            typename Graph::adjIterator adj(graph, w);
            for (int i = adj.begin(); !adj.end(); i = adj.next()) {
                if (!visited[i] ){
                    q.push(i);
                    visited[i] = true;
                    from[i] = w;
                    ord[i] = ord[w] + 1;
                }
            }
        }
    }

    void showShortPath(int w){
        stack<int> s;
        if (visited[w]){
            int p = w;
            while (p != -1){
                s.push(p);
                p = from[p];
            }
        }
        vector<int> vec;
        while (!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
        for (auto v: vec) {
            cout << v << " ";
        }
        cout << endl;
    }
};

#endif //DATA_STRUCTURE_BFS_H
