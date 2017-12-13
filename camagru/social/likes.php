<?php

if (basename(__FILE__) == basename($_SERVER["SCRIPT_FILENAME"]))
{
	header("Location: ./gallery.php");
	exit ;
}

function user_has_liked($image_id)
{
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

	$image_id = htmlspecialchars($image_id, ENT_QUOTES);
	$user_id = htmlspecialchars($_SESSION['id'], ENT_QUOTES);

	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

		$query_result = $pdo->query("SELECT COUNT(*) AS HAS_LIKED FROM `likes` WHERE `image_id` = '$image_id' AND `owner_id` = '$user_id';");

		$array = $query_result->fetch(PDO::FETCH_ASSOC);
		$has_liked = $array['HAS_LIKED'];

		return ($has_liked);
	} catch (Exception $e) {
		echo "ERROR : " . $e->getMessage();
		die();
	}

}

function display_likes($image_id, $all)
{
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

	$image_id = htmlspecialchars($image_id, ENT_QUOTES);

	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

		//Get likes about image
		$query_result = $pdo->query("SELECT COUNT(*) AS TOTAL_LIKES FROM `likes` WHERE `image_id` = '$image_id';");

		$likes_array = $query_result->fetch(PDO::FETCH_ASSOC);
		$likes_total = $likes_array['TOTAL_LIKES'];

		//Display like number
		echo '<label id="likes_counter_' . $image_id . '">';
		if ($likes_total == 0)
			echo " - No like";
		else if ($likes_total == 1)
			echo " - 1 like";
		else
			echo " - " . $likes_total . " likes";
		echo "</label>";

		//Hide dynamic like counter
		echo "<div style='display:none' id='likes_total_{$image_id}'>" . $likes_total . "</div>";

		//Logged or not logged
		if (!isset($_SESSION['login']) || empty($_SESSION['login']) || !isset($_SESSION['password']) || empty($_SESSION['password']) || !is_numeric($_SESSION['id']) || $all == 0)
			return ($likes_total);

		echo <<<EOD
	<form style="position:absolute" id="add_like_{$image_id}" action="likes_add.php" method="POST" target="hidden-form">
		<input style="display:none; position:absolute" name="image_id" value="{$image_id}">
	</form>

	<form style="position:absolute" id="delete_like_{$image_id}" action="likes_delete.php" method="POST" target="hidden-form">
		<input style="display:none; position:absolute" name="image_id" value="{$image_id}">
	</form>
EOD;

		//What function call ? like or unlike ?
		if (user_has_liked($image_id))
		{
			echo "- <a class=global_a href='javascript:void(0);' id='likes_button_" . $image_id . "' onclick='delete_like(" . $image_id . ");' style='color:green'> Liked ! </a>";
		}
		else
		{
			echo "- <a class=global_a href='javascript:void(0);'' id='likes_button_" . $image_id . "' onclick='add_like(" . $image_id . ");' >Like !</a>";
		}

	} catch (Exception $e) {
		echo "ERROR : " . $e->getMessage();
		die();
	}
}

?>