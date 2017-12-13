#!/usr/bin/php
<?php
	function ft_strsplit($str)
	{
		$str = trim($str);
		$str = preg_replace('/\s\s+/', ' ', $str);
		$array = array_filter(explode(" ", $str), 'strlen');
		return ($array);
	}

	if ($argc < 2)
		exit;
	$arr = ft_strsplit($argv[1]);
	$len = count($arr);
	array_push($arr, $arr[0]);
	array_shift($arr);
	foreach ($arr as $key=>$value)
	{
		echo $value;
		if ($key != count($arr) - 1)
			echo " ";
	}
	echo "\n";
?>