public class HeapSort {

    // Function to sort an array using Heap Sort
    public void heapSort(int[] array) {
        int n = array.length;

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(array, n, i);
        }

        // Extract elements from the heap one by one
        for (int i = n - 1; i > 0; i--) {
            // Move current root to the end
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;

            // Call max heapify on the reduced heap
            heapify(array, i, 0);
        }
    }

    // Function to heapify a subtree rooted at node i
    void heapify(int[] array, int n, int i) {
        int largest = i;  // Initialize largest as root
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2;  // Right child

        // If the left child is larger than root
        if (left < n && array[left] > array[largest]) {
            largest = left;
        }

        // If the right child is larger than largest so far
        if (right < n && array[right] > array[largest]) {
            largest = right;
        }

        // If the largest is not root
        if (largest != i) {
            int swap = array[i];
            array[i] = array[largest];
            array[largest] = swap;

            // Recursively heapify the affected subtree
            heapify(array, n, largest);
        }
    }

    // Utility function to print the array
    static void printArray(int[] array) {
        int n = array.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    // Main method to test the heap sort implementation
    public static void main(String[] args) {
        int[] array = {12, 11, 13, 5, 6, 7};

        HeapSort heapSort = new HeapSort();
        System.out.println("Given Array:");
        printArray(array);

        heapSort.heapSort(array);

        System.out.println("Sorted Array:");
        printArray(array);
    }
}
