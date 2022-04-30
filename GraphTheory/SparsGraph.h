/**
 *  Created by zhuozhu on 2022/4/25 19:08.
 *  Description: SparsGraph.h
 */
//

#ifndef GRAPHTHEORY_SPARSGRAPH_H
#define GRAPHTHEORY_SPARSGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稀疏图 - 邻接表 - 存在平行边
class SparsGraph {
private:
    int n; // 顶点个数
    int m; // 边数
    bool directed; // 是否为有向图
    vector<vector<int>> g;
public:
    SparsGraph(int n, bool directed) : n(n), m(0), directed(directed) {
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<int>());
        }
    }

    ~SparsGraph() {}

    int V() { return n; }

    int E() { return m; }

    void addEdge(int v, int w) {
        assert(v >= 0 && v <= n);
        assert(w >= 0 && w < n);

        g[v].push_back(w);
        if (!directed && v != w) // 剔除自环边
            g[w].push_back(v);
        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v <= n);
        assert(w >= 0 && w < n);
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] == w)
                return true;
        }
        return false;
    }

    void show() {
        for (int i = 0; i < n; ++i) {
            cout << "Vertex " << i << "\t";
            for (int j = 0; j < g[i].size(); ++j)
                cout << g[i][j] << "\t";
            cout << endl;
        }
    }

    class adjIterator {
    private:
        SparsGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparsGraph &graph, int v) : G(graph), v(v), index(0) {}

        int begin() {
            index = 0;
            if (G.g[v].size())
                return G.g[v][index];
            return -1;
        }

        int next() {
            index++;
            if (index < G.g[v].size())
                return G.g[v][index];
            return -1;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };
};

#endif //GRAPHTHEORY_SPARSGRAPH_H
