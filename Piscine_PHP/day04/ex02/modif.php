<?php

function ft_strlen($str)
{
	$i = 0;
	while ($str[$i] != '')
		$i++;
	return ($i);
}

$login = NULL;
$oldpwd = NULL;
$newpwd = NULL;
$ok = false;

foreach($_POST as $key=>$value)
{
	if ($key == 'login' && ft_strlen($_POST['login']))
	{
		$login = $_POST['login'];
	}
	if ($key == 'oldpw' && ft_strlen($_POST['oldpw']))
	{
		$oldpwd = $_POST['oldpw'];
	}
	if ($key == 'newpw' && ft_strlen($_POST['newpw']))
	{
		$newpwd = $_POST['newpw'];
	}
	if ($key == 'submit' && $value == 'OK')
	{
		$ok = true;
	}
}

if (!$login || !$oldpwd || !$newpwd || !$ok)
{
	echo "ERROR\n";
}
else
{
//	if ((!file_exists("./private")) || (!file_exists("./private/passwd")))
//	{
//		echo "ERROR\n";
//		exit;
//	}

	$file = file_get_contents("./private/passwd");
	$u_file = unserialize($file);

	$found = false;
	foreach ($u_file as $key => $array)
	{
		if ($array['login'] == $login)
		{
			$found = true;
			$found_tab = $array;
			$index = $key;
		}
	}

	if (!$found)
		echo "ERROR\n";
	else
	{
		$u_oldpwd = $found_tab['passwd'];
		$oldpwd = hash('whirlpool', $oldpwd);

		if ($oldpwd != $u_oldpwd)
		{
			echo "ERROR\n";
		}
		else
		{
			$newpwd = hash('whirlpool', $newpwd);

			$u_file[$index]['passwd'] = $newpwd;

			file_put_contents("./private/passwd", serialize($u_file));
			echo "OK\n";
		}
	}
}
?>