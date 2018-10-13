//
// Created by root on 2018/10/13.
//

#ifndef DATA_STRUCTURE_BINARYSEARCHTREE_H
#define DATA_STRUCTURE_BINARYSEARCHTREE_H

#include <algorithm>
#include <iostream>
#include <cassert>

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
        //TODO
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insertNode(Key key, Value value){
        root = insert(root, key, value);
    }

    Node *search(Key key){

    }

    bool contain(Key key){

    }

private:
    Node *insert(Node *node, Key key, Value value){
        if (node == NULL){
            count ++;
            return new Node(key, value);
        }
        if (node->key == key){
            node->value = value;
        } else if(key < node->key){
            node->left = insert(node->left, key, value);
        } else{
            node->right = insert(node->right, key, value);
        }
        return node;
    }

    Node *search(Node *node, Key key, Value value){
    }
};

#endif //DATA_STRUCTURE_BINARYSEARCHTREE_H
