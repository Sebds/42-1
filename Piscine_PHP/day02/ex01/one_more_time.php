#!/usr/bin/php
<?php

if ($argc != 2)
	exit;

$match = preg_match("/^(\bLundi\b|\bMardi\b|\bMercredi\b|\bJeudi\b|\bVendredi\b|\bSamedi\b|\bDimanche\b) ([0-3][0-9]) (\bJanvier\b|\bFevrier\b|\bMars\b|\bAvril\b|\bMai\b|\bJuin\b|\bJuillet\b|\bAout\b|\bSeptembre\b|\bOctobre\b|\bNovembre\b|\bDecembre\b) (19[789]\d|20[0-9]\d) ([0-2][0-9]):([0-5][0-9]):([0-5][0-9])$/", $argv[1]);

if ($match)
{
	date_default_timezone_set('Europe/Paris');

	$new_date = $argv[1];

	$new_date = preg_replace('/(^Lundi)/', 'Monday', $new_date);
	$new_date = preg_replace('/(^Mardi)/', 'Tuesday', $new_date);
	$new_date = preg_replace('/(^Mercredi)/', 'Wednesday', $new_date);
	$new_date = preg_replace('/(^Jeudi)/', 'Thursday', $new_date);
	$new_date = preg_replace('/(^Vendredi)/', 'Friday', $new_date);
	$new_date = preg_replace('/(^Samedi)/', 'Saturday', $new_date);
	$new_date = preg_replace('/(^Dimanche)/', 'Sunday', $new_date);

	$new_date = preg_replace('/Janvier/', 'January', $new_date);
	$new_date = preg_replace('/Fevrier/', 'February', $new_date);
	$new_date = preg_replace('/Mars/', 'March', $new_date);
	$new_date = preg_replace('/Avril/', 'April', $new_date);
	$new_date = preg_replace('/Mai/', 'May', $new_date);
	$new_date = preg_replace('/Juin/', 'June', $new_date);
	$new_date = preg_replace('/Juillet/', 'July', $new_date);
	$new_date = preg_replace('/Aout/', 'August', $new_date);
	$new_date = preg_replace('/Septembre/', 'September', $new_date);
	$new_date = preg_replace('/Octobre/', 'October', $new_date);
	$new_date = preg_replace('/Novembre/', 'November', $new_date);
	$new_date = preg_replace('/Decembre/', 'December', $new_date);

	echo strtotime($new_date) . "\n";
}
else
	echo "Wrong Format\n";

?>