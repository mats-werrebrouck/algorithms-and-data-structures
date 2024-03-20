#ifndef BST_H
#define BST_H

#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
    private:
        Node *root;
        void insert(Node *node, int data);
        void destroy(Node *node);
        Node* search(Node *node, int data);
        Node* remove(Node *node, int data);
        Node *findMin(Node *node);

    public: 
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(int data);
        Node* search(int data);
        void remove(int data);
};

#endif