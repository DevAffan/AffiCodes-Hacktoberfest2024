<?php

function quickSort(array $array): array {
    // Base case: arrays with 0 or 1 element are already "sorted"
    if (count($array) < 2) {
        return $array;
    }

    // Choose a pivot element
    $pivot = $array[0];
    
    // Partitioning step: elements smaller than the pivot, elements greater than the pivot
    $left = array_filter(array_slice($array, 1), fn($x) => $x <= $pivot);
    $right = array_filter(array_slice($array, 1), fn($x) => $x > $pivot);
    
    // Recursively apply quicksort to left and right arrays, then merge
    return array_merge(quickSort($left), [$pivot], quickSort($right));
}

// Example usage:
$array = [3, 6, 8, 10, 1, 2, 1];
$sortedArray = quickSort($array);
print_r($sortedArray);
