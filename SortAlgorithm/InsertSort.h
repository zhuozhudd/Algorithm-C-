/**
 * Created by zhuozhu on 2022/4/17 8:38 PM.
 * Description: Insert sort
 */
//

#ifndef SORTALGORITHM_INSERTSORT_H
#define SORTALGORITHM_INSERTSORT_H

#include <iostream>

using namespace std;

template<typename T>
void insertSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        // 寻找元素arr[i]合适的插入位置
        for (int j = i; j > 0; --j) {
            // 在前面操作
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else // 处于正确位置，终止此次循环，可以提前结束！
                break;
        }
    }
}

template<typename T>
void insertSortPro(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T elem = arr[i];
        int j; // 保存elem应该插入的位置
        for (j = i; j > 0 && arr[j - 1] > elem; --j)
            arr[j] = arr[j - 1];
        arr[j] = elem;
    }
}

template<typename T>
void insertSort(T arr[], int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        T elem = arr[i];
        int j;
        for (j = i; j > l && arr[j - 1] > elem; --j)
            arr[j] = arr[j - 1];
        arr[j] = elem;
    }
    return;
}

#endif //SORTALGORITHM_INSERTSORT_H
