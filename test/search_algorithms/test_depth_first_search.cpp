#include "../catch.hpp"
#include "../../src/search_algorithms/depth_first_search.cpp"

TEST_CASE("Depth First Search") {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    SECTION("Searching for a node that exists") {
        node* result = depthFirstSearch(root, 5);
        REQUIRE(result->value == 5);
    }

    SECTION("Searching for a node that does not exist") {
        node* result = depthFirstSearch(root, 8);
        REQUIRE(result == nullptr);
    }
}

TEST_CASE("Depth First Search with empty tree") {
    node* root = nullptr;

    SECTION("Node does not exist") {
        REQUIRE(depthFirstSearch(root, 5) == nullptr);
    }
}