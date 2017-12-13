<?php

session_start();

include 'function.php';
checkConnect();

if (!isset($_GET['id']) || !isset($_GET['action']))
	header("Location: ../index.php?error=quantity");

$id = $_GET['id'];
$quantity = ($_GET['action'] == "plus") ? 1 : -1;

$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
$sql = "SELECT * FROM `articles` WHERE `id` = $id;";
$res = mysqli_query($conn, $sql);
$line = mysqli_fetch_assoc($res);
//mysqli_close($conn);
if (intval($line['stock']) <= 0 && $quantity == 1)
{
	header("Location: ./basket.php?error=stock");
}
else
{
	if (isset($_SESSION['basket']))
	{
		$j = json_decode($_SESSION['basket']);
	}
	//var_dump($j);
	$i = 0;
	foreach ($j as $v)
	{
		if ($v->id == $id)
		{
			if ($quantity == -1 && $v->quantite <= 1)
				unset($j[$i]);
			else
				$v->quantite += $quantity;
		}
		$i++;
	}

	$j = json_encode($j);
	$_SESSION['basket'] = $j;

	$sql = "SELECT * FROM `articles` WHERE `id` = $id;";
	$res = mysqli_query($conn, $sql);
	$line = mysqli_fetch_assoc($res);
	$quantite = intval($line['stock']) + (($_GET['action'] == "plus") ? -1 : 1);
	$sql = "UPDATE `articles` SET `stock` = '$quantite' WHERE `id` = $id;";
	$res = mysqli_query($conn, $sql);
	mysqli_close($conn);

	header("Location: ./basket.php");
}

?>
