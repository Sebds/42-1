#!/usr/bin/php
<?php
	function ft_split($str)
	{
		$str = trim($str);
		$str = preg_replace('/\s\s+/', ' ', $str);
		$array = array_filter(explode(" ", $str), 'strlen');
		sort($array);
		return ($array);
	}
?>