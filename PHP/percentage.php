<?php
// Short Program to get Percentage 

function percentage($marks , $total){
	$percentage = number_format(($marks * 100)/$total , 2);
    return $percentage;
}

//Output Answer
echo percentage( 300 , 550);
?>