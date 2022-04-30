/**
 *  Created by zhuozhu on 2022/4/28 21:25.
 *  Description: UnionFind.h
 */
//

#ifndef MST_UNIONFIND_H
#define MST_UNIONFIND_H

#include <iostream>
#include <cassert>

using namespace std;

// Quick Union + rank + path compression

class UnionFind {
private:
    int *parent;
    int *rank;
    int count;
public:
    UnionFind(int count) {
        parent = new int[count];
        rank = new int[count];
        this->count = count;
        for (int i = 0; i < count; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    int find(int p) {
        assert(p >= 0 && p < count);

        // path compression 1
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;
        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else if (rank[pRoot] > rank[qRoot])
            parent[qRoot] = pRoot;
        else {
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
};

#endif //MST_UNIONFIND_H
