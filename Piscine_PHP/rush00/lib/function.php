<?php

function passwordify($usr, $pass)
{
	$key = "IciAussiOnAimeLesPoneys";
	return (hash("whirlpool", $user.$key.$pass));
}

function checkConnect()
{
	if (!isset($_SESSION['login']) || !isset($_SESSION['password']) || !isset($_SESSION['id']))
		return ;
	$login = htmlspecialchars($_SESSION['login'], ENT_QUOTES);
	$password = htmlspecialchars($_SESSION['password'], ENT_QUOTES);//Add for security
	$conn = mysqli_connect("localhost", "vthomas", "password", "rush");

	$sql = "SELECT * FROM `client` WHERE `name` = '$login' AND `pass` = '$password'";

	$res = mysqli_query($conn, $sql);
	if ($res === false)
		header("Location: ./connect.php?error=connect");
	$line = mysqli_fetch_assoc($res);
	$_SESSION['login'] = $line['name'];
	$_SESSION['password'] = $line['pass'];
	$_SESSION['id'] = $line['id'];
	if (!isset($_SESSION['basket']))
		$_SESSION['basket'] = $line['basket'];
	mysqli_close($conn);
}

function getUserType()
{
	if (!isset($_SESSION['login']) || !isset($_SEESSION['password']) || !isset($_SESSION['id']))
		checkConnect();
	$login = htmlspecialchars($_SESSION['login'], ENT_QUOTES);
	$password = htmlspecialchars($_SESSION['password'], ENT_QUOTES);//Add for security
	$conn = mysqli_connect("localhost", "vthomas", "password", "rush");

	$sql = "SELECT * FROM `client` WHERE `name` = '$login' AND `pass` = '$password'";

	$res = mysqli_query($conn, $sql);
	if ($res === false)
		header("Location: ./connect.php?error=connect");
	$line = mysqli_fetch_assoc($res);
	$i = $line['type'];
	mysqli_close($conn);
	return ($i);
}
?>
