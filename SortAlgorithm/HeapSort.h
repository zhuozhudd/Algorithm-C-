/**
 *  Created by zhuozhu on 2022/4/19 14:58.
 *  Description: HeapSort1.h
 */
//

#ifndef SORTALGORITHM_HEAPSORT_H
#define SORTALGORITHM_HEAPSORT_H

#include <iostream>
#include <algorithm>
#include "Heap.h"
#include "MergeSort.h"
#include "QuickSort2.h"
#include "SortTestHelper.h"

using namespace std;

// 原地堆排序
// parent(i) = (i-1)/2
// left child(i) = 2*i + 1
// right child(i) = 2*i + 2
// 最后一个非叶子节点 (count - 2) / 2

template<typename T>
void __shiftDown(T arr[], int n, int k){
    while(2*k+1 < n) { // left child 不越界，注意 < n
        int j = 2*k + 1;
        if (j + 1 < n && arr[j+1] > arr[j])
            j+=1;
        if (arr[k] >= arr[j]) // 满足大根堆，退出
            break;
        swap(arr[k], arr[j]);
        k = j; // 继续向下调整
    }
}

template<typename T>
void heapSort(T arr[], int n) {
    // heapify 构建堆
    // 在从0开始索引堆数组中，最后一个元素的索引值为 count-1
    // 所以最后一个非叶子节点的索引值为(count-1-1)/2 = (count-2)/2
    for (int i = (n - 2) / 2; i >= 0; --i)
        __shiftDown(arr, n, i);

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }

}

template<typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> max_heap = MaxHeap<T>(n);
    for (int i = 0; i < n; ++i)
        max_heap.insert(arr[i]);
    for (int i = n - 1; i >= 0; --i)
        arr[i] = max_heap.extractMax();
}

template<typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> max_heap = MaxHeap<T>(arr, n);
    for (int i = n - 1; i >= 0; --i)
        arr[i] = max_heap.extractMax();
}

#endif //SORTALGORITHM_HEAPSORT_H
