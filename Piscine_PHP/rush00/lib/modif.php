<?php

session_start();

include 'function.php';

if (!isset($_SESSION['login']) || !isset($_POST['oldpw']) || !isset($_POST['newpw']))
{
	header("Location: ../index.php");
	return ;
}
else
{
	$login = $_SESSION['login'];
	$oldpw = passwordify($login, $_POST['oldpw']);
	$newpw = passwordify($login, $_POST['newpw']);
}

if ($oldpw != $_SESSION['password'])
{
	header("Location: ./account.php?error=password");
	return ;
}

$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
$sql = "UPDATE `client` SET `pass` = '$newpw' WHERE `name` = '$login';";
$res = mysqli_query($conn, $sql); 

if ($res == false)
{
	header("Location: ../index.php");
}

$_SESSION['password'] = $newpw;

mysqli_close($conn);

header("Location: ./account.php?value=modified");
?>