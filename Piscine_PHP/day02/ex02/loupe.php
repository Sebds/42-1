#!/usr/bin/php
<?php

if ($argc != 2)
	exit;

$file = file($argv[1]);

if ($file == false)
	exit;

foreach ($file as $line)
{
	$match = preg_match('@(<a.*?href=.*?\stitle=)(.*?)(>)(.*?)(</a?>)@', $line);

	if ($match)
	{
		$line = preg_replace_callback('@(<a.*?href=.*?\stitle=)(.*?)(>)(.*?)(</a?>)@', function ($matches) {
				$new_line = $matches[1] . strtoupper($matches[2]) . $matches[3] . strtoupper($matches[4]) . $matches[5];
				return $new_line;
			}, $line);
	}
	
	$match = preg_match('@(<a.*?href=.*?)(>)(.*?)(<.*?>)(</a?>)@', $line);
	
	if ($match)
	{
		$line = preg_replace_callback('@(<a.*?href=.*?)(>)(.*?)(<.*?>)(</a?>)@', function ($matches) {
			$new_line = $matches[1] . $matches[2] . strtoupper($matches[3]) . $matches[4] . $matches[5];
			return ($new_line);
		}
		, $line);
	}
	
	echo $line;
}
?>