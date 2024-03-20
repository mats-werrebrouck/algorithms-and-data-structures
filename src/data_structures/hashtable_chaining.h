#ifndef HASHTABLE_CHAINING_H
#define HASHTABLE_CHAINING_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>

class HashTable {
    private:
        int capacity;
        std::vector<std::list<std::pair<int, int>>> table;

        int hash(int key);

    public:
        HashTable(int capacity);
        ~HashTable();

        void insert(int key, int value);
        void remove(int key);
        int search(int key);
};

#endif