#!/usr/bin/php
<?php

date_default_timezone_set('Europe/Paris');

$file = fopen("/var/run/utmpx", "r");

if ($file == false)
	exit;

$who = [];
$i = 0;

while (($buffer = stream_get_line($file, 628, '\0')) !== false)
{
	$format = "a256user/a4id/a32line/ipid/itype/l2time/a256host/i16pad";
	$data = unpack($format, $buffer);
	if ($data['type'] == 7)
	{
		$who[$i] = $data;
		$i++;
	}
}

foreach($who as $line)
{
	printf("%s  ", $line['user']);
	printf("%s  ", $line['line']);
	printf("%s\n", date("M  j H:i", $line['time1']));
}

?>