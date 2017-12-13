<?php

session_start();
include 'function.php';
checkConnect();

if (!isset($_SESSION['id']) || !isset($_SESSION['basket']))
{
	header("Location: ./basket.php");
	return ;
}

$id = $_SESSION['id'];
$json = $_SESSION['basket'];

$conn_1 = mysqli_connect("localhost", "vthomas", "password", "rush");
$sql = "SELECT * FROM `basket` WHERE `id` = '$id';";
$res = mysqli_query($conn_1, $sql);
$line = mysqli_fetch_assoc($res);

if (!$line)
{
	$conn_2 = mysqli_connect("localhost", "vthomas", "password", "rush");
	$sql = "INSERT INTO `basket` (`id`, `json`) VALUES ('$id', '$json')";
	$res = mysqli_query($conn_2, $sql);

	header("Location: ./basket.php?message=saved");
}
else
{
	$conn_2 = mysqli_connect("localhost", "vthomas", "password", "rush");
	$sql = "UPDATE `basket` SET `json` = '$json' WHERE `id` = '$id';";
	$res = mysqli_query($conn_2, $sql);

	header("Location: ./basket.php?message=updated");
}
?>