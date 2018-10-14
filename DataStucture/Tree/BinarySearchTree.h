//
// Created by root on 2018/10/13.
//

#ifndef DATA_STRUCTURE_BINARYSEARCHTREE_H
#define DATA_STRUCTURE_BINARYSEARCHTREE_H

#include <queue>
#include <algorithm>
#include <iostream>
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

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }

        Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node *root;
    int count;

public:
    BST() {
        root = NULL;
        count = 0;
    }

    ~BST() {
        destory();
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insertNode(Key key, Value value) {
        root = insert(root, key, value);
    }

    Value *search(Key key) {
        return search(root, key);
    }

    bool contain(Key key) {
        return contain(root, key);
    }

    void preOreder() {
        preOrder(root);
    }

    void inOrder() {
        inOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }

    void destory() {
        destory(root);
    }

    void levelOrder() {
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *p = q.front();
            q.pop();
            cout << p->value;
            if (p->left) {
                q.push(p->left);
            }
            if (p->right) {
                q.push(p->right);
            }
        }
    }

    Key minimum() {
        assert(count != 0);
        Node *node = minimum(root);
        return node->key;
    }

    Key maximum(){
        assert(count != 0);
        Node *node = maximum(root);
        return node->key;
    }

    void removeMin(){
        if (root){
            root = removeMin(root);
        }
    }

    void removeMax(){
        if (root){
            root = removeMax(root);
        }
    }

    void remove(Key key){
        root = remove(root, key);
    }
private:

    Node *remove(Node *node, Key key){
        if ( node == NULL){
            return NULL;
        } else if (key < node->key){
            node->left = remove(node->left, key);
        } else if (key > node->key){
            node->right = remove(node->right, key);
        } else{
            if (node->left == NULL){
                Node *right = node->right;
                delete node;
                count --;
                return right;
            } else if (node->right == NULL){
                Node *left = node->left;
                delete node;
                count --;
                return left;
            } else{
                Node *delNode = node;
                Node *successor = new Node(minimum(node->right));
                count ++;
                successor->right = removeMin(node->right);
                successor->left = node->left;
                delete delNode;
                count --;
                return successor;
            }
        }
    }

    Node *removeMax(Node *node){
        if (node->right == NULL){
            Node *left = node->left;
            delete node;
            count --;
            return left;
        }
        node->right = removeMax(node->right);
        return node;
    }

    Node *removeMin(Node *node){
        if (node->left == NULL){
            Node *right = node->right;
            delete node;
            count --;
            return right;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node *minimum(Node *node) {
        if (node->left == NULL) {
            return node;
        }
        return minimum(node->left);
    }

    Node *maximum(Node *node) {
        if (node->right){
            return node;
        }
        return maximum(node->right);
    }

    Node *insert(Node *node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }
        if (node->key == key) {
            node->value = value;
        } else if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else {
            node->right = insert(node->right, key, value);
        }
        return node;
    }

    Value *search(Node *node, Key key) {
        if (NULL == node) {
            return NULL;
        } else if (node->key == key) {
            return &(node->value);
        } else if (key < node->key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    bool contain(Node *node, Key key) {
        if (NULL == node) {
            return false;
        }
        if (node->key == key) {
            return true;
        } else if (key < node->key) {
            return contain(node->left, key);
        } else {
            return contain(node->right, key);
        }
    }

    void preOrder(Node *node) {
        if (node != NULL) {
            cout << node->value;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node *node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->value;
            inOrder(node->right);
        }
    }

    void postOrder(Node *node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->value;
        }
    }

    void destory(Node *node) {
        if (node != NULL) {
            destory(node->left);
            destory(node->right);
            delete node;
            count--;
        }
    }
};

#endif //DATA_STRUCTURE_BINARYSEARCHTREE_H
