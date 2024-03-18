#include <iostream>

using namespace std;

void array_demo() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    array_demo();
    return 0;
}