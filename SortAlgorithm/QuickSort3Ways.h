/**
 *  Created by zhuozhu on 2022/4/18 10:52 PM.
 *  Description: QuickSort3Ways.h
 */
//

#ifndef SORTALGORITHM_QUICKSORT3WAYS_H
#define SORTALGORITHM_QUICKSORT3WAYS_H


#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "InsertSort.h"

using namespace std;

// 三路快速排序处理 arr[l...r]
// 将 arr[l...r] 分为 <v; ==v; >v 三部分
//  之后递归对 <v 和 >v 两部分继续进行三路快速排序
template<typename T>
void __quickSort3Ways(T arr[], int l, int r) {
    if (r - l <= 15) {
        insertSort(arr, l, r);
        return;
    }

    // partition

    // 随机化处理
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];

    int lt = l; // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt..r] > v
    int i = l + 1; // arr[lt+1..i) == v 前闭后开

    while (i < gt) {
        if (arr[i] < v) {
            swap(arr[i], arr[lt + 1]);
            lt++;
            i++;
        } else if (arr[i] > v) {
            swap(arr[i], arr[gt - 1]);
            gt--;
        } else { // arr[i] == v
            i++;
        }
    }
    swap(arr[l], arr[lt]);
    __quickSort3Ways(arr, l, lt - 1);
    __quickSort3Ways(arr, gt, r);
}

template<typename T>
void quickSort3Ways(T arr[], int n) {
    srand(time(nullptr));
    __quickSort3Ways(arr, 0, n - 1);
}


#endif //SORTALGORITHM_QUICKSORT3WAYS_H
