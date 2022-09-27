<?php

/*
 * Complete the 'compareTriplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

function compareTriplets($a, $b) {
    // Write your code here
    $ans = [0,0];
    $Alice = 0;
    $Bob = 0;
    for($i=0; $i<=3; $i++){
        if($a[$i] == $b[$i]){
            // return;
        }
        elseif($a[$i] < $b[$i]){
            $Bob = 1 + $Bob; 
        }
        else{
            $Alice = 1 + $Alice; 
        }
    }
    $ans[0] = $Alice;
    $ans[1] = $Bob;
    return $ans;
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$a_temp = rtrim(fgets(STDIN));

$a = array_map('intval', preg_split('/ /', $a_temp, -1, PREG_SPLIT_NO_EMPTY));

$b_temp = rtrim(fgets(STDIN));

$b = array_map('intval', preg_split('/ /', $b_temp, -1, PREG_SPLIT_NO_EMPTY));

$result = compareTriplets($a, $b);

fwrite($fptr, implode(" ", $result) . "\n");

fclose($fptr);
