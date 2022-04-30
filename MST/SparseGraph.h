/**
 *  Created by zhuozhu on 2022/4/26 18:48.
 *  Description: SparseGraph.h
 */
//

#ifndef MST_SPARSEGRAPH_H
#define MST_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

// 稀疏图 - 邻接表 - 存在平行边
template<typename Weight>
class SparseGraph {
private:
    int n; // 顶点个数
    int m; // 边数
    bool directed; // 是否为有向图
    vector<vector<Edge<Weight> * >> g;
public:
    SparseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<Edge<Weight> *>());
        }
    }

    ~SparseGraph() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                delete g[i][j];
            }
        }
    }

    int V() { return n; }

    int E() { return m; }

    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v <= n);
        assert(w >= 0 && w < n);

        g[v].push_back(new Edge(v, w, weight));
        if (!directed && v != w) // 剔除自环边
            g[w].push_back(new Edge<Weight>(w, v, weight));
        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v <= n);
        assert(w >= 0 && w < n);
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i]->other() == w)
                return true;
        }
        return false;
    }

    void show() {
        for (int i = 0; i < n; ++i) {
            cout << "Vertex " << i << ":\t";
            for (int j = 0; j < g[i].size(); ++j)
                cout << "( to: " << g[i][j]->w() << ", wt:" << g[i][j]->wt() << ")\t";
            cout << endl;
        }
    }

    class adjIterator {
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparseGraph &graph, int v) : G(graph), v(v), index(0) {}

        Edge<Weight> *begin() {
            index = 0;
            if (G.g[v].size())
                return G.g[v][index];
            return nullptr;
        }

        Edge<Weight> *next() {
            index++;
            if (index < G.g[v].size())
                return G.g[v][index];
            return nullptr;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };
};

#endif //MST_SPARSEGRAPH_H
