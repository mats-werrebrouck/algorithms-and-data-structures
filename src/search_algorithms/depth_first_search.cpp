using namespace std;

struct node {
    int value;
    node* left;
    node* right;

    node(int value) : value(value), left(nullptr), right(nullptr) {}
};

node* depth_first_search(node* root, int target) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->value == target) {
        return root;
    }

    node* leftResult = depth_first_search(root->left, target);
    if (leftResult) {
        return leftResult;
    }

    node* rightResult = depth_first_search(root->right, target);
    if (rightResult) {
        return rightResult;
    }

    return nullptr;
}