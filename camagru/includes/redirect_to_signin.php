<?php

if (basename(__FILE__) == basename($_SERVER["SCRIPT_FILENAME"]))
{
	header("Location: /includes/index.php");
	exit ;
}

if ((!isset($_SESSION['login']) || empty($_SESSION['login']) || !isset($_SESSION['password']) || empty($_SESSION['password'] || !is_numeric($_SESSION['id']) || $_SESSION['id'] <= 0)))
{
	header("Location: /connexion/signin.php");
	return ;
}

?>