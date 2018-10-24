//
// Created by root on 2018/10/22.
//

#ifndef DATA_STRUCTURE_EDGE_H
#define DATA_STRUCTURE_EDGE_H

#include <iostream>
#include <cassert>
using namespace std;

template<typename Weight>
class Edge {
private:
    int a, b;
    Weight weight;
public:
    Edge() {}

    Edge(int a, int b, Weight weight) {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    ~Edge() = default;

    Weight wt(){
        return weight;
    }

    int Other(int v) {
        assert(v == a || v == b);
        return v == a ? b : a;
    }

    int v(){ return a;}
    int w(){ return b;}

    friend ostream& operator<<(ostream &os, const Edge &e){
        os << e.a << "->" << e.b << " : " << e.weight;
        return os;
    }

    bool operator<(Edge<Weight>& e){
        return weight < e.wt();
    }

    bool operator<=(Edge<Weight>& e){
        return weight <= e.wt();
    }

    bool operator>(Edge<Weight>& e){
        return weight > e.wt();
    }

    bool operator>=(Edge<Weight>& e){
        return weight >= e.wt();
    }

    bool operator==(Edge<Weight>& e){
        return weight == e.wt();
    }
};

#endif //DATA_STRUCTURE_EDGE_H
