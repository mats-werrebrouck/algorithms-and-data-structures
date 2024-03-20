#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <iostream>
// to use rand()
#include <cstdlib>

class SkipListNode {
    public:
        int value;
        // array of pointers to the next node in each level
        SkipListNode **forward;

        SkipListNode(int value, int level);
        ~SkipListNode();
};

class SkipList {
    private:
        // maximum level of the skip list
        int maxLevel;
        // current level of the skip list
        int level;
        // pointer to the header node
        SkipListNode *header;

        int randomLevel();

    public:
        SkipList(int maxLevel);
        ~SkipList();

        void insert(int value);
        void remove(int value);
        bool search(int value);

        void display();
};

#endif