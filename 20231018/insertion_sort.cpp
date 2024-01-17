#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int data[] = {1,9,3,2,5,7,4,6,8,0};
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    insertionSort(data, n);
    for (int i = 0; i < n; ++i) {
        cout << data[i] << " ";
    }

    cout << endl;

    return 0;
}