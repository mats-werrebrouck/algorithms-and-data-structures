#include <queue>

using namespace std;

struct node {
    int value;
    node* left;
    node* right;

    node(int value) : value(value), left(nullptr), right(nullptr) {}
};

int getHeight(node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(getHeight(root->left), getHeight(root->right));
}

node* traverseLevel(node* current, int target, int level) {
    if (current == nullptr) {
        return nullptr;
    }

    if (level == 1) {
        if (current->value == target) {
            return current;
        }
    } else if (level > 1) {
        node* leftResult = traverseLevel(current->left, target, level - 1);
        if (leftResult) {
            return leftResult;
        }

        node* rightResult = traverseLevel(current->right, target, level - 1);
        if (rightResult) {
            return rightResult;
        }
    }

    return nullptr;
}

// Time complexity: O(n)
// Space complexity: O(1), if the recursion stack is not considered otherwise O(n)
node* breadthFirstSearch(node* root, int target) {
    if (root == nullptr) {
        return nullptr;
    }

    int height = getHeight(root);

    for (int i = 1; i <= height; i++) {
        node* result = traverseLevel(root, target, i);
        if (result) {
            return result;
        }
    }

    return nullptr;
}

// Time complexity: O(n)
// Space complexity: O(n)
node* breadthFirstSearchv2(node* root, int target) {
    if (root == nullptr) {
        return nullptr;
    }

    queue<node*> q;
    q.push(root);
    
    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        if (current->value == target) {
            return current;
        }

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    return nullptr;
}