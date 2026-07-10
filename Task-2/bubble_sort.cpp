#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto start = high_resolution_clock::now();

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    auto end = high_resolution_clock::now();

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    auto duration = duration_cast<microseconds>(end - start);
    cout << "\nExecution Time: " << duration.count() << " microseconds";

    return 0;
}