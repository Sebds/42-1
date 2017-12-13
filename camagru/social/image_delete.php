<?php

if (!isset($_SESSION))
	session_start();
include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
include($_SERVER['DOCUMENT_ROOT'] . "/includes/redirect_to_signin.php");
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

//Verifying input
if (!isset($_GET['image_id']) || $_GET['image_id'] == '')
{
	header("Location: ./my_photos.php");
	return ;
}

//Cleaning input
$image_id = htmlspecialchars($_GET['image_id'], ENT_QUOTES);

try {
	$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	//searching for image info
	$query_result = $pdo->query("SELECT * FROM `images` WHERE `images`.`id` = '$image_id';");

	$array = $query_result->fetch(PDO::FETCH_ASSOC);
	if ($array['owner_id'] != $_SESSION['id'])
	{
		//image does not belong to user
		header("Location: my_photos.php");
		return ;
	}

	//Deleting image and related likes and comments
	$pdo->exec("DELETE FROM `images` WHERE `id` = '$image_id';");
	$pdo->exec("DELETE FROM `likes` WHERE `image_id` = '$image_id';");
	$pdo->exec("DELETE FROM `comments` WHERE `image_id` = '$image_id';");

	header("Location: my_photos.php");

} catch (Exception $e) {
	echo "ERROR : " . $e->getMessage();
	die();
}

?>