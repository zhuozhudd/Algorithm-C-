#include <iostream>
#include "SortTestHelper.h"
#include "SelectSort.h"
#include "InsertSort.h"
#include "MergeSort.h"
#include "QuickSort1.h"
#include "QuickSort2.h"
#include "QuickSort3Ways.h"
#include "HeapSort.h"

void testSort_select_and_insert();

void testSort_merge_and_insert(int n);

void testSort_quick_and_merge(int n, int swapTimes);

void testSort_heap_quick_merge(int n);
int main() {
    // testSort_select_and_insert();
    // testSort_merge_and_insert(50000);
    // testSort_quick_and_merge(1000000, 100);

    testSort_heap_quick_merge(1000000);
    return 0;
}

void testSort_heap_quick_merge(int n) {
    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);
    int* arr5 = SortTestHelper::copyIntArray(arr1, n);
    int* arr6 = SortTestHelper::copyIntArray(arr1, n);
    int* arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort1, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort ", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort1, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort ", heapSort, arr7, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout<<endl;


    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    // 这种情况下, 普通的QuickSort退化为O(n^2)的算法, 不做测试
    SortTestHelper::testSort("Quick Sort", quickSort1, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort ", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
}

void testSort_quick_and_merge(int n, int swapTimes) {
    cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Merge Sort: ", mergeSort, arr1, n);
    // SortTestHelper::testSort("Quick Sort1: ", quickSort1, arr2, n);
    SortTestHelper::testSort("Quick Sort2: ", quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort3Ways: ", quickSort3Ways, arr4, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout << endl << "Test for Random Nearly Ordered Array, size = " << n << ", swapTimes = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Merge Sort: ", mergeSort, arr1, n);
    // SortTestHelper::testSort("Quick Sort1: ", quickSort1, arr2, n);
    SortTestHelper::testSort("Quick Sort2: ", quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort3Ways: ", quickSort3Ways, arr4, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout << endl << "Test for Random Array, size = " << n << ", Random Range: [0,10]" << endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Merge Sort: ", mergeSort, arr1, n);
    // SortTestHelper::testSort("Quick Sort1: ", quickSort1, arr2, n);
    SortTestHelper::testSort("Quick Sort2: ", quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort3Ways: ", quickSort3Ways, arr4, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
}


void testSort_merge_and_insert(int n) {

    //int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Insert Sort Pro: ", insertSortPro, arr, n);
    SortTestHelper::testSort("MergeSort: ", mergeSort, arr2, n);

    delete[] arr;
    delete[] arr2;
}


void testSort_select_and_insert() {
    int n = 100000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Insert Sort", insertSort, arr, n);
    SortTestHelper::testSort("Insert Sort Pro", insertSortPro, arr2, n);
    SortTestHelper::testSort("Select Sort", selectSort, arr3, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
}