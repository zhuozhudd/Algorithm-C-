cmake_minimum_required(VERSION 3.21)
project(SortAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(SortAlgorithm main.cpp SortTestHelper.h InsertSort.h SelectSort.h MergeSort.h MergeSortB2U.h QuickSort1.h QuickSort2.h QuickSort3Ways.h Heap.h HeapSort.h IndexMaxHeap.h)
