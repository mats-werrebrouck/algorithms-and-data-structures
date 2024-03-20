#ifndef HASH_TABLE_PROBING_H
#define HASH_TABLE_PROBING_H

#include <iostream>
#include <vector>
#include <utility>

class HashTable {
    private:
        int capacity;
        std::vector<std::pair<int, int>> table;
        std::vector<bool> isOccupied;

        int hash(int key);
    
    public:
        HashTable(int capacity);
        ~HashTable();

        void insert(int key, int value);
        void remove(int key);
        int search(int key);
};

#endif