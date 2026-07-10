#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    auto start = high_resolution_clock::now();

    int low = 0;
    int high = n - 1;
    int index = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key) {
            index = mid;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    auto end = high_resolution_clock::now();

    if(index != -1)
        cout << "Element found at index: " << index;
    else
        cout << "Element not found";

    auto duration = duration_cast<microseconds>(end - start);
    cout << "\nExecution Time: " << duration.count() << " microseconds";

    return 0;
}