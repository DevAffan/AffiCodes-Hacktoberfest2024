#include <iostream>
using namespace std;

// This function implements the Shell Sort algorithm
void shellSort(int arr[], int n) {
    // We start with a gap size, which is half of the array size
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Now we will perform a gapped insertion sort for the current gap
        for (int i = gap; i < n; i++) {
            // We need to temporarily store the current element
            int temp = arr[i];
            int j;
            
            // Shift elements that are gap positions away until we find the right spot for temp
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; // Move the larger element up
            }
            // Finally, we place temp in its correct position
            arr[j] = temp;
        }
    }
}

// This function prints the elements of the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; // Print each element followed by a space
    cout << endl; // New line after printing the array
}

// The main function to run the Shell Sort
int main() {
    // Let's define an array that we want to sort
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Call the shellSort function to sort our array
    shellSort(arr, n);
    
    // Print out the sorted array
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0; // End of the program
}