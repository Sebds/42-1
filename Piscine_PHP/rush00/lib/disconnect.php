<?php
session_start();
$_SESSION['login'] = '';
$_SESSION['password'] = '';
$_SESSION['id'] = '';
$_SESSION['type'] = '';
$_SESSION['basket'] = '';

$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
$sql = "DELETE FROM `panier`;";
$res = mysqli_query($conn, $sql);

header("Location: ../index.php");
?>