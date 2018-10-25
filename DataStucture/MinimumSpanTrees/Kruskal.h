//
// Created by root on 2018/10/24.
//

#ifndef DATA_STRUCTURE_KRUSKAL_H
#define DATA_STRUCTURE_KRUSKAL_H

#include "Edge.h"
#include <iostream>
#include <algorithm>
#include <cassert>
#include "../UnionFind/UnionFind.h"
#include <vector>
#include "../Heap/MinHeap.h"
using namespace std;
namespace MinimumSpanTree_Kruskal{
    template <typename Graph, typename Weight>
    class Kruskal{
    private:
        vector<Edge<Weight>> mst;
        Weight mstWeight;
    public:
        Kruskal(Graph &graph){
            MinHeap<Edge<Weight>> pg(graph.E());
            for (int i = 0; i < graph.V(); ++i) {
                typename Graph :: adjIterator adj(graph, i);
                for (Edge<Weight> *e = adj.begin(); !adj.end() ; e = adj.next()) {
                    if (e->v() < e->w()){
                        pg.insert(*e);
                    }
                }
            }
            UF_version3::unionFind unionFind(graph.E());
            while (!pg.isEmpty() && mst.size() < graph.V() - 1){
                Edge<Weight> e = pg.extractMin();
                if (unionFind.isConnected(e.v(), e.w())){
                    continue;
                }
                mst.push_back(e);
                unionFind.unionElements(e.v(), e.w());
            }
            mstWeight =mst[0].wt();
            for (int j = 1; j < mst.size(); ++j) {
                mstWeight += mst[j].wt();
            }
        }

        vector<Edge<Weight>> mstEdges(){
            return mst;
        }

        Weight result(){
            return mstWeight;
        }
    };
}
#endif //DATA_STRUCTURE_KRUSKAL_H
