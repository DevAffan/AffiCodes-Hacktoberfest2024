public class QuickSort {

    // Main function to implement quick sort
    public static void quickSort(int[] array, int low, int high) {
        if (low < high) {
            // Get the pivot element at correct position
            int partitionIndex = partition(array, low, high);

            // Recursively sort elements before and after partition
            quickSort(array, low, partitionIndex - 1);
            quickSort(array, partitionIndex + 1, high);
        }
    }

    // Function to partition the array
    public static int partition(int[] array, int low, int high) {
        int pivot = array[high];  // Choose the last element as the pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to the pivot
            if (array[j] <= pivot) {
                i++;

                // Swap elements array[i] and array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // Swap the pivot element with the element at index i+1
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        return i + 1;  // Return the partition index
    }

    // Utility function to print the array
    public static void printArray(int[] array) {
        for (int element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    // Main method to test the quick sort implementation
    public static void main(String[] args) {
        int[] array = {10, 7, 8, 9, 1, 5};

        System.out.println("Given Array:");
        printArray(array);

        quickSort(array, 0, array.length - 1);

        System.out.println("Sorted Array:");
        printArray(array);
    }
}
