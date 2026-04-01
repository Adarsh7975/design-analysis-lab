#include <iostream>
using namespace std;

// Heapify function
void heapify(int arr[], int n, int i) {
    int largest = i;        // root
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify affected subtree
        heapify(arr, n, largest);
    }
}

// Main Heap Sort function
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move root to end
        heapify(arr, i, 0);    // Heapify reduced heap
    }
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
