<?php
session_start();

include './function.php';

if (!isset($_POST['login']) || !isset($_POST['password']) || !isset($_POST['secpassword']))
	header("Location: ./connect.php?error=connect");

$login = htmlspecialchars($_POST['login'], ENT_QUOTES);
$password = passwordify($login, $_POST['password']);
$conn = mysqli_connect("localhost", "vthomas", "password", "rush");

$check_login = "SELECT * FROM `client` WHERE `name` = '$login';";

$check_res = mysqli_query($conn, $check_login);

$check_tab = mysqli_fetch_assoc($check_res);

if ($check_tab['name'] == $login)
{
	header("Location: ./connect.php?error=login");
	return;
}

$type = $_POST['salesman'] + 0;

$sql = "INSERT INTO `client` (`id`, `name`, `pass`, `type`, `basket`) VALUES (NULL, '$login', '$password', '$type', '')";

$res = mysqli_query($conn, $sql);

mysqli_close($conn);

// if (!isset($_SESSION['login']) || !isset($_SESSION['password']) || !isset($_SESSION['id']))
	// return ;
$login = htmlspecialchars($_SERVER['login'], ENT_QUOTES);
$password = htmlspecialchars($_SERVER['password'], ENT_QUOTES);//Add for security
$conn = mysqli_connect("localhost", "vthomas", "password", "rush");

$sql = "SELECT * FROM `client` WHERE `name` = '$login' AND `pass` = '$password'";

$res = mysqli_query($conn, $sql);
if ($res === false)
	header("Location: ./connect.php?error=connect");
$line = mysqli_fetch_assoc($res);
$_SESSION['login'] = $line['name'];
$_SESSION['password'] = $line['pass'];
$_SESSION['id'] = $line['id'];
mysqli_close($conn);
header("Location: ../index.php?value=created");
?>
