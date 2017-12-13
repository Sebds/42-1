<?php

include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
include($_SERVER['DOCUMENT_ROOT'] . "/includes/redirect_to_signin.php");
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

if (!isset($_POST['image_id']) || $_POST['image_id'] == '')
	return ;

$owner_id = $_SESSION['id'];
$img_id = htmlspecialchars($_POST['image_id'], ENT_QUOTES);

try {
	$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$pdo->exec("DELETE FROM `likes`  WHERE `owner_id` = '$owner_id' AND `image_id` = '$img_id';");
	header("Location: " . $_SERVER['HTTP_REFERER']);
} catch (Exception $e) {
	echo "ERROR : " . $e->getMessage();
	die();
}

?>