/**
 * Created by zhuozhu on 2022/4/17 8:40 PM.
 * Description: Select sort
 */
//

#ifndef SORTALGORITHM_SELECTSORT_H
#define SORTALGORITHM_SELECTSORT_H

#include <iostream>

using namespace std;

template<typename T>
void selectSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

struct Student {
    string name;
    int score;

    // 重载< , 用于比较
    bool operator<(const Student &otherStudent) {
        return score == otherStudent.score ? name < otherStudent.name : score < otherStudent.score;
    }

    // 重载 << , 用于打印
    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "student:" << student.name << " " << student.score << endl;
        return os;
    }
};
#endif //SORTALGORITHM_SELECTSORT_H
