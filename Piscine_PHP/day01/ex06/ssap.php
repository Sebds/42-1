#!/usr/bin/php
<?php
	function ft_strsplit($str)
	{
		$str = trim($str);
		$str = preg_replace('/\s\s+/', ' ', $str);
		$array = array_filter(explode(" ", $str), 'strlen');
		return ($array);
	}

	$array = [];
	for ($i = 1; $i < $argc; $i++)
	{
		$new_arr = ft_strsplit($argv[$i]);
		$array = array_merge($array, $new_arr);
	}
	sort($array);

	for ($i = 0; $i < count($array); $i++)
		echo $array[$i] . "\n";
?>