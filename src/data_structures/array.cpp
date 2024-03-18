#include <iostream>

using namespace std;

void arrayDemo() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    arrayDemo();
    return 0;
}