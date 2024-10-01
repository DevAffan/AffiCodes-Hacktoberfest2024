def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2  # Calculate the mid index

        # Check if the target is at the mid index
        if arr[mid] == target:
            return mid  # Return the index of the found item
        # If the target is greater, ignore the left half
        elif arr[mid] < target:
            left = mid + 1
        # If the target is smaller, ignore the right half
        else:
            right = mid - 1

    return -1  # Return -1 if the item is not found

# Example usage
arr = [10, 20, 30, 40, 50]  # Sample sorted array
target = 30  # Value to search for

result = binary_search(arr, target)

if result != -1:
    print(f"Element {target} found at index {result}.")
else:
    print(f"Element {target} not found in the array.")
