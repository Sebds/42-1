<?php

if (!isset($_SESSION))
	session_start();

$_SESSION['login'] = '';
$_SESSION['password'] = '';
$_SESSION['id'] = '';
$_SESSION['input'] = "webcam";

header("Location: /");

?>