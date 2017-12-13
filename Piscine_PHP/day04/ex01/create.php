<?php

function ft_strlen($str)
{
	$i = 0;
	while ($str[$i] != '')
		$i++;
	return ($i);
}

$passwd = NULL;
$login = NULL;
$ok = false;

foreach($_POST as $key=>$value)
{
	if ($key == 'login' && ft_strlen($_POST['login']))
	{
		$login = $_POST['login'];
	}
	if ($key == 'passwd' && ft_strlen($_POST['passwd']))
	{
		$passwd = $_POST['passwd'];
	}
	if ($key == 'submit' && $value == 'OK')
	{
		$ok = true;
	}
}

if (!$login || !$passwd || !$ok)
{
	echo "ERROR\n";
}
else
{
	if (!file_exists("./private"))
		mkdir("./private");
	if (!file_exists("./private/passwd"))
		file_put_contents("./private/passwd", serialize(array(array('login' => '', 'passwd' => ''))));

	$file = file_get_contents("./private/passwd");
	$u_file = unserialize($file);

	foreach ($u_file as $array)
	{
		if ($array['login'] == $login)
		{
			echo "ERROR\n";
			exit;
		}
	}
	
	$passwd = hash('whirlpool', $passwd);

	$u_file[] = array('login' => $login, 'passwd' => $passwd);

	file_put_contents("./private/passwd", serialize($u_file));
	echo "OK\n";
}
?>