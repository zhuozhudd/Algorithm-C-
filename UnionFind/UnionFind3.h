/**
 *  Created by zhuozhu on 2022/4/25 10:51.
 *  Description: UnionFind3.h
 */
//

#ifndef UNIONFIND_UNIONFIND3_H
#define UNIONFIND_UNIONFIND3_H

#include <cassert>

namespace UF3 {
    class UnionFind {
    private:
        int *parent;
        int *size; // size[i]表示以i为根的集合中元素个数
        int count;

    public:
        UnionFind(int count) {
            parent = new int[count];
            size = new int[count];
            this->count = count;
            for (int i = 0; i < count; ++i) {
                parent[i] = i; // 初始每个节点的根节点是本身
                size[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] size;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            while (p != parent[p])
                p = parent[p];
            return p;
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot)
                return; // 在一个集合中
            if (size[pRoot] < size[qRoot]) {
                parent[pRoot] = qRoot; // p -> qRoot
                size[qRoot] += size[pRoot];
            } else {
                parent[qRoot] = pRoot;
                size[pRoot] += size[qRoot];
            }
        }
    };
}
#endif //UNIONFIND_UNIONFIND3_H
