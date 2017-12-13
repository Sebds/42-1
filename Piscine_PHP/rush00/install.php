<div align="center">
<?php
include 'lib/function.php';

$conn = mysqli_connect("localhost", "vthomas", "password");
$adm_pass = passwordify("admin", "admin");

$sql = array(
	"DROP DATABASE IF EXISTS rush",
	"CREATE DATABASE rush"
);

echo "<table style='width: 100%;' border='1px' cellspacing='0'>";
foreach ($sql as $key)
{
	if (mysqli_query($conn, $key) === TRUE)
		echo "<tr><td><code>$key</code></td><td><b style='color: #27ae60; text-align: center;'>SUCCESS</b></td></tr>";
	else
		echo "<tr><td><code>$key</code></td><td><b style='color: #c0392b; text-align: center;'>ERROR</b></td></tr>";
}
//$conn->close();


/* ************************************************************************** */
/*                         INITIALISATION DE LA DB RUSH                       */
/* ************************************************************************** */

//$conn = new mysqli($serv, $user, $pass, "rush");
//if ($conn->connect_error) {
//	die("Connection failed: " . $conn->connect_error);
//}
mysqli_select_db($conn, 'rush');

$sql = array(
	"CREATE TABLE `rush`.`client` ( `id` INT NOT NULL AUTO_INCREMENT , `name` TEXT NOT NULL , `pass` TEXT NOT NULL , `type` INT NOT NULL , `basket` TEXT NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;",
	"CREATE TABLE `rush`.`articles` ( `id` INT NOT NULL AUTO_INCREMENT , `last_change` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP , `name` TEXT NOT NULL , `description` TEXT NOT NULL , `price` INT NOT NULL , `stock` INT NOT NULL , `img` TEXT NOT NULL , `sexe` INT NOT NULL , `categ` TEXT NOT NULL , `poss` INT NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;",
	"CREATE TABLE `rush`.`categorie` ( `id` INT NOT NULL AUTO_INCREMENT , `name` TEXT NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;",
	"CREATE TABLE `rush`.`basket` ( `id` INT NOT NULL, `json` TEXT NOT NULL, PRIMARY KEY (`id`)) ENGINE = InnoDB;",
	"INSERT INTO `client` (`id`, `name`, `pass`, `type`, `basket`) VALUES (NULL, 'admin', '$adm_pass', '1', '')",
	"INSERT INTO `categorie` (`id`, `name`) VALUES (NULL, 'one piece')",
	"INSERT INTO `categorie` (`id`, `name`) VALUES (NULL, 'miku')",
	"INSERT INTO `categorie` (`id`, `name`) VALUES (NULL, 'chill')",
	"INSERT INTO `categorie` (`id`, `name`) VALUES (NULL, 'en action')",
	"INSERT INTO `categorie` (`id`, `name`) VALUES (NULL, 'dragon ball')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Luffy avec hache dans le dos',				'Petite statuette de Luffy',									'12', '20', 'img_0.png',	'0', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Personnage feminim &eacute;p&eacute;iste',	'Petite statuette de personnage avec une &eacute;p&eacute;e',	'26', '20', 'img_1.png',	'1', '2',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Personnage feminim normal',					'Petite statuette de personnage',								'20', '20', 'img_2.png',	'1', '2',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Ace',							'Petite statuette de Ace aux poings ardents',					'31', '20', 'img_3.png',	'0', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Trafalgar',						'Petite statuette de Trafalgar Law torse nu',					'21', '20', 'img_4.png',	'0', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Sabot',							'Petite statuette de Sabot',									'25', '20', 'img_5.png',	'0', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de luffy',							'Petite statuette de Luffy chill',								'24', '20', 'img_6.png',	'0', '1:3',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Mihawk',						'Petite statuette de Mihawk chill',								'34', '20', 'img_7.png',	'0', '1:3',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de crocodile',						'Petite statuette de Crocodile chill',							'21', '20', 'img_8.png',	'0', '1:3',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Rayleigh',						'Petite statuette de Rayleigh',									'25', '20', 'img_9.png',	'0', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette Baggy',							'Petite statuette de Baggy le clown',							'22', '20', 'img_10.png',	'0', '1:4',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Trafalgar',						'Petite statuette de Trafalgar',								'18', '20', 'img_11.png',	'0', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Trafalgar',						'Petite statuette de Trafalgar Chmapion 2015',					'22', '20', 'img_12.png',	'0', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Roronoa',						'Petite statuette de Roronoa zoro',								'24', '20', 'img_13.png',	'0', '1:4',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Franky',						'Petite statuette de General Franky',							'22', '20', 'img_14.png',	'0', '1:4',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Tashigi',						'Petite statuette de Tashigi',									'17', '20', 'img_15.png',	'1', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Smoker',						'Petite statuette de Smoker',									'20', '20', 'img_16.png',	'0', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Gold D Roger',					'Petite statuette de Gold D Roger',								'25', '20', 'img_17.png',	'0', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Perhona',						'Petite statuette de Perhona',									'22', '20', 'img_18.png',	'1', '1',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Son Goku',						'Petite statuette de Son Goku SSGSS',							'22', '20', 'img_19.png',	'0', '5:4',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Golden Freezer',				'Petite statuette de Golden Freezer',							'22', '20', 'img_20.png',	'0', '5:4',		'1')",
	"INSERT INTO `articles` (`id`, `name`, `description`, `price`, `stock`, `img`, `sexe`, `categ`, `poss`) VALUES (NULL, 'Statuette de Son Goku',						'Petite statuette de Son Goku Dramatic Showcase',				'21', '20', 'img_21.png',	'0', '5:4',		'1')",
);

/*
* Categorie:
*		0: one piece;
*		1: miku
*/


foreach ($sql as $key)
{
	if (mysqli_query($conn, $key) === TRUE)
		echo "<tr><td><code>$key</code></td><td><b style='color: #27ae60; text-align: center;'>SUCCESS</b></td></tr>";
	else
		echo "<tr><td><code>$key</code></td><td><b style='color: #c0392b; text-align: center;'>ERROR</b></td></tr>";
}
echo "</table>";
mysqli_close($conn);
?>
<br><br>
<a href="./" style="font-size: 4vmin">Acceder &agrave; la base du site</a>
</div>
