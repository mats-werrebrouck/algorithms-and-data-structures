#include <iostream>
#include <queue>

using namespace std;

void queue_demo() {
    queue<int> q;
    q.push(3);
    q.push(5);
    q.push(2);
    q.push(1);
    q.push(4);

    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void priority_queue_demo() {
    priority_queue<int> pq;
    pq.push(3);
    pq.push(5);
    pq.push(2);
    pq.push(1);
    pq.push(4);

    cout << "Priority queue elements: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    queue_demo();
    priority_queue_demo();
    return 0;
}