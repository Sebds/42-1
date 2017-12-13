<?php

session_start();

include ("../lib/function.php");
checkConnect();

if (!isset($_SESSION['login']) || !isset($_SESSION['password']) || $_SESSION['login'] == 'admin')
{
	header("Location: ../index.php");
	return ;
}
else
{
	$login = $_SESSION['login'];
	$password = $_SESSION['password'];
}

$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
$sql = "DELETE FROM `client` WHERE `name` = '$login' AND `pass` = '$password';";
$res = mysqli_query($conn, $sql);
mysqli_close($conn);

header("Location: ../index.php?value=deleted");
?>
