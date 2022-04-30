cmake_minimum_required(VERSION 3.21)
project(ShortestPath)

set(CMAKE_CXX_STANDARD 17)

add_executable(ShortestPath main.cpp DenseGraph.h Edge.h IndexMinHeap.h ReadGraph.h SparseGraph.h Dijkstra.h TestHelper.h BellmanFord.h)
