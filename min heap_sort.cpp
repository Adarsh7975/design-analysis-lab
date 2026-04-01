#include <iostream>
using namespace std;

// Heapify function for Min Heap
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Min Heap Sort function
void minHeapSort(int arr[], int n) {
    // Step 1: Build Min Heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // Move min to end
        heapify(arr, i, 0);     // Heapify reduced heap
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    minHeapSort(arr, n);

    cout << "Sorted array (Descending): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
