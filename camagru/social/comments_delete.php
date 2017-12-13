<?php

if (!isset($_SESSION))
	session_start();
include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
include($_SERVER['DOCUMENT_ROOT'] . "/includes/redirect_to_signin.php");
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

//Cleaning input
$comment_id = htmlspecialchars($_GET['comment_id'], ENT_QUOTES);
$commented_image_id = $_GET['commented_image_id'];

//Checking input
if (!isset($_GET['comment_id']) || $_GET['comment_id'] == '' || !isset($_GET['commented_image_id']) || $_GET['commented_image_id'] == '')
{
	header("Location: ./view.php?image_id=$commented_image_id");
	return ;
}

try {
	$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	//Checking for comment owner
	$query_result = $pdo->query("SELECT * FROM `comments` WHERE `comments`.`id` = '$comment_id';");

	$array = $query_result->fetch(PDO::FETCH_ASSOC);
	if ($array['owner_id'] != $_SESSION['id'])
	{
		//user is not the owner, moving
		header("Location: ./view.php?image_id=$commented_image_id");
		return ;
	}

	//user is the owner, deleting the comment
	$pdo->exec("DELETE FROM `comments` WHERE `id` = '$comment_id';");

	header("Location: ./view.php?image_id=$commented_image_id");

} catch (Exception $e) {
	echo "ERROR : " . $e->getMessage();
	die();
}

?>