#!/usr/bin/php
<?php
function ft_strsplit($str)
{
	$str = trim($str);
	$str = preg_replace('/\s\s+/', ' ', $str);
	$array = array_filter(explode(" ", $str), 'strlen');
	return ($array);
}

function customcmp($stra, $strb)
{
	$arr_a = str_split(strtolower($stra));
	$arr_b = str_split(strtolower($strb));

	$order = "abcdefghijklmnopqrstuvwxyz0123456789 !\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~";

	$i = 0;
	while ($i < strlen($stra) && $i < strlen($strb))
	{
		$pos_a = strpos($order, $arr_a[$i]);
		$pos_b = strpos($order, $arr_b[$i]);
		if ($pos_a != $pos_b)
			return ($pos_a - $pos_b);
		$i++;
	}
	return (0);
}

$array = [];
for ($i = 1; $i < $argc; $i++)
{
	$new_arr = ft_strsplit($argv[$i]);
	$array = array_merge($array, $new_arr);
}

usort($array, 'customcmp');

foreach ($array as $value)
	echo $value . "\n";
?>
