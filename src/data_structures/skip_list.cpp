#include "skip_list.h"

SkipListNode::SkipListNode(int value, int level) {
    this->value = value;

    // allocate memory for forward array of pointers 
    // with size level + 1 (0 to level)
    forward = new SkipListNode*[level + 1];

    // fill forward array with 0
    for (int i = 0; i <= level; i++) {
        forward[i] = nullptr;
    }
}

SkipListNode::~SkipListNode() {
    delete[] forward;
}

SkipList::SkipList(int maxLevel) {
    this->maxLevel = maxLevel;
    level = 0;

    // create header node and initialize its forward array
    header = new SkipListNode(0, maxLevel);
}

SkipList::~SkipList() {
    delete header;
}

int SkipList::randomLevel() {
    int level = 0;
    // generate a random number between 0 and 1
    // if it is 1, increase the level
    while (level < maxLevel && rand() % 2) {
        level++;
    }
    // return the level
    return level;
}

void SkipList::insert(int value) {
    SkipListNode *current = header;

    // create update array and initialize it
    // update array is used to keep track of the nodes at each level where the new node will be inserted and to where pointers will be rearranged
    SkipListNode *update[maxLevel + 1];
    for (int i = 0; i <= maxLevel; i++) {
        update[i] = nullptr;
    }

    // start from the highest level of the skip list
    for (int i = level; i >= 0; i--) {
        // move the current node forward while the value of the next node is less than the value we are searching for
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        // update the update array at level i
        update[i] = current;
    }

    // Reached level 0 and forward pointer to the right is desired position to add the new node
    current = current->forward[0];

    // if current is null or not the value we are searching for, create a new node
    if (current == nullptr || current->value != value) {
        // generate a random level for node
        int rlevel = randomLevel();

        // if the random level is greater than the current level of the skip list
        if (rlevel > level) {
            // initialize update value with header
            for (int i = level + 1; i <= rlevel; i++) {
                update[i] = header;
            }
            // update the current level
            level = rlevel;
        }

        // create new node with random level generated
        SkipListNode *n = new SkipListNode(value, rlevel);

        // insert node by rearranging pointers
        for (int i = 0; i <= rlevel; i++) {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
    }
}

void SkipList::remove(int value) {
    SkipListNode *current = header;

    // create update array and initialize it
    SkipListNode *update[maxLevel + 1];
    for (int i = 0; i <= maxLevel; i++) {
        update[i] = nullptr;
    }

    // start from the highest level of the skip list
    for (int i = level; i >= 0; i--) {
        // move the current node forward while the value of the next node is less than the value we are searching for
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        // update the update array at level i
        update[i] = current;
    }

    // Reached level 0 and forward pointer to the right is the position to remove the node
    current = current->forward[0];

    // if current node is the value we are searching for
    if (current != nullptr && current->value == value) {
        // start from the lowest level of the skip list
        for (int i = 0; i <= level; i++) {
            // if the value of the next node is equal to the value we are searching for
            if (update[i]->forward[i] == current) {
                // rearrange pointers
                update[i]->forward[i] = current->forward[i];
            }
        }

        // remove levels having no elements
        while (level > 0 && header->forward[level] == nullptr) {
            level--;
        }

        // delete the node
        delete current;
    }
}

bool SkipList::search(int value) {
    SkipListNode *current = header;

    // start from the highest level of the skip list
    for (int i = level; i >= 0; i--) {
        // move the current node forward while the value of the next node is less than the value we are searching for
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
    }

    // Reached level 0 and forward pointer to the right is the position to search for the value
    current = current->forward[0];

    // if current node is the value we are searching for
    if (current != nullptr && current->value == value) {
        return true;
    }

    // if current is null or not the value we are searching for, return false
    return false;
}

void SkipList::display() {
    std::cout << "Skip List" << std::endl;
    for (int i = 0; i <= level; i++) {
        SkipListNode *node = header->forward[i];
        std::cout << "Level " << i << ": ";
        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->forward[i];
        }
        std::cout << std::endl;
    }
}

int main() {
    // create a skip list with max level 3
    SkipList list(3);

    list.insert(3);
    list.insert(6);
    list.insert(7);
    list.insert(9);
    list.insert(12);
    list.insert(19);
    list.insert(17);
    list.insert(26);
    list.insert(21);
    list.insert(25);
    list.display();

    std::cout << "Search for 19: " << list.search(19) << std::endl;
    std::cout << "Remove 19" << std::endl;
    list.remove(19);
    list.display();
    std::cout << "Search for 19: " << list.search(19) << std::endl;

    return 0;
}