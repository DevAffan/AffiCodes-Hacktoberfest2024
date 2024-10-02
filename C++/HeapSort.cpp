#include <iostream>
using namespace std;

// Function to maintain the heap property
void heapify(int arr[], int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // Check if the left child exists and is greater than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if the right child exists and is greater than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root with the largest
        heapify(arr, n, largest);    // Recursively heapify the affected sub-tree
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Step 1: Build a max heap from the input array
    for (int i = n / 2 - 1; i >= 0; i--) // Start from the last non-leaf node
        heapify(arr, n, i);               // Heapify each node

    // Step 2: Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move the current root (largest) to the end
        heapify(arr, i, 0);    // Call heapify on the reduced heap
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) // Iterate through the array
        cout << arr[i] << " ";  // Print each element
    cout << "\n";               // New line after printing the array
}

// Driver function to test the heap sort algorithm
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; // Example array to be sorted
    int n = sizeof(arr) / sizeof(arr[0]); // Get the number of elements in the array

    heapSort(arr, n); // Perform heap sort on the array
    cout << "Sorted array is \n"; // Output message
    printArray(arr, n); // Print the sorted array
    return 0; // Indicate successful execution
}