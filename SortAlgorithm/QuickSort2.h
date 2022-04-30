/**
 *  Created by zhuozhu on 2022/4/18 10:29 PM.
 *  Description: QuickSort2.h
 */
//

#ifndef SORTALGORITHM_QUICKSORT2_H
#define SORTALGORITHM_QUICKSORT2_H

#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "InsertSort.h"

using namespace std;

template<typename T>
int __partition2(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];

    // arr[l+1...i] <= v ; arr[j...r] >= v
    int i = l + 1, j = r;
    while (true) {
        while (i <= r && arr[i] < v) i++;
        while (j >= l && arr[j] > v) j--;
        if (i > j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[l], arr[j]);
    return j;

}

template<typename T>
void __quickSort2(T arr[], int l, int r) {
    if (r - l <= 15) {
        insertSort(arr, l, r);
        return;
    }
    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p - 1);
    __quickSort2(arr, p + 1, r);
}

template<typename T>
void quickSort2
(T arr[], int n) {
    srand(time(nullptr));
    __quickSort2(arr, 0, n - 1);
}

#endif //SORTALGORITHM_QUICKSORT2_H
