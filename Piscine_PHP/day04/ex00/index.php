<?php

session_start();

function ft_strlen($str)
{
	$i = 0;
	while ($str[$i] != '')
		$i++;
	return ($i);
}

$ok = false;
foreach($_GET as $key=>$value)
	if ($key == 'submit' && $value == 'OK')
		$ok = true;

foreach($_GET as $key=>$value)
{
	if ($key == 'login' && $ok == true)
	{
		$_SESSION['login'] = $value;
	}
	if ($key == 'passwd' && $ok == true)
	{
		$_SESSION['passwd'] = $value;
	}
}

if (!$_SESSION['login'] || !$_SESSION['passwd'] || !ft_strlen($_SESSION['login']) || !ft_strlen($_SESSION['passwd']))
{
	$_SESSION['login'] = "";
	$_SESSION['passwd'] = "";
}

?>
<html><body>
<form action="index.php" method="get">
	Identifiant: <input type="text" name="login" value=<?php session_start(); echo $_SESSION['login']; ?> >
	<br />
	Mot de passe: <input type="password" name="passwd" value=<?php session_start(); echo $_SESSION['passwd']; ?> >
	<input type="submit" name="submit" value="OK">
</form>
</body></html>