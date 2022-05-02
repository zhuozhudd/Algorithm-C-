/*
 * @Author: szz
 * @Date: 2022-05-02 10:00:05
 * @Description: 
 */
#include <iostream>
#include "TestUnionFind.h"
#include "UnionFindTestHelper.h"

int main() {
    int n = 1000000;
    // UnionFindTestHelper::testUF1(n);
    // UnionFindTestHelper::testUF2(n);
    // UnionFindTestHelper::testUF3(n); // size优化
    // UnionFindTestHelper::testUF4(n); // rank优化
    UnionFindTestHelper::testUF5(n); // 路径压缩
    return 0;
}
