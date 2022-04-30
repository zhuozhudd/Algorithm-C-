/**
 *  Created by zhuozhu on 2022/4/18 10:43 AM.
 *  Description: MergeSortB2U.h
 */
//

#ifndef SORTALGORITHM_MERGESORTB2U_H
#define SORTALGORITHM_MERGESORTB2U_H

#include <iostream>

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

// 自底向上归并排序，迭代
template<typename T>
void mergeSortB2U(T arr[], int n) {
    for (int sz = 1; sz <= n; sz += sz)
        for (int i = 0; i + sz < n; i += sz + sz)
            // 对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行归并排序
            __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
    // 自底向上速度没有自顶向下快，但由于没有使用数组对下标索引，所以此方法可以对链表进行排序，这是此方法对优势
}


#endif //SORTALGORITHM_MERGESORTB2U_H
