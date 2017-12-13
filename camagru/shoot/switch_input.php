<?php

session_start();

if ($_SESSION['input'] == 'webcam')
{
	$_SESSION['input'] = 'file';
	header("Location: ./shoot_file.php");
	return ;
}
if ($_SESSION['input'] == 'file')
{
	$_SESSION['input'] = 'webcam';
	header("Location: ./shoot_webcam.php");
	return ;
}

?>