/**
 *  Created by zhuozhu on 2022/4/28 10:47.
 *  Description: PrimMST.h
 */
//

#ifndef MST_PRIMMST_H
#define MST_PRIMMST_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

template<typename Graph, typename Weight>
class PrimMST { // O(ElogV)
private:
    Graph &G;
    IndexMinHeap<Weight> ipq; // 存储和每个节点相邻的可选横切边的权值
    vector<Edge<Weight> *> edgeTo; // 存储和每个节点相邻的的横切边
    bool *marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visit(int v) {
        assert(!marked[v]);
        marked[v] = true;
        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
            int w = e->other(v); // 得到与v相连接的节点w
            if (!marked[w]) { // v标记，w未标记
                if (edgeTo[w] == nullptr) { // 之前没有找到和w连接的横切边
                    ipq.insert(w, e->wt());
                    edgeTo[w] = e;
                } else if (e->wt() < edgeTo[w]->wt()) {
                    // 更新横切边
                    edgeTo[w] = e;
                    ipq.change(w, e->wt());
                }
            }
        }
    }

public:
    PrimMST(Graph &graph) : G(graph), ipq(IndexMinHeap<double>(graph.V())) {
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            marked[i] = false;
            edgeTo.push_back(nullptr);
        }
        mst.clear();

        // Prim
        visit(0);
        while (!ipq.isEmpty()) {
            int v = ipq.extractMinIndex();
            assert(edgeTo[v]);
            mst.push_back(*edgeTo[v]);
            visit(v);
        }

        mstWeight = mst[0].wt();
        for (int i = 1; i < mst.size(); ++i)
            mstWeight += mst[i].wt();
    }

    ~PrimMST() {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }
};


#endif //MST_PRIMMST_H
