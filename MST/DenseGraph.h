/**
 *  Created by zhuozhu on 2022/4/26 18:47.
 *  Description: DenseGraph.h
 */
//

#ifndef MST_DENSEGRAPH_H
#define MST_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

// 稠密图 - 邻接矩阵 - 带权图
template<typename Weight>
class DenseGraph {
private:
    int n; // 顶点个数
    int m; // 边数
    bool directed; // 是否为有向图
    vector<vector<Edge<Weight> * >> g;
public:
    DenseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<Edge<Weight> *>(n, nullptr));
        }
    }

    ~DenseGraph() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] != nullptr)
                    delete g[i][j];
            }
        }
    }

    int V() { return n; }

    int E() { return m; }


    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v <= n);
        assert(w >= 0 && w < n);

        if (hasEdge(v, w)) {
            // 处理重复边
            delete g[v][w];
            if (!directed) // 无向图删除反向边
                delete g[w][v];
            m--;
        }

        g[v][w] = new Edge<Weight>(v, w, weight);
        if (!directed)
            g[w][v] = new Edge<Weight>(v, w, weight);
        m++;
    }

    // 判断v和w之间是否存在连接边
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v <= n);
        assert(w >= 0 && w < n);
        return g[v][w] != nullptr;
    }

    void show() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                if (g[i][j])
                    cout << g[i][j]->wt() << "\t";
                else
                    cout << "NULL\t";
            cout << endl;
        }


    }

    class adjIterator {
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(DenseGraph &graph, int v) : G(graph), v(v), index(-1) {}

        Edge<Weight> *begin() {
            index = -1;
            return next();
        }

        Edge<Weight> *next() {
            index++;
            for (; index < G.V(); ++index) {
                if (G.g[v][index] == true)
                    return G.g[v][index];
            }
            return nullptr;
        }

        bool end() {
            return index >= G.V();
        }
    };

};

#endif //MST_DENSEGRAPH_H
