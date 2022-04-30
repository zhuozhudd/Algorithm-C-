/**
 *  Created by zhuozhu on 2022/4/25 09:29.
 *  Description: UnionFind1.h
 */
//

#ifndef UNIONFIND_UNIONFIND1_H
#define UNIONFIND_UNIONFIND1_H

#include <iostream>
#include <cassert>

using namespace std;

namespace UF1 {
    // 特点：Find - O(1), Union - O(n), QuickFind
    class UnionFind {
    private:
        int *id;
        int count;
    public:
        UnionFind(int n) {
            count = n;
            id = new int[n];
            for (int i = 0; i < n; ++i) {
                id[i] = i; // 初始化每个节点之间都不相连
            }
        }

        ~UnionFind() {
            delete[] id;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            return id[p];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // O(n)
        void unionElements(int p, int q) {
            int pId = find(p);
            int qId = find(q);
            if (pId == qId) return;
            for (int i = 0; i < count; i++) {
                if (id[i] == pId)
                    id[i] = qId;
            }
        }
    };
}


#endif //UNIONFIND_UNIONFIND1_H
