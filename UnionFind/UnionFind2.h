/**
 *  Created by zhuozhu on 2022/4/25 10:33.
 *  Description: UnionFind2.h
 */
//

#ifndef UNIONFIND_UNIONFIND2_H
#define UNIONFIND_UNIONFIND2_H

#include <cassert>

namespace UF2 {
    //
    class UnionFind {
    private:
        int *parent;
        int count;

    public:
        UnionFind(int count) {
            parent = new int[count];
            this->count = count;
            for (int i = 0; i < count; ++i) {
                parent[i] = i; // 初始每个节点的根节点是本身
            }
        }

        ~UnionFind() {
            delete[] parent;
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

        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if(pRoot == qRoot)
                return; // 在一个集合中
            parent[pRoot] = qRoot;
        }
    };
}
#endif //UNIONFIND_UNIONFIND2_H
