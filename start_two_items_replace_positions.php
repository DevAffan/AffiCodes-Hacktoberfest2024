<?php
//From this code the starting two items of an array will exchange there positions.
//like: ['a','b','c'] to ['b','a','c']

function changePosition(&$array) {
    $temp_array = array_slice($array, 0, 2);
    $temp_array = array_reverse($temp_array);
    $array = array_slice($array, 2);
    return array_merge($temp_array, $array );
};

$someArray = ['b' , 'a' , 'c'];

//it will replace starting two elements

echo changePosition($someArray);

//output ['a','b','c']

?>