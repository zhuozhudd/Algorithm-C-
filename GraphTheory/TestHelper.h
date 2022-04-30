/**
 *  Created by zhuozhu on 2022/4/25 19:43.
 *  Description: TestHelper.h
 */
//

#ifndef GRAPHTHEORY_TESTHELPER_H
#define GRAPHTHEORY_TESTHELPER_H

#include <iostream>
#include "DenseGraph.h"
#include "SparsGraph.h"
#include "ReadGraph.h"
#include "GetComponent.h"
#include "DFS_Path.h"
#include "BFS_ShortPath.h"

using namespace std;

void test_sparse_graph(int N, int M);

void test_dense_graph(int N, int M);

void test_read_graph(int n);

void test_get_component();

void test_show_DFS_path(int v, int w);

void test_show_BFS_showPath(int v, int w);

void test_show_BFS_showPath(int v, int w) {
    string filename = "../testG2.txt";
    SparsGraph sg = SparsGraph(7, false);
    ReadGraph<SparsGraph> readGraph(sg, filename);
    sg.show();
    cout << endl;
    BFS_ShortPath<SparsGraph> bfs(sg, v);
    cout << "bfs: ";
    bfs.showPath(w);
}

void test_show_DFS_path(int v, int w) {
    string filename = "../testG2.txt";
    SparsGraph sg = SparsGraph(7, false);
    ReadGraph<SparsGraph> readGraph(sg, filename);
    sg.show();
    cout << endl;
    DFS_Path<SparsGraph> dfs(sg, v);
    cout << "DFS: ";
    dfs.showPath(w);

}

void test_get_component() {
    string filename1 = "../testG1.txt";
    SparsGraph sg1(13, false);
    ReadGraph<SparsGraph> readGraph1(sg1, filename1);
    Component<SparsGraph> component1(sg1);
    cout << "TestG1.txt, Component Count :" << component1.count() << endl;
    cout << "Vertex 1 与 Vertex 2 是否相连：" << component1.isConnected(1, 2) << endl;

    string filename2 = "../testG2.txt";
    SparsGraph sg2(7, false);
    ReadGraph<SparsGraph> readGraph2(sg2, filename2);
    Component<SparsGraph> component2(sg2);
    cout << "TestG2.txt, Component Count :" << component2.count() << endl;

    cout << "Vertex 1 与 Vertex 2 是否相连：" << component2.isConnected(1, 2) << endl;

}

void test_read_graph(int n) {
    string filename = "../testG1.txt";
    SparsGraph sg(n, false);
    ReadGraph<SparsGraph> readGraph1(sg, filename);
    sg.show();

    DenseGraph dg(n, false);
    ReadGraph<DenseGraph> readGraph2(dg, filename);
    dg.show();
}

void test_sparse_graph(int N, int M) {
    srand(time(nullptr));
    SparsGraph g1(N, false);
    for (int i = 0; i < M; ++i) {
        int a = rand() % N;
        int b = rand() % N;
        g1.addEdge(a, b);
    }

    for (int v = 0; v < N; ++v) {
        cout << v << ": ";
        SparsGraph::adjIterator adj(g1, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }
    cout << endl;
}

void test_dense_graph(int N, int M) {
    srand(time(nullptr));
    SparsGraph g1(N, false);
    for (int i = 0; i < M; ++i) {
        int a = rand() % N;
        int b = rand() % N;
        g1.addEdge(a, b);
    }

    for (int v = 0; v < N; ++v) {
        cout << v << ": ";
        SparsGraph::adjIterator adj(g1, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }
    cout << endl;
}

#endif //GRAPHTHEORY_TESTHELPER_H
