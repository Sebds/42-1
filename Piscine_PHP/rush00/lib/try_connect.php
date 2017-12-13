<?php
session_start();

include './function.php';

if (!isset($_POST['login']) || !isset($_POST['password']))
	header("Location: ./connect.php?error=connect");

$login = htmlspecialchars($_POST['login'], ENT_QUOTES);
$password = passwordify($login, $_POST['password']);
$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');

$sql = "SELECT * FROM `client` WHERE `name` = '$login' AND `pass` = '$password'";

$res = mysqli_query($conn, $sql);
if ($res === false)
	header("Location: ./connect.php?error=connect");
$line = mysqli_fetch_assoc($res);

if (!$line['name'] || $line['name'] == '')
{
	header("Location: ./connect.php?error=connect");
	return ;
}
if ($line['type'] == -1) //BANNED
{
	header("Location: ./connect.php?error=ban");
	return ;
}
$_SESSION['login'] = $line['name'];
$_SESSION['password'] = $line['pass'];
$_SESSION['id'] = $line['id'];
$_SESSION['type'] = $line['type'];
mysqli_close($conn);
header("Location: ../index.php");
?>
