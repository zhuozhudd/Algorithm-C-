/**
 *  Created by zhuozhu on 2022/4/22 14:27.
 *  Description: BinarySearchTree.h
 */
//

#ifndef BINARYSEARCH_BINARYSEARCHTREE_H
#define BINARYSEARCH_BINARYSEARCHTREE_H

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

template<typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) : key(key), value(value), left(nullptr), right(nullptr) {}

        Node(Node *node) : key(node->key), value(node->value), left(node->left), right(node->right) {}

    };


    Node *root;
    int count;
public:
    BST() : root(nullptr), count(0) {}

    ~BST() {
        destroy(root);
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }

    bool contain(Key key) {
        return contain(root, key);
    }

    Value *search(Key key) {
        return search(root, key);
    }

    // 前序遍历
    void preOrder() {
        preOrder(root);
    }

    // 中序遍历
    void inOrder() {
        inOrder(root);
    }

    // 后序遍历
    void postOrder() {
        postOrder(root);
    }

    // 层序遍历
    void levelOrder() {
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            cout << node->key << endl;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    // 寻找最小值
    Key minimum() {
        assert(count != 0);
        Node *minNode = minimum(root);
        return minNode->key;
    }

    //  寻找最大值
    Key maximum() {
        assert(count != 0);
        Node *maxNode = maximum(root);
        return maxNode->key;
    }

    // 从二叉树中删除最小值所在大节点
    void removeMin() {
        if (root) {
            root = removeMin(root);
        }
    }

    // 从二叉树中删除最大值所在大节点
    void removeMax() {
        if (root) {
            root = removeMax(root);
        }
    }

    // 从二叉树中删除键值为key对节点
    void removeKey(Key key) {
        root = removeKey(root, key);
    }
    // 寻找key的floor值, 递归算法
    // 如果不存在key的floor值(key比BST中的最小值还小), 返回NULL
    Key* floor(Key key){

        if( count == 0 || key < minimum() )
            return NULL;

        Node *floorNode = floor(root, key);
        return &(floorNode->key);
    }

    // 寻找key的ceil值, 递归算法
    // 如果不存在key的ceil值(key比BST中的最大值还大), 返回NULL
    Key* ceil(Key key){

        if( count == 0 || key > maximum() )
            return NULL;

        Node *ceilNode = ceil(root, key);
        return &(ceilNode->key);
    }
private:
    // 向以node为根的二叉搜索树中插入节点(key, value)
    // 返回插入新节点后的二叉搜索树的根
    Node *insert(Node *node, Key key, Value value) {
        if (node == nullptr) {
            count++;
            return new Node(key, value);
        }
        if (key == node->key)
            node->value = value;
        else if (key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);
        return node;
    }

    // 查看以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node *node, Key key) {
        if (node == nullptr) return false;
        if (key == node->key) return true;
        else if (key < node->key) return contain(node->left, key);
        else return contain(node->right, key);
    }

    // 以root为根的二叉搜索树中查找key所对应的value
    Value *search(Node *node, Key key) {
        if (node == nullptr)
            return nullptr;
        if (key == node->key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // 对以node为根对BST进行前序遍历
    void preOrder(Node *node) {
        if (node != nullptr) {
            cout << node->key << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // 对以node为根对BST进行中序遍历
    void inOrder(Node *node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->key << endl;
            inOrder(node->right);
        }
    }

    // 对以node为根对BST进行后序遍历
    void postOrder(Node *node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << endl;
        }
    }

    // 使用后序遍历对内存空间进行释放
    void destroy(Node *node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
            count--;
        }
    }

    // 在以node为根对BST中，返回最小键值对节点
    Node *minimum(Node *node) {
        if (node->left == nullptr)
            return node;
        return minimum(node->left);
    }

    // 在以node为根对BST中，返回最大键值对节点
    Node *maximum(Node *node) {
        if (node->right == nullptr)
            return node;
        return minimum(node->right);
    }

    // 删除以node根对BST中的最小节点
    // 返回删除节点后新的BST的根
    Node *removeMin(Node *node) {
        if (node->left == nullptr) {
            Node *rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    // 删除以node根对BST中的最大节点
    // 返回删除节点后新的BST的根
    Node *removeMax(Node *node) {
        if (node->right == nullptr) {
            Node *leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    // 删除以node根对BST中键值为key的节点
    // 返回删除节点后新的BST的根
    Node *removeKey(Node *node, Key key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (key < node->key) {
            node->left = removeKey(node->left, key);
            return node;
        } else if (key > node->key) {
            node->right = removeKey(node->right, key);
            return node;
        } else {
            if (node->left == nullptr) {
                Node *rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            if (node->right == nullptr) {
                Node *leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }

            // 左右孩子都不为空
            Node *successor = new Node(minium(node->right));
            count++;
            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            count--;
            return successor;

        }
    }
    // 在以node为根的二叉搜索树中, 寻找key的floor值所处的节点, 递归算法
    Node* floor(Node* node, Key key){

        if( node == NULL )
            return NULL;

        // 如果node的key值和要寻找的key值相等
        // 则node本身就是key的floor节点
        if( node->key == key )
            return node;

        // 如果node的key值比要寻找的key值大
        // 则要寻找的key的floor节点一定在node的左子树中
        if( node->key > key )
            return floor( node->left , key );

        // 如果node->key < key
        // 则node有可能是key的floor节点, 也有可能不是(存在比node->key大但是小于key的其余节点)
        // 需要尝试向node的右子树寻找一下
        Node* tempNode = floor( node->right , key );
        if( tempNode != NULL )
            return tempNode;

        return node;
    }


    // 在以node为根的二叉搜索树中, 寻找key的ceil值所处的节点, 递归算法
    Node* ceil(Node* node, Key key){

        if( node == NULL )
            return NULL;

        // 如果node的key值和要寻找的key值相等
        // 则node本身就是key的ceil节点
        if( node->key == key )
            return node;

        // 如果node的key值比要寻找的key值小
        // 则要寻找的key的ceil节点一定在node的右子树中
        if( node->key < key )
            return ceil( node->right , key );

        // 如果node->key > key
        // 则node有可能是key的ceil节点, 也有可能不是(存在比node->key小但是大于key的其余节点)
        // 需要尝试向node的左子树寻找一下
        Node* tempNode = ceil( node->left , key );
        if( tempNode != NULL )
            return tempNode;

        return node;
    }
};


#endif //BINARYSEARCH_BINARYSEARCHTREE_H
