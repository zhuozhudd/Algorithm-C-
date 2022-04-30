/**
 *  Created by zhuozhu on 2022/4/26 10:05.
 *  Description: BFS_Path.h
 */
//

#ifndef GRAPHTHEORY_BFS_SHORTPATH_H
#define GRAPHTHEORY_BFS_SHORTPATH_H


#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 广度优先遍历可以求出无权图的最短路径

template<typename Graph>
class BFS_ShortPath {
private:
    Graph &G;
    int s;
    bool *visited;
    int *from;
    int *ord;
public:
    BFS_ShortPath(Graph &graph, int s) : G(graph), s(s) {
        assert(s >= 0 && s < graph.V());
        visited = new bool[graph.V()];
        from = new int[graph.V()];
        ord = new int[graph.V()];
        for (int i = 0; i < graph.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }

        queue<int> q;
        q.push(s);
        visited[s] = true;
        ord[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            typename Graph::adjIterator adj(G, v);
            for (int i = adj.begin(); !adj.end(); i = adj.next()) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    ord[i] = ord[v] + 1;
                }
            }

        }

    }

    ~BFS_ShortPath() {
        delete[] visited;
        delete[] from;
        delete[] ord;
    }

    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec) {
        assert(w >= 0 && w < G.V());
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

    int pathLength(int w) {
        assert(w >= 0 && w < G.V());
        return ord[w];
    }
};

#endif //GRAPHTHEORY_BFS_SHORTPATH_H
