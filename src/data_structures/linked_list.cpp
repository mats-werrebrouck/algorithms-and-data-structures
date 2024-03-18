#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
struct DNode {
    T data;
    DNode* next;
    DNode* prev;
    DNode(T data) : data(data), next(nullptr), prev(nullptr) {}
};

void singleLinkedListDemo() {
    Node<int>* head = new Node<int>(1);
    head->next = new Node<int>(2);
    head->next->next = new Node<int>(3);
    head->next->next->next = new Node<int>(4);
    head->next->next->next->next = new Node<int>(5);

    Node<int>* temp = head;
    cout << "Linked list elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free memory
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void doubleLinkedListDemo() {
    DNode<int>* head = new DNode<int>(1);
    head->next = new DNode<int>(2);
    head->next->prev = head;
    head->next->next = new DNode<int>(3);
    head->next->next->prev = head->next;
    head->next->next->next = new DNode<int>(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new DNode<int>(5);
    head->next->next->next->next->prev = head->next->next->next;

    DNode<int>* temp = head;
    cout << "Double linked list elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free memory
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    singleLinkedListDemo();
    doubleLinkedListDemo();
    return 0;
}