<?php

include($_SERVER['DOCUMENT_ROOT'] . "/includes/error.php");

function passwordify($user, $pass)
{
	$key = "makeamericagreatagain";
	return (hash("whirlpool", $user . $key . $pass));
}

function checkConnect()
{
	if (!isset($_SESSION))
		session_start();
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
	$login = htmlspecialchars($_SESSION['login'], ENT_QUOTES);
	$hashpw = htmlspecialchars($_SESSION['password'], ENT_QUOTES);
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query_result = $pdo->query("SELECT * FROM `user` WHERE `login` = '$login' AND `pass` = '$hashpw';");
		if ($query_result->rowCount() != 1)
		{
			$_SESSION['login'] = '';
			$_SESSION['password'] = '';
			$_SESSION['id'] = '';
		}
	} catch (Exception $e) {
		echo "ERROR : " . $e->getMessage();
		die();
	}
}

checkConnect();

?>
