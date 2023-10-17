<?php 

$numbers = [1, 2, 3, 4, 5];

// Using a traditional anonymous function to square each number
$squared = array_map(function($num) {
    return $num * $num;
}, $numbers);

echo "Squared numbers using traditional anonymous function: " . implode(', ', $squared) . PHP_EOL;

// Using an arrow function to square each number
$squaredArrow = array_map(fn($num) => $num * $num, $numbers);

echo "Squared numbers using arrow function: " . implode(', ', $squaredArrow) . PHP_EOL;


?>