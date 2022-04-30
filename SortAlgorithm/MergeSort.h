/**
 *  Created by zhuozhu on 2022/4/17 10:58 PM.
 *  Description: MergeSort.h
 */
//

#ifndef SORTALGORITHM_MERGESORT_H
#define SORTALGORITHM_MERGESORT_H

#include <iostream>
#include "InsertSort.h"

using namespace std;

// 将arr[l...mid]和arr[mid+1,...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T aux[r - l + 1];
    for (int i = l; i <= r; ++i)
        aux[i - l] = arr[i]; // 注意i - l偏移量

    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }
}


// 递归使用归并排序，对arr[l...r]对范围内进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {
//    if (l >= r)
//        return;
//  对上述代码进行优化，当数组近乎有序时，采用InsertSort
    if (r - l <= 15) {
        insertSort(arr, l, r);
        return;
    }


    int mid = l + (r - l) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);

    // 优化，如果arr[mid] <= arr[mid+1]就不需要合并
    if (arr[mid] > arr[mid + 1])
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}


#endif //SORTALGORITHM_MERGESORT_H
