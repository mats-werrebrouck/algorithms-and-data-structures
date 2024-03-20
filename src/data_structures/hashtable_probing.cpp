#include "hashtable_probing.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int capacity) {
    this->capacity = capacity;
    this->table.resize(capacity);
    this->isOccupied.resize(capacity, false);
}

HashTable::~HashTable() {}

int HashTable::hash(int key) {
    return key % this->capacity;
}

void HashTable::insert(int key, int value) {
    // Find the next available index
    int index = this->hash(key);

    while (this->isOccupied[index]) {
        if (this->table[index].first == key) {
            // If the key already exists, update the value
            cerr << "Key already exists" << endl;
            return;
        }

        // Linear probing
        index = (index + 1) % this->capacity;
        
        // If we have looped back to the original index, the table is full
        if (index == this->hash(key)) {
            cerr << "Table is full" << endl;
            return;
        }
    }
    
    // Insert the key-value pair
    this->table[index] = std::make_pair(key, value);
    // Mark the index as occupied
    this->isOccupied[index] = true;
}

void HashTable::remove(int key) {
    // Find the index of the key
    int index = this->hash(key);

    while (this->isOccupied[index]) {
        if (this->table[index].first == key) {
            // Mark the index as unoccupied
            this->isOccupied[index] = false;
            return;
        }

        // Linear probing
        index = (index + 1) % this->capacity;

        if (index == this->hash(key)) {
            cerr << "Key not found" << endl;
            return;
        }
    }

    cerr << "Key not found" << endl;
}

int HashTable::search(int key) {
    // Find the index of the key
    int index = this->hash(key);

    while (this->isOccupied[index]) {
        if (this->table[index].first == key) {
            return this->table[index].second;
        }

        // Linear probing
        index = (index + 1) % this->capacity;

        if (index == this->hash(key)) {
            cerr << "Key not found" << endl;
            return -1;
        }
    }

    cerr << "Key not found" << endl;
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