/**
 *  Created by zhuozhu on 2022/4/26 09:21.
 *  Description: DFS_Path.h
 */
//

#ifndef GRAPHTHEORY_DFS_PATH_H
#define GRAPHTHEORY_DFS_PATH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

template<typename Graph>
class DFS_Path {
private:
    Graph &G;
    int s;
    bool *visited;
    int *from;

    void dfs(int v) {
        visited[v] = true;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (visited[i] == false) {
                from[i] = v;
                dfs(i);
            }

        }
    }

public:
    DFS_Path(Graph &graph, int s) : G(graph), s(s) {
        assert(s >= 0 && s < G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
        }
        // 寻路算法
        dfs(s);
    }

    ~DFS_Path() {
        delete[] visited;
        delete[] from;
    }

    // s到w是否存在路径
    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    // s到w的具体路径
    void path(int w, vector<int> &vec) {
        stack<int> st;
        int p = w;
        while (p != -1) {
            st.push(p);
            p = from[p];
        }
        vec.clear();
        while (!st.empty()) {
            vec.push_back(st.top());
            st.pop();
        }
    }

    // 打印s到w的路径
    void showPath(int w) {
        assert(w >= 0 && w < G.V());
        vector<int> vec;
        path(w, vec);
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i == vec.size() - 1)
                cout << endl;
            else cout << "->";
        }
    }


};


#endif //GRAPHTHEORY_DFS_PATH_H
