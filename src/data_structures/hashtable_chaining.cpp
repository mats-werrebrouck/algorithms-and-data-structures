#include "hashtable_chaining.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int capacity) {
    this->capacity = capacity;
    this->table.resize(capacity);
}

HashTable::~HashTable() {}

int HashTable::hash(int key) {
    return key % this->capacity;
}

void HashTable::insert(int key, int value) {
    // Get the index of the key
    int index = this->hash(key);
    // Get the bucket at the index
    std::list<std::pair<int, int>> &bucket = this->table[index];

    // Check if the key already exists in the bucket
    for (std::pair<int, int> &pair : bucket) {
        // If the key exists, update the value
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    // If the key does not exist, add the key-value pair to the bucket
    bucket.push_back(std::make_pair(key, value));
}

void HashTable::remove(int key) {
    // Get the index of the key
    int index = this->hash(key);
    // Get the bucket at the index
    std::list<std::pair<int, int>> &bucket = this->table[index];

    // Iterate through the bucket to find the key
    for (std::pair<int, int> &pair : bucket) {
        // If the key is found, remove the key-value pair
        if (pair.first == key) {
            bucket.remove(pair);
            return;
        }
    }
}

int HashTable::search(int key) {
    // Get the index of the key
    int index = this->hash(key);
    // Get the bucket at the index
    std::list<std::pair<int, int>> &bucket = this->table[index];

    // Iterate through the bucket to find the key
    for (std::pair<int, int> &pair : bucket) {
        // If the key is found, return the value
        if (pair.first == key) {
            return pair.second;
        }
    }
    
    // If the key is not found, return -1
    return -1;
}

int main() {
    HashTable ht(5);

    ht.insert(10, 100);
    ht.insert(20, 200);
    ht.insert(30, 300);
    ht.insert(15, 150);

    cout << "Searching for key 20: ";
    int value = ht.search(20);
    if (value != -1) {
        cout << "Found, value is: " << value << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "Removing key 20" << endl;
    ht.remove(20);

    cout << "Searching for key 20: ";
    value = ht.search(20);
    if (value != -1) {
        cout << "Found, value is: " << value << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}