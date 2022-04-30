cmake_minimum_required(VERSION 3.21)
project(GraphTheory)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphTheory main.cpp DenseGraph.h SparsGraph.h TestHelper.h ReadGraph.h GetComponent.h DFS_Path.h BFS_ShortPath.h)
