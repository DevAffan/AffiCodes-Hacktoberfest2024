<?php

//change position Of an Element in an Array By just giving index Numbers

function MoveItem(&$array, $from, $to) {
    $out = array_splice($array, $from, 1);
    array_splice($array, $to, 0, $out);
}

$array = ['a','c','d','b','e'];

MoveItem($array, 3, 1);

echo $array;


//Output: ['a','b','c','d','e']





?>