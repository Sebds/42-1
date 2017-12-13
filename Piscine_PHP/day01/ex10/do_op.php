#!/usr/bin/php
<?php

function clean($str)
{
	$str = trim($str);
	$str = preg_replace('/\s\s+/', ' ', $str);
	return ($str);
}

if ($argc != 4)
{
	echo "Incorrect Parameters\n";
	exit;
}

$argv[1] = clean($argv[1]);
$argv[2] = clean($argv[2]);
$argv[3] = clean($argv[3]);

if (is_numeric($argv[1]) == false || is_numeric($argv[3]) == false)
{
	echo "Incorrect Parameters\n";
	exit;
}

if ($argv[2] != "+" && $argv[2] != "-" && $argv[2] != "*" && $argv[2] != "/" && $argv[2] != "%")
{
	echo "Incorrect Parameters\n";
	exit;
}

if ($argv[2] == "+")
	echo $argv[1] + $argv[3] . "\n";

if ($argv[2] == "-")
    echo $argv[1] - $argv[3] . "\n";

if ($argv[2] == "*")
    echo $argv[1] * $argv[3] . "\n";

if ($argv[2] == "/")
    echo $argv[1] / $argv[3] . "\n";

if ($argv[2] == "%")
    echo $argv[1] % $argv[3] . "\n";

?>