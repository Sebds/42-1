<?php

session_start();

include 'function.php';
checkConnect();

if (!isset($_POST['basket_add']) && !isset($_POST['clear']))
	header("Location: ../index.php?error=add");

$id_to_add = $_POST['basket_add'];

if (!is_numeric($id_to_add) || $id_to_add <= 0)
	header("Location: ../index.php?error=add");


$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
$sql = "SELECT * FROM `articles` WHERE `id` = '$id_to_add';";
$res = mysqli_query($conn, $sql);

if ($res === false)
{
	header("Location: ../index.php");
	return;
}

$line = mysqli_fetch_assoc($res);

$id_prod = $id_to_add;
$name = $line['name'];
$price = $line['price'];
$img = $line['img'];

//mysqli_close($conn);

if (isset($_SESSION['basket']))
{
	$j = json_decode($_SESSION['basket']);
}

$t = false;
if ($j)
{
	foreach ($j as $v)
	{
		if ($v->id == $id_prod)
		{
				$t = true;
				$v->quantite += 1;
		}
	}
}
if (!$t)
{
	$j[] = array("id" => $id_prod,
	"name" => $name,
	"price" => $price,
	"quantite" => 1,
	"img" => $img);
}

$sql = "SELECT * FROM `articles` WHERE `id` = $id_prod;";
$res = mysqli_query($conn, $sql);
$line = mysqli_fetch_assoc($res);

$quantite = intval($line['stock']) - 1;
//var_dump($quantite);
$sql = "UPDATE `articles` SET `stock` = '$quantite' WHERE `id` = $id_prod;";
$res = mysqli_query($conn, $sql);

$j = json_encode($j);
$_SESSION['basket'] = $j;
$myid = $_SESSION['id'];


if ($myid)
{
	$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
	$sql = "UPDATE `client` SET `basket` = '$j' WHERE `client`.`id` = $myid";
	$res = mysqli_query($conn, $sql);
}
mysqli_close($conn);
header("Location: ./basket.php");

?>
