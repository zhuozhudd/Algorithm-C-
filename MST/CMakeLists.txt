cmake_minimum_required(VERSION 3.21)
project(MST)

set(CMAKE_CXX_STANDARD 17)

add_executable(MST main.cpp DenseGraph.h SparseGraph.h Edge.h ReadGraph.h TestHelper.h MinHeap.h LazyPrimMST.h IndexMinHeap.h PrimMST.h UnionFind.h KruskalMST.h)
