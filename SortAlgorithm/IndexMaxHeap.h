/**
 *  Created by zhuozhu on 2022/4/21 20:14.
 *  Description: IndexMaxHeap.h
 */
//

#ifndef SORTALGORITHM_INDEXMAXHEAP_H
#define SORTALGORITHM_INDEXMAXHEAP_H

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template<typename Item>
class IndexMaxHeap {
private:
    Item *data;
    int *indexes; // 将索引构造为堆，不改变data堆元素位置
    int *reverse; // reverse[i]表示索引i在indexes(堆)中的索引位置
    int count; // 数量
    int capacity; // 容量


    void shiftUp(int idx) {
        while (idx > 1 && data[indexes[idx / 2]] < data[indexes[idx]]) {
            swap(indexes[idx / 2], indexes[idx]);
            reverse[indexes[idx / 2]] = idx / 2;
            reverse[indexes[idx]] = idx;
            idx /= 2;
        }
    }

    void shiftDown(int idx) {
        while (2 * idx <= count) { // k一定有孩子节点
            int j = 2 * idx; // 在此轮循环中，data[k]和data[j]交换位置
            if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
                j += 1;
            if (data[indexes[idx]] > data[indexes[j]])
                break;
            else swap(indexes[idx], indexes[j]);
            reverse[indexes[idx]] = idx;
            reverse[indexes[j]] = j;
            idx = j;
        }
    }

public:
    IndexMaxHeap(int capacity) {
        // 从索引1开始存储
        data = new Item[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];
        for (int i = 0; i <= capacity; ++i)
            reverse[i] = 0; // 对reverse初始化
        count = 0;
        this->capacity = capacity;
    }


    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    // 传入的i对于用户而言，是从0开始索引的
    void insert(int i, Item item) {
        assert(count + 1 <= capacity);
        assert(i + 1 >= 1 && i + 1 <= capacity);
        i += 1; // 从1开始索引
        data[i] = item;
        count++;
        indexes[count] = i;
        reverse[i] = count;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);
        Item elem = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return elem;
    }

    Item extractMaxIndex() {
        assert(count > 0);
        int elem = indexes[1] - 1; // 转换为从0开始的索引
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return elem;
    }

    bool contain(int idx) {
        assert(idx >= 0 && idx + 1 <= capacity);
        return reverse[idx + 1] != 0;
    }

    Item getItem(int i) {
        assert(contain(i));
        return data[i + 1];
    }

    void change(int i, Item newItem) {
        assert(contain(i));
        i += 1; // 转换从1开始的索引
        data[i] = newItem;

        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shitfUp(j), 再shiftDown(j)
        /* 使用reverse数组优化后无需便利
        for (int j = 0; j <= count; ++j) {
            if (indexes[j] == i) {
                shiftUp(j);
                shiftDown(j);
                return;
            }
        }
         */
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
    }

public:
    // 以树状打印整个堆结构
    void testPrint() {

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if (size() >= 100) {
            cout << "This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if (typeid(Item) != typeid(int)) {
            cout << "This print function can only work for int item";
            return;
        }

        cout << "The max heap size is: " << size() << endl;
        cout << "Data in the max heap: ";
        for (int i = 1; i <= size(); i++) {
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert(data[i] >= 0 && data[i] < 100);
            cout << data[i] << " ";
        }
        cout << endl;
        cout << endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            string line1 = string(max_level_number * 3 - 1, ' ');

            int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
                putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            cout << line1 << endl;

            if (level == max_level - 1)
                break;

            string line2 = string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
                putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
            cout << line2 << endl;

            cur_tree_max_level_number /= 2;
        }
    }

private:
    void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        } else {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
};

#endif //SORTALGORITHM_INDEXMAXHEAP_H
