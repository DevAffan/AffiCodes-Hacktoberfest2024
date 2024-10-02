#include <stdio.h>
#include <stdlib.h> 

// An iterative binary search function.
int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

// Driver code
int main(void)
{
    int n, x;

    // Taking the number of elements in the array as input
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int*)malloc(n * sizeof(int));

    // Taking array elements as input
    printf("Enter %d elements (sorted):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Element you want to search
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if(result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);

    // Free the allocated memory
    free(arr);

    return 0;
}
