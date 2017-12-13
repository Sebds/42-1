<?php

if (!$_GET['action'] || !$_GET['name'])
	exit;

if ($_GET['action'] == 'set')
{
	if (!$_GET['value'])
		exit;
	setcookie($_GET['name'], $_GET['value'], time() + 3600);
}
if ($_GET['action'] == 'del')
{
	setcookie($_GET['name'], "", -1);
}
if ($_GET['action'] == 'get')
{
	foreach($_COOKIE as $key=>$value)
	{
		if ($key == $_GET['name'])
		{
			echo $_COOKIE[$key]. "\n";
		}
	}
}

?>