/**
 * Created by zhuozhu on 2022/4/17 8:34 PM.
 * Description: Srot test helper
 */
//

#ifndef SORTALGORITHM_SORTTESTHELPER_H
#define SORTALGORITHM_SORTTESTHELPER_H


#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {

    // 生成有n个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(nullptr)); // 将当前时间作为随机数种子设置
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }

        return arr;
    }

    // 生成一个近乎有序的数组
    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = i;

        srand(time(nullptr));
        for (int i = 0; i < swapTimes; ++i) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }


    // 测试排序是否正确
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }

    // 测试排序算法的运行时间
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        double time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        cout << sortName << " : " << time << " s" << endl;
    }

    int *copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }

    // 打印函数
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
#endif //SORTALGORITHM_SORTTESTHELPER_H
