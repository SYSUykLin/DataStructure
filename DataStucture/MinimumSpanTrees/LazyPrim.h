//
// Created by root on 2018/10/24.
//

#ifndef DATA_STRUCTURE_LAZYPRIM_H
#define DATA_STRUCTURE_LAZYPRIM_H

#include <cassert>
#include <iostream>
#include <algorithm>
#include "../Heap/MinHeap.h"
#include "../UnionFind/UnionFind.h"
#include "Edge.h"
#include <vector>

using namespace std;
namespace MinimumSpanTree_Prim {
    template<typename Graph, typename Weight>
    class Prim {
    private:
        Graph &G;
        MinHeap<Edge<Weight>> pq;
        bool *marked;
        vector<Edge<Weight>> MinimumEdge;
        Weight mstWeight;

        void visit(int v){
            assert( !marked[v] );
            marked[v] = true;
            typename Graph::adjIterator adj(G, v);
            for (Edge<Weight> *e = adj.begin(); !adj.end() ; e = adj.next()) {
                if (!marked[e->Other(v)]){
                    pq.insert(*e);
                }
            }
        }
    public:
        Prim(Graph &graph) : G(graph), pq(MinHeap<Edge<Weight>>(G.E())){
            marked = new bool[ G.V() ];
            for (int i = 0; i < G.V(); ++i) {
                marked[i] = false;
            }
            MinimumEdge.clear();

            visit(0);
            while (!pq.isEmpty()){
                Edge<Weight> e = pq.extractMin();
                if (marked[e.v()] == marked[e.w()]){
                    continue;
                }
                MinimumEdge.push_back(e);
                if (!marked[e.v()]){
                    visit(e.v());
                } else{
                    visit(e.w());
                }
            }

            mstWeight = MinimumEdge[0].wt();
            for (int j = 1; j < MinimumEdge.size(); ++j) {
                mstWeight += MinimumEdge[j].wt();
            }
        }

        ~Prim(){
            delete [] marked;
        }

        vector<Edge<Weight>> mstEdges(){
            return MinimumEdge;
        }

        Weight result(){
            return mstWeight;
        }
    };
}
#endif //DATA_STRUCTURE_LAZYPRIM_H
