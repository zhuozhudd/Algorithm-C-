/**
 *  Created by zhuozhu on 2022/4/26 18:49.
 *  Description: Edge.h
 */
//

#ifndef MST_EDGE_H
#define MST_EDGE_H

#include <iostream>

using namespace std;

template<typename Weight>
class Edge {
private:
    int a, b;
    Weight weight;
public:
    Edge(int a, int b, Weight weight) : a(a), b(b), weight(weight) {

    }

    Edge() {}

    ~Edge() {}

    int v() { return a; }

    int w() { return b; }

    Weight wt() { return weight; }

    // 已知边的一个点，求另一个点
    int other(int x) {
        assert(x == a || x == b);
        return x == a ? b : a;
    }

    friend ostream &operator<<(ostream &os, const Edge &e) {
        os << e.a << "-" << e.b << " " << e.weight;
        return os;
    }

    bool operator<(Edge<Weight> &e) {
        return weight < e.wt();
    }

    bool operator<=(Edge<Weight> &e) {
        return weight <= e.wt();
    }

    bool operator>(Edge<Weight> &e) {
        return weight > e.wt();
    }

    bool operator>=(Edge<Weight> &e) {
        return weight >= e.wt();
    }

    bool operator==(Edge<Weight> &e) {
        return weight == e.wt();
    }

};


#endif //MST_EDGE_H
