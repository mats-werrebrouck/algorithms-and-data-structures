#include "../catch.hpp"
#include "../../src/search_algorithms/breadth_first_search.cpp"

TEST_CASE("Naive Breadth First Search") {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    SECTION("Node exists") {
        REQUIRE(breadth_first_search(root, 5)->value == 5);
    }

    SECTION("Node does not exist") {
        REQUIRE(breadth_first_search(root, 8) == nullptr);
    }
}

TEST_CASE("Naive Breadth First Search with empty tree") {
    node* root = nullptr;

    SECTION("Node does not exist") {
        REQUIRE(breadth_first_search(root, 5) == nullptr);
    }
}

TEST_CASE("Breadth First Search") {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    SECTION("Node exists") {
        REQUIRE(breadth_first_searchv2(root, 5)->value == 5);
    }

    SECTION("Node does not exist") {
        REQUIRE(breadth_first_searchv2(root, 8) == nullptr);
    }
}

TEST_CASE("Breadth First Search with empty tree") {
    node* root = nullptr;

    SECTION("Node does not exist") {
        REQUIRE(breadth_first_searchv2(root, 5) == nullptr);
    }
}