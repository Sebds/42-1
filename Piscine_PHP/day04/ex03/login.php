<?php

function ft_strlen($str)
{
	$i = 0;
	while ($str[$i] != '')
		$i++;
	return ($i);
}

include("auth.php");

session_start();

$login = NULL;
$passwd = NULL;

foreach ($_GET as $key => $value)
{
	if ($key == 'login' && ft_strlen($_GET['login']))
	{
		$login = $_GET['login'];
	}
	if ($key == 'passwd' && ft_strlen($_GET['passwd']))
	{
		$passwd = $_GET['passwd'];
	}
}

if (!$login || !$passwd)
{
	echo "ERROR\n";
	$_SESSION['loggued_on_user'] = '';
}
else
{
	if (auth($login, $passwd))
	{
		echo "OK\n";
		$_SESSION['loggued_on_user'] = $login;
	}
	else
	{
		echo "ERROR\n";
		$_SESSION['loggued_on_user'] = '';
	}
}

?>