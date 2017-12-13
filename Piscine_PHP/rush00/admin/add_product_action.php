<?php

session_start();

include '../lib/function.php';
$type = getUserType();

if ($type != 1 && $type != 2) //Ni admin ni vendeur
{
	header("Location: ../?error=badaccount");
	return;
}

$poss = $_SESSION['id'];

$new_name = htmlspecialchars($_POST['name'], ENT_QUOTES);
$new_desc = htmlspecialchars($_POST['description'], ENT_QUOTES);
$new_price = htmlspecialchars($_POST['price'], ENT_QUOTES);
$new_stock = htmlspecialchars($_POST['stock'], ENT_QUOTES);
$new_img = htmlspecialchars($_POST['img'], ENT_QUOTES);
$new_sex = htmlspecialchars($_POST['sexe'], ENT_QUOTES);
$new_categ = htmlspecialchars($_POST['categorie'], ENT_QUOTES);

$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
$sql = "INSERT INTO `articles` (`id`, `last_change`, `name`, `description`, `price`, `stock`, `img` , `sexe`, `categ`, `poss`) VALUES (NULL, NULL, '$new_name', '$new_desc', '$new_price', '$new_stock', '$new_img', '$new_sex', '$new_categ', '$poss')";
$res = mysqli_query($conn, $sql);

mysqli_close($conn);

header("Location: ../edit.php");
?>