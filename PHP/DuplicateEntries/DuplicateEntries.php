<?php 

function remove_duplicates($var) {

    // appplying logic to remove duplicate numbers
    $array = array();
    foreach ($var as $v) {
        if(! in_array($v, $array)) {
            $array[] = $v;
        }
    }
    sort($array);
    return $array;

}


echo implode(", ", remove_duplicates([1,2,3,5,7,8,2,3,1,3,4,7,9,2,2]));


?>