//
// Created by root on 2018/10/25.
//

#ifndef DATA_STRUCTURE_DIJKSTRA_H
#define DATA_STRUCTURE_DIJKSTRA_H

#include <iostream>
#include <cassert>
#include "Edge.h"
#include <vector>
#include <stack>
#include "../Heap/IndexMinHeap.h"
using namespace std;
template <typename Graph, typename Weight>
class Dijkstra{
private:
    Graph &G;
    int s;
    Weight *distTo;
    bool *marked;
    vector<Edge<Weight> *> from;
public:
    Dijkstra(Graph &graph, int s) : G(graph){
        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }
        IndexMinHeap<Weight> pq(G.V());
        distTo[s] = Weight();
        marked[s] = true;
        pq.insert(s, distTo[s]);
        while (!pq.isEmpty()){
            int v = pq.extractMinIndex();
            marked[v] = true;
            typename Graph :: adjIterator adj(G, v);
            for (auto e = adj.begin(); !adj.end(); e = adj.next()) {
                int w = e->Other(v);
                if (!marked[w]){
                    if (from[w] == NULL || distTo[v] + e->wt() < distTo[w] ){
                        distTo[w] = distTo[v] + e->wt();
                        from[w] = e;
                        if (pq.contain(w)){
                            pq.change(w, distTo[w]);
                        } else{
                            pq.insert(w, distTo[w]);
                        }
                    }
                }
            }
        }
    }

    void show(){
        stack<Edge<Weight> *> ss;
        for (int i = 1; i < G.V(); ++i) {
            vector<Edge<Weight>> vec;
            cout << i << " :" << endl;
            Edge<Weight> * e = from[i];
            while (e->v() != this->s){
                ss.push(e);
                e = from[e->v()];
            }
            ss.push(e);

            while( !ss.empty() ){
                e = ss.top();
                vec.push_back( *e );
                ss.pop();
            }

            for (int j = 0; j < vec.size(); ++j) {
                cout << vec[j].v() << " ";
                if( j == vec.size()-1 )
                    cout<<vec[j].w()<<endl;
            }
            //cout << distTo[i] << endl;
        }
    }

    ~Dijkstra(){
        delete [] distTo;
        delete [] marked;
    }
};
#endif //DATA_STRUCTURE_DIJKSTRA_H
