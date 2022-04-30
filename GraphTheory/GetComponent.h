/**
 *  Created by zhuozhu on 2022/4/25 20:50.
 *  Description: GetComponent.h
 */
//

#ifndef GRAPHTHEORY_GETCOMPONENT_H
#define GRAPHTHEORY_GETCOMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;

template<typename Graph>
class Component {
private:
    Graph &G;
    bool *visited;
    int componentCnt;
    int *id;

    void dfs(int v) {
        visited[v] = true;
        id[v] = componentCnt;
        // 由于编译器无法确定adjIterator是Graph中的类型还是成员变量
        // 需要添加typename标知符
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i])
                dfs(i);
        }
    }

public:
    Component(Graph &graph) : G(graph) {
        visited = new bool[G.V()];
        id = new int[G.V()];
        componentCnt = 0;
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            id[i] = -1;
        }
        for (int i = 0; i < G.V(); ++i) {
            if (!visited[i]) {
                dfs(i);
                componentCnt++;
            }
        }
    }

    int count() {
        return componentCnt;
    }

    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return id[v] == id[w];
    }

    ~Component() {
        delete[] visited;
        delete[] id;
    }
};

#endif //GRAPHTHEORY_GETCOMPONENT_H
