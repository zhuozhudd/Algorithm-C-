/**
 *  Created by zhuozhu on 2022/4/29 20:26.
 *  Description: Dijkstra.h
 */
//

#ifndef SHORTESTPATH_DIJKSTRA_H
#define SHORTESTPATH_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

template<typename Graph, typename Weight>
class Dijkstra {
private:
    Graph &G;
    int s;
    Weight *distTo;
    bool *marked;
    vector<Edge<Weight> *> from;
public:
    Dijkstra(Graph &graph, int s) : G(graph), s(s) {
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(nullptr);
        }
        IndexMinHeap<Weight> ipq(G.V());

        // Dijkstra
        distTo[s] = Weight(); // 默认为0
        marked[s] = true;
        from[s] = new Edge<Weight>(s, s, Weight());
        ipq.insert(s, distTo[s]);
        while (!ipq.isEmpty()) {
            int v = ipq.extractMinIndex();
            // distTo[v]是s到v的最短距离
            marked[v] = true;


            typename Graph::adjIterator adj(G, v);
            for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                int w = e->other(v);
                if (!marked[w]) { // 松弛操作 Relaxation
                    // 如果w点以前没有访问过, 或者访问过, 但是通过当前的v点到w点距离更短, 则进行更新
                    if (from[w] == nullptr || distTo[v] + e->wt() < distTo[w]) {
                        distTo[w] = distTo[v] + e->wt();
                        from[w] = e;
                        if (ipq.contain(w))
                            ipq.change(w, distTo[w]);
                        else
                            ipq.insert(w, distTo[w]);
                    }
                }
            }
        }
    }

    ~Dijkstra() {
        delete[] distTo;
        delete[] marked;
        delete from[0];
    }

    // s到达w最短路径权值
    Weight shortestPathTo(int w) {
        return distTo[w];
    }

    bool hasPathTo(int w) {
        return marked[w];
    }

    // 寻找从s到w的最短路径, 将整个路径经过的边存放在vec中
    void shortestPath( int w, vector<Edge<Weight>> &vec ){

        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) );

        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while( e->v() != this->s ){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }
    void showPath(int w) {
        assert(w >= 0 && w < G.V());
        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i].v() << "->";
            if (i == vec.size() - 1)
                cout << vec[i].w() << endl;
        }
    }
};


#endif //SHORTESTPATH_DIJKSTRA_H
