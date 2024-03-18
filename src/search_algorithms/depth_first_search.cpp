using namespace std;

struct node {
    int value;
    node* left;
    node* right;

    node(int value) : value(value), left(nullptr), right(nullptr) {}
};

// Time complexity: O(n)
// Space complexity: O(log n)
node* depthFirstSearch(node* root, int target) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->value == target) {
        return root;
    }

    node* leftResult = depthFirstSearch(root->left, target);
    if (leftResult) {
        return leftResult;
    }

    node* rightResult = depthFirstSearch(root->right, target);
    if (rightResult) {
        return rightResult;
    }

    return nullptr;
}