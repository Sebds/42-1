<?php

session_start();

include ("../lib/function.php");

if (getUserType() != 1)
{
	header("Location: ../");
	return ;
}

if (!isset($_GET['action']) || !isset($_GET['id']))
{
	header("Location: ./");
	return ;
}

$id = $_GET['id'];

if ($id == 1)
{
	header("Location: ./");
	return;
}

switch ($_GET['action'])
{
	case "vend":
		$sql = "UPDATE `client` SET `type` = '2' WHERE `client`.`id` = $id;";
		break;
	case "suppr":
		$sql = "DELETE FROM `client` WHERE `id` = '$id';";
		break;
	case "ban":
		$sql = "UPDATE `client` SET `type` = '-1' WHERE `client`.`id` = $id;";
		break;
	case "unban":
	case "user":
		$sql = "UPDATE `client` SET `type` = '0' WHERE `client`.`id` = $id;";
		break;
}

$conn = mysqli_connect("localhost", "vthomas", "password", "rush");
$res = mysqli_query($conn, $sql);

if ($res === false)
{
	header("Location: ./");
	return ;
}

if ($_GET['action'] == 'moddi')
{
	$line = mysqli_fetch_assoc($res);
	$type = $line['type'];

	if ($type == 1)
		$type = 2;
	else if ($type == 2)
		$type = 0;
	else if ($type == 0)
		$type = 1;

	$conn_2 = mysqli_connect("localhost", "vthomas", "password", "rush");
	$new_sql = "UPDATE `client` SET `type` = '$type' WHERE `client`.`id` = $id;";
	mysqli_query($conn_2, $new_sql);
	mysqli_close($conn_2);
}

mysqli_close($conn);
$act = $_GET['action'];
header("Location: ./index.php#user?$act");
?>
<br>
