cmake_minimum_required(VERSION 3.21)
project(BinarySearch)

set(CMAKE_CXX_STANDARD 14)

add_executable(BinarySearch main.cpp BinarySearch.h BinarySearchTree.h FileOps.h SequenceST.h TestSearch.h)
