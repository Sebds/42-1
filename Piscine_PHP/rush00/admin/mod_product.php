<?php

session_start();

include ("../lib/function.php");

if (getUserType() != 1 && getUserType() != 2)
{
	header("Location: ../");
	return ;
}

if (!isset($_POST['id']))
{
	header("Location: ./");
	return ;
}

$to_modify = $_POST['id'];

$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
$sql = "SELECT * FROM `articles` WHERE `id` = '$to_modify';";
$res = mysqli_query($conn, $sql);

$line = mysqli_fetch_assoc($res);

if ($res === false)
{
	header("Location: ../index.php");
	return ;
}

$new_name = htmlspecialchars($_POST['name'], ENT_QUOTES);
$new_desc = htmlspecialchars($_POST['description'], ENT_QUOTES);
$new_price = htmlspecialchars($_POST['price'], ENT_QUOTES);
$new_stock = htmlspecialchars($_POST['stock'], ENT_QUOTES);
$new_img = htmlspecialchars($_POST['img'], ENT_QUOTES);
$new_sex = htmlspecialchars($_POST['sexe'], ENT_QUOTES);
$new_categ = htmlspecialchars($_POST['categorie'], ENT_QUOTES);

mysqli_close($conn);

$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
$sql = "UPDATE `articles` SET `name` = '$new_name', `description` = '$new_desc', `price` = '$new_price', `stock` = '$new_stock', `img` = '$new_img', `sexe` = '$new_sex', `categ` = '$new_categ' WHERE `id` = '$to_modify';";
$res = mysqli_query($conn, $sql); 
mysqli_close($conn);

header("Location: ../edit.php")

?>
