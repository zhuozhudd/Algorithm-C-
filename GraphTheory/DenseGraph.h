/**
 *  Created by zhuozhu on 2022/4/25 19:07.
 *  Description: DenseGraph.h
 */
//

#ifndef GRAPHTHEORY_DENSEGRAPH_H
#define GRAPHTHEORY_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稠密图 - 邻接矩阵 - 自动剔除平行边
class DenseGraph {
private:
    int n; // 顶点个数
    int m; // 边数
    bool directed; // 是否为有向图
    vector<vector<bool>> g;
public:
    DenseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<bool>(n, false));
        }
    }

    ~DenseGraph() {}

    int V() { return n; }

    int E() { return m; }

    void addEdge(int v, int w) {
        assert(v >= 0 && v <= n);
        assert(w >= 0 && w < n);
        if (hasEdge(v, w))
            return;
        g[v][w] = true;
        if (!directed)
            g[w][v] = true;
        m++;
    }

    // 判断v和w之间是否存在连接边
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v <= n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }

    void show() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << g[i][j] << "\t";
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

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            index++;
            for (; index < G.V(); ++index) {
                if (G.g[v][index] == true)
                    return index;
            }
            return -1;
        }

        bool end() {
            return index >= G.V();
        }
    };

};

#endif //GRAPHTHEORY_DENSEGRAPH_H
