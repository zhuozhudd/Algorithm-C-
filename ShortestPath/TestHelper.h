/**
 *  Created by zhuozhu on 2022/4/29 20:47.
 *  Description: TestHelper.h
 */
//

#ifndef SHORTESTPATH_TESTHELPER_H
#define SHORTESTPATH_TESTHELPER_H

#include <iostream>
#include "SparseGraph.h"
#include "Dijkstra.h"
#include "ReadGraph.h"
#include "BellmanFord.h"

using namespace std;

void test_dijkstra();

void test_bellmanFord();

void test_bellmanFord() {
    string filename = "../testG2.txt";
    //string filename = "../testG_negative_circle.txt";
    int V = 5;

    SparseGraph<int> g = SparseGraph<int>(V, true);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout << "Test Bellman-Ford:" << endl << endl;

    int s = 0;
    BellmanFord<SparseGraph<int>, int> bellmanFord(g, s);
    if (bellmanFord.negativeCycle())
        cout << "The graph contain negative cycle!" << endl;
    else
        for (int i = 0; i < V; i++) {
            if (i == s)
                continue;

            if (bellmanFord.hasPathTo(i)) {
                cout << "Shortest Path to " << i << " : " << bellmanFord.shortestPathTo(i) << endl;
                bellmanFord.showPath(i);
            } else
                cout << "No Path to " << i << endl;

            cout << "----------" << endl;
        }
}

void test_dijkstra() {
    string filename = "../testG1.txt";
    int V = 5;

    SparseGraph<int> g = SparseGraph<int>(V, true);
    // Dijkstra最短路径算法同样适用于有向图
    //SparseGraph<int> g = SparseGraph<int>(V, false);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout << "Test Dijkstra:" << endl << endl;
    Dijkstra<SparseGraph<int>, int> dij(g, 0);
    for (int i = 0; i < V; i++) {
        if (dij.hasPathTo(i)) {
            cout << "Shortest Path to " << i << " : " << dij.shortestPathTo(i) << endl;
            dij.showPath(i);
        } else
            cout << "No Path to " << i << endl;

        cout << "----------" << endl;
    }
}

#endif //SHORTESTPATH_TESTHELPER_H
