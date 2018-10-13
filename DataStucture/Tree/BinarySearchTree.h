//
// Created by root on 2018/10/13.
//

#ifndef DATA_STRUCTURE_BINARYSEARCHTREE_H
#define DATA_STRUCTURE_BINARYSEARCHTREE_H

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

    void preOreder(){
        preOrder(root);
    }

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

    void destory(){
        destory(root);
    }

private:
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

    void preOrder(Node *node){
        if (node != NULL){
            cout << node->value;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node *node){
        if (node != NULL){
            inOrder(node->left);
            cout << node->value;
            inOrder(node->right);
        }
    }

    void postOrder(Node * node){
        if (node != NULL){
            postOrder(node->left);
            postOrder(node->right);
            cout << node->value;
        }
    }

    void destory(Node *node){
        if (node != NULL){
            destory(node->left);
            destory(node->right);
            delete node;
            count --;
        }
    }
};

#endif //DATA_STRUCTURE_BINARYSEARCHTREE_H
