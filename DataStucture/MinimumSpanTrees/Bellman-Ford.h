//
// Created by root on 2018/10/26.
//

#ifndef DATA_STRUCTURE_BELLMAN_FORD_H
#define DATA_STRUCTURE_BELLMAN_FORD_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "Edge.h"
#include <stack>
using namespace std;
namespace Ford{
    template <typename Graph, typename Weight>
    class BellmanFord{
    private:
        Graph &G;
        int s;
        Weight* distTo;
        vector<Edge<Weight>*> from;
        bool hasNegativeCycle;
    public:

        bool detectNegativeCycle(){
            for (int i = 0; i < G.V(); ++i) {
                typename Graph::adjIterator adj(G, i);
                for (auto e = adj.begin(); !adj.end() ; e = adj.next()) {
                    if (!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()]){
                        return true;
                    }
                }
            }
            return false;
        }

        BellmanFord(Graph &graph, int s):G(graph){
            this->s = s;
            distTo = new Weight[G.V()];
            for (int i = 0; i < G.V(); ++i) {
                from.push_back(NULL);
            }

            distTo[s] = Weight();
            for (int pass = 1; pass < G.V(); ++pass) {
                for (int i = 0; i < G.V(); ++i) {
                    typename Graph::adjIterator adj(G, i);
                    for (auto e = adj.begin(); !adj.end() ; e = adj.next()) {
                        if (!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()]){
                            distTo[e->w()] = distTo[e->v()] + e->wt();
                            from[e->w()] = e;
                        }
                    }
                }
            }
            hasNegativeCycle = detectNegativeCycle();
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
    };
}
#endif //DATA_STRUCTURE_BELLMAN_FORD_H
