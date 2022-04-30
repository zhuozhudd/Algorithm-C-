/**
 *  Created by zhuozhu on 2022/4/26 20:19.
 *  Description: TestHelper.h
 */
//

#ifndef MST_TESTHELPER_H
#define MST_TESTHELPER_H

#include <iostream>
#include <string>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"

using namespace std;

void test_edge();

void test_lazyPrim();

void test_Prim();

void test_performance();

void test_kruskalMST();

void test_kruskalMST() {
    cout << "Test Kauskal MST:" << endl;
    string filename = "../testG1.txt";
    int V = 8;
    SparseGraph<double> sg = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(sg, filename);
    KruskalMST<SparseGraph<double>, double> kruskal(sg);
    vector<Edge<double>> mst = kruskal.mstEdges();
    for (int i = 0; i < mst.size(); ++i)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << kruskal.result() << endl;

}


void test_Prim() {
    cout << "Test Prim MST:" << endl;
    string filename = "../testG1.txt";
    int V = 8;
    SparseGraph<double> sg = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(sg, filename);
    PrimMST<SparseGraph<double>, double> primMST(sg);
    vector<Edge<double>> mst = primMST.mstEdges();
    for (int i = 0; i < mst.size(); ++i)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << primMST.result() << endl;

}

void test_lazyPrim() {
    string filename = "../testG1.txt";
    int V = 8;
    SparseGraph<double> sg = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(sg, filename);
    cout << "Test Lazy Prim MST:" << endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(sg);
    vector<Edge<double>> mst = lazyPrimMST.mstEdges();
    for (int i = 0; i < mst.size(); ++i)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << lazyPrimMST.result() << endl;
}

void test_edge() {
    string filename = "../testG1.txt";
    int V = 8;
    cout << fixed << setprecision(2);
    cout << "Test Weighted Dense Graph:" << endl;
    DenseGraph<double> dg = DenseGraph<double>(V, false);
    ReadGraph<DenseGraph<double>, double> readGraph(dg, filename);
    dg.show();
    cout << endl << endl;

    cout << "Test Weighted Sparse Graph:" << endl;
    SparseGraph<double> sg = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(sg, filename);
    sg.show();

}

void test_performance() {
    string filename1 = "../testG1.txt";
    int V1 = 8;

    string filename2 = "../testG2.txt";
    int V2 = 250;

    string filename3 = "../testG3.txt";
    int V3 = 1000;

    string filename4 = "../testG4.txt";
    int V4 = 10000;

    // 读取文件
    SparseGraph<double> g1 = SparseGraph<double>(V1, false);
    ReadGraph<SparseGraph<double>, double> readGraph1(g1, filename1);
    cout << filename1 << " load successfully." << endl;

    SparseGraph<double> g2 = SparseGraph<double>(V2, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename2);
    cout << filename2 << " load successfully." << endl;

    SparseGraph<double> g3 = SparseGraph<double>(V3, false);
    ReadGraph<SparseGraph<double>, double> readGraph3(g3, filename3);
    cout << filename3 << " load successfully." << endl;

    SparseGraph<double> g4 = SparseGraph<double>(V4, false);
    ReadGraph<SparseGraph<double>, double> readGraph4(g4, filename4);
    cout << filename4 << " load successfully." << endl;

    cout << endl;


    clock_t startTime, endTime;

    // Test Lazy Prim MST
    cout << "Test Lazy Prim MST:" << endl;

    startTime = clock();
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST1(g1);
    endTime = clock();
    cout << "Test for G1: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    startTime = clock();
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST2(g2);
    endTime = clock();
    cout << "Test for G2: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    startTime = clock();
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST3(g3);
    endTime = clock();
    cout << "Test for G3: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    startTime = clock();
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST4(g4);
    endTime = clock();
    cout << "Test for G4: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    cout << endl;


    // Test Prim MST
    cout << "Test Prim MST:" << endl;

    startTime = clock();
    PrimMST<SparseGraph<double>, double> PrimMST1(g1);
    endTime = clock();
    cout << "Test for G1: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    startTime = clock();
    PrimMST<SparseGraph<double>, double> PrimMST2(g2);
    endTime = clock();
    cout << "Test for G2: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    startTime = clock();
    PrimMST<SparseGraph<double>, double> PrimMST3(g3);
    endTime = clock();
    cout << "Test for G3: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    startTime = clock();
    PrimMST<SparseGraph<double>, double> PrimMST4(g4);
    endTime = clock();
    cout << "Test for G4: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    cout << endl;


    // Test Kruskal MST
    cout << "Test Kruskal MST:" << endl;

    startTime = clock();
    KruskalMST<SparseGraph<double>, double> KruskalMST1(g1);
    endTime = clock();
    cout << "Test for G1: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    startTime = clock();
    KruskalMST<SparseGraph<double>, double> KruskalMST2(g2);
    endTime = clock();
    cout << "Test for G2: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    startTime = clock();
    KruskalMST<SparseGraph<double>, double> KruskalMST3(g3);
    endTime = clock();
    cout << "Test for G3: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    startTime = clock();
    KruskalMST<SparseGraph<double>, double> KruskalMST4(g4);
    endTime = clock();
    cout << "Test for G4: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;


    cout << endl;

}

#endif //MST_TESTHELPER_H
