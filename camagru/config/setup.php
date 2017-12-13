<?php

include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
if (file_exists($_SERVER['DOCUMENT_ROOT'] . '/images'))
{
	array_map('unlink', glob($_SERVER['DOCUMENT_ROOT'] . "/images/*.*"));
    rmdir($_SERVER['DOCUMENT_ROOT'] . "/images");
}
mkdir($_SERVER['DOCUMENT_ROOT'] . '/images', 0777, true);
try {
	$pdo = new PDO('mysql:host=127.0.0.1;', $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$pdo->exec("DROP DATABASE IF EXISTS Camagru;");
	$pdo->exec("CREATE DATABASE Camagru;");
	$pdo->exec("CREATE TABLE `Camagru`.`user`     (`id` INT NOT NULL AUTO_INCREMENT , `login`    TEXT NOT NULL , `pass`         TEXT NOT NULL , `mail`         TEXT NOT NULL , `hash` TEXT        NOT NULL , `active` INT( 1 ) NOT NULL DEFAULT '0' , PRIMARY KEY (`id`)) ENGINE = InnoDB;");
	$pdo->exec("CREATE TABLE `Camagru`.`images`   (`id` INT NOT NULL AUTO_INCREMENT , `file`     TEXT NOT NULL , `owner_id`     INT  NOT NULL , `owner_string` TEXT NOT NULL , `date` DATETIME             ,                                          PRIMARY KEY (`id`)) ENGINE = InnoDB;");
	$pdo->exec("CREATE TABLE `Camagru`.`likes`    (`id` INT NOT NULL AUTO_INCREMENT , `owner_id` INT  NOT NULL , `image_id`     INT  NOT NULL ,                                                                                                       PRIMARY KEY (`id`)) ENGINE = InnoDB;");
	$pdo->exec("CREATE TABLE `Camagru`.`comments` (`id` INT NOT NULL AUTO_INCREMENT , `owner_id` INT  NOT NULL , `owner_string` TEXT NOT NULL , `image_id`     INT  NOT NULL , `comment` TEXT     NOT NULL ,                                          PRIMARY KEY (`id`)) ENGINE = InnoDB DEFAULT CHARSET=utf8;");
} catch (Exception $e) {
	echo "ERROR : " . $e->getMessage();
	die();
}
header("Location: /index.php?error=SuccessfullInstall");

?>