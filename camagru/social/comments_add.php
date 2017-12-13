<?php

include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
include($_SERVER['DOCUMENT_ROOT'] . "/includes/redirect_to_signin.php");
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

if (!isset($_POST['image_to_comment']) || $_POST['image_to_comment'] == '' ||
	!isset($_POST['comment']) || $_POST['comment'] == '')
	return ;

$owner_id = $_SESSION['id'];
$owner_string = $_SESSION['login'];
$img = htmlspecialchars($_POST['image_to_comment'], ENT_QUOTES);
$comment =  htmlspecialchars($_POST['comment'], ENT_QUOTES);

try {
	$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$pdo->exec("INSERT INTO `comments` (`id`, `owner_id`, `owner_string`, `image_id`, `comment`) VALUES (NULL, '$owner_id', '$owner_string', '$img', '$comment');");

	$query_result = $pdo->query("SELECT * FROM `images` WHERE `id` = '$img';");
	$query_row = $query_result->fetch(PDO::FETCH_ASSOC);

	//Sending mail
	$to      = $query_row['mail'];
	$subject = 'The Camagru Project | Someone commented your pic !'; 
	$message = <<<EOD

Please click on the url below to see your commented pic.<br><br>

<a href=http://localhost:8080/social/view.php?image_id={$img} target='_blank'>See pic !</a><br><br>

	The Camagru Team.
EOD;
	$headers = 'From:camagru@42.fr' . "\r\n";
	$headers .= "Reply-To:camagru@42.fr\r\n";
	$headers .= "MIME-Version: 1.0\r\n";
	$headers .= "Content-Type: text/html; charset=utf-8\r\n";
	// mail($to, $subject, $message, $headers);

	echo $to . "<br>";
	echo $subject . "<br>";
	echo $message . "<br>";

	// header("Location: " . $_SERVER['HTTP_REFERER']);
} catch (Exception $e) {
	echo "ERROR : " . $e->getMessage();
	die();
}

?>