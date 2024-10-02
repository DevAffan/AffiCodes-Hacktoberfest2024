import java.util.*;

public class QuickSort {
    public static void main(String[] args) {
        int[] arr = {5, 4, 3, 2, 1};  // Example array to be sorted
        quicksort(arr, 0, arr.length - 1);  // Call quicksort on the entire array
        System.out.println(Arrays.toString(arr));  // Print the sorted array
    }

    // Quicksort function to recursively sort the array
    static void quicksort(int[] nums, int low, int high) {
        // Base condition: If the subarray has one or zero elements, it's already sorted
        if (low >= high) {
            return;
        }

        // Initialize the start and end pointers
        int s = low, e = high;

        // Find the middle index to select a pivot element
        int m = s + (e - s) / 2;
        int pivot = nums[m];  // Choose the middle element as the pivot

        // Partitioning process to place the pivot in its correct position
        while (s <= e) {
            // Move the start pointer right until finding an element greater than or equal to pivot
            while (nums[s] < pivot) {
                s++;
            }
            // Move the end pointer left until finding an element smaller than or equal to pivot
            while (nums[e] > pivot) {
                e--;
            }

            // If the start pointer is less than or equal to the end pointer, swap the elements
            // This ensures that all elements on the left side of the pivot are smaller,
            // and all elements on the right side are larger
            if (s <= e) {
                int temp = nums[s];
                nums[s] = nums[e];
                nums[e] = temp;
                s++;
                e--;
            }
        }

        // Recursively sort the left and right subarrays
        // Sort the left part of the array (elements smaller than pivot)
        quicksort(nums, low, e);

        // Sort the right part of the array (elements larger than pivot)
        quicksort(nums, s, high);
    }
}
