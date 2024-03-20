#include "bst.h"
#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

void BinarySearchTree::insert(int data) {
    if (root == nullptr) {
        root = new Node(data);
    } else {
        insert(root, data);
    }
}

void BinarySearchTree::insert(Node *node, int data) {
    if (data < node->data) {
        if (node->left == nullptr) {
            node->left = new Node(data);
        } else {
            insert(node->left, data);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new Node(data);
        } else {
            insert(node->right, data);
        }
    }
}

Node* BinarySearchTree::search(int data) {
    return search(root, data);
}

Node* BinarySearchTree::search(Node *node, int data) {
    if (node == nullptr || node->data == data) {
        return node;
    } else if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

void BinarySearchTree::remove(int data) {
    root = remove(root, data);
}

Node* BinarySearchTree::remove(Node *node, int data) {
    // Base case: if the tree is empty, return null
    if (node == nullptr) {
        return node;
    // Otherwise, recur down the tree
    // If the data to be deleted is smaller than the root's data, then it lies in the left subtree
    } else if (data < node->data) {
        // Recur down the left subtree
        node->left = remove(node->left, data);
    // If the data to be deleted is greater than the root's data, then it lies in the right subtree
    } else if (data > node->data) {
        // Recur down the right subtree
        node->right = remove(node->right, data);
    // If the data is same as node's data, then this is the node to be deleted
    } else {
        // Node with only one child or no child
        if (node->left == nullptr) {
            // If the node has only a right child, then you can just return the right child and delete the node
            Node *temp = node->right;
            delete node;
            return temp;
        // If the node has only a left child, then you can just return the left child and delete the node
        } else if (node->right == nullptr) {
            Node *temp = node->left;
            delete node;
            return temp;
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        } else {
            // Find the minimum value in the right subtree
            Node *temp = findMin(node->right);
            // Copy the inorder successor's content to this node
            node->data = temp->data;
            // Delete the inorder successor
            node->right = remove(node->right, temp->data);
        }
    }
    return node;
}

Node* BinarySearchTree::findMin(Node *node) {
    Node *current = node;
    // Loop down to find the leftmost leaf
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void BinarySearchTree::destroy(Node *node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    bst.insert(1);
    bst.insert(9);
    bst.insert(0);
    bst.insert(10);

    cout << "Search for 5: " << (bst.search(5) ? "Found" : "Not found") << endl;
    cout << "Search for 9: " << (bst.search(9) ? "Found" : "Not found") << endl;
    
    bst.remove(3);
    bst.remove(7);

    cout << "Search for 3: " << (bst.search(3) ? "Found" : "Not found") << endl;
    cout << "Search for 7: " << (bst.search(7) ? "Found" : "Not found") << endl;

    return 0;
}