/**
 *  Created by zhuozhu on 2022/4/25 12:07.
 *  Description: UnionFind5.h
 */
//

#ifndef UNIONFIND_UNIONFIND5_H
#define UNIONFIND_UNIONFIND5_H

#include <cassert>

namespace UF5 {
    class UnionFind {
    private:
        int *parent;
        int *rank; // rank[i]表示以i为根的集合所表示的树的层数
        int count;

    public:
        UnionFind(int count) {
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for (int i = 0; i < count; ++i) {
                parent[i] = i; // 初始每个节点的根节点是本身
                rank[i] = 1;   // 单个节点均为1层
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
//            路径压缩实现方法 1
//            while (p != parent[p]){
//                parent[p] = parent[parent[p]]; // 路径压缩
//                p = parent[p];
//            }
//            return p;
//          路径压缩实现方法 2
            if (p != parent[p])
                parent[p] = find(parent[p]); // 递归实现，所有节点都将直接指向根节点
            return parent[p];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot)
                return; // 在一个集合中
            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot; // p -> qRoot
            } else if (rank[qRoot] < rank[pRoot]) {
                parent[qRoot] = pRoot;
            } else {
                parent[pRoot] = qRoot; // p -> qRoot
                rank[qRoot]++;
            }
        }
    };
}
#endif //UNIONFIND_UNIONFIND5_H
