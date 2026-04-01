#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;   // element found

        else if (arr[mid] < key)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;  // element not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 16;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}
