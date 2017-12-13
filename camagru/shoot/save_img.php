<?php

function RandomString($length = 5)
{
	$base_string = str_repeat($x='0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ', ceil($length / strlen($x)));
	$shuffled_string = str_shuffle($base_string);
	$final_string = substr($shuffled_string, 1, $length);

	return $final_string;
}

session_start();
include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
include($_SERVER['DOCUMENT_ROOT'] . "/includes/redirect_to_signin.php");
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
if ($_POST["action"] == "file")
	$mode = "file";
else if ($_POST["action"] == "webcam")
	$mode = "webcam";
else
{
	header("Location: ./shoot_file.php");
	return ;
}
if ($mode == "file")
{
	if (!$_FILES || !$_FILES['shoot_file'])
	{
		header("Location: ./shoot_file.php");
		return ;
	}
	if (!file_exists($_SERVER['DOCUMENT_ROOT'] . $filter) || !file_exists($_FILES['shoot_file']['tmp_name']))
	{
		header("Location: ./shoot_file.php");
		return ;
	}
}
if ($mode == "webcam")
{
	if (!$_POST['image_base'] || $_POST['image_base'] == '')
	{
		header("Location: ./shoot_webcam.php");
		return ;
	}
	if (!file_exists($_SERVER['DOCUMENT_ROOT'] . $filter) || !(base64_encode(base64_decode(explode(',', $_POST['image_base'])[1], true)) === explode(',', $_POST['image_base'])[1]))
	{
		header("Location: ./shoot_webcam.php");
		return ;
	}
}
if (!$_POST['filter'])
	$filter = '/filters/empty.png';
else
	$filter = $_POST['filter'];
$png = imagecreatefrompng($_SERVER['DOCUMENT_ROOT'] . $filter);
if ($mode == "file")
	$jpeg = imagecreatefromjpeg($_FILES['shoot_file']['tmp_name']);
if ($mode == "webcam")
{
	$jpeg = imagecreatefromstring(base64_decode(explode(',', $_POST['image_base'])[1]));
	imageflip($jpeg, IMG_FLIP_HORIZONTAL);
}
if ($mode == "file")
	list($width, $height) = getimagesize($_FILES['shoot_file']['tmp_name']);
if ($mode == "webcam")
	list($width, $height) = getimagesizefromstring(base64_decode(explode(',', $_POST['image_base'])[1]));
list($filter_w, $filter_h) = getimagesize($_SERVER['DOCUMENT_ROOT'] . $filter);
$out = imagecreatetruecolor(320, 240);
imagecopyresized($out, $jpeg, 0, 0, 0, 0, 320, 240, $width, $height);
imagecopyresized($out, $png, 0, 0, 0, 0, 320, 240, $filter_w, $filter_h);
date_default_timezone_set('Europe/Paris');

// for ($i = 0; $i < 100; $i++)
// {

$file = "/images/" . $_SESSION['login'] . date('_m-d-Y-h-i-s_', time()) . RandomString() . ".png";
$id = htmlspecialchars($_SESSION['id'], ENT_QUOTES);
$owner_string = htmlspecialchars($_SESSION['login'], ENT_QUOTES);
imagepng($out, $_SERVER['DOCUMENT_ROOT'] . $file);
try {
	$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$pdo->exec("INSERT INTO `images` (`id`, `file`, `owner_id`, `owner_string`, `date`) VALUES (NULL, '$file', '$id', '$owner_string', CURRENT_TIMESTAMP);");
	header("Location: /social/gallery.php");
	// return ;
} catch (Exception $e) {
	echo "ERROR : " . $e->getMessage();
	die();
}

// }

?>
