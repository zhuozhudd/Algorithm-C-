/**
 *  Created by zhuozhu on 2022/4/18 2:40 PM.
 *  Description: QuickSort.h
 */
//

#ifndef SORTALGORITHM_QUICKSORT1_H
#define SORTALGORITHM_QUICKSORT1_H

#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "InsertSort.h"


using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template<typename T>
int __partition1(T arr[], int l, int r) {

    // 优化, 使用随机化当方法选取标定元素，可以提高在近乎有序数组中排序的效率
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];

    // arr[l+1...j] < v ; arr[j+1...i) v
    int j = l;
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] < v)
            swap(arr[++j], arr[i]);
    }
    swap(arr[l], arr[j]);
    return j;
}


// 对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort1(T arr[], int l, int r) {
//    if (l >= r)
//        return;
    // 优化方法，当区间元素个数在16个内，采用InsertSort
    if (r - l <= 15) {
        insertSort(arr, l, r);
        return;
    }

    int p = __partition1(arr, l, r);
    __quickSort1(arr, l, p - 1);
    __quickSort1(arr, p + 1, r);
}

template<typename T>
void quickSort1(T arr[], int n) {
    srand(time(nullptr));
    __quickSort1(arr, 0, n - 1);
}

#endif //SORTALGORITHM_QUICKSORT1_H
