def linear_search(arr, target):
    for index, value in enumerate(arr):
        if value == target:
            return index  # Return the index of the found item
    return -1  # Return -1 if the item is not found

# Example usage
arr = [10, 20, 30, 40, 50]  # Sample array
target = 30  # Value to search for

result = linear_search(arr, target)

if result != -1:
    print(f"Element {target} found at index {result}.")
else:
    print(f"Element {target} not found in the array.")
