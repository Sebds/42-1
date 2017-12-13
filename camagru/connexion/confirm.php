<?php

if (!isset($_SESSION))
	session_start();
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
if (!isset($_GET['login']) || $_GET['login'] == '' || !isset($_GET['mail']) || $_GET['mail'] == '' || !isset($_GET['hash']) || $_GET['hash'] == '')
{
	header("location: ./signup.php");
	return ;
}
$login = htmlspecialchars($_GET['login'], ENT_QUOTES);
$mail = htmlspecialchars($_GET['mail'], ENT_QUOTES);
$hash = htmlspecialchars($_GET['hash'], ENT_QUOTES);
try {
	$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$query_result = $pdo->query("SELECT * FROM `user` WHERE `login` = '$login' AND `mail` = '$mail' AND `hash` = '$hash' AND `active` = '0';");
	if ($query_result->rowCount() != 1)
	{
		header("Location: ./signup.php?error=UnvalidConfirmation");
		return ;
	}
	$pdo->exec("UPDATE `user` SET `active` = '1' WHERE `login` = '$login' AND `hash` = '$hash';");
	header("Location: ./signin.php?error=ActiveAccount");
} catch (Exception $e) {
	echo "ERROR : " . $e->getMessage();
	die();
}

?>