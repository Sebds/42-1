<?php

function auth($login, $passwd)
{
	if ($login == NULL || $passwd == NULL)
		return (false);
//	if (!file_exists("./private/passwd"))
//		return (false);

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
		return (false);

	$passwd = hash('whirlpool', $passwd);
	if ($passwd != $u_file[$index]['passwd'])
		return (false);
	return (true);
}

?>