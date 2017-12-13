#!/usr/bin/php
<?php

function ft_clean($str)
{
	$str = trim($str);
	$str = preg_replace('/\s\s+/', ' ', $str);
	return ($str);
}

if ($argc < 2)
	exit;
echo ft_clean($argv[1]) . "\n";

?>