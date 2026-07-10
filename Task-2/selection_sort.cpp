#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto start = high_resolution_clock::now();

    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
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