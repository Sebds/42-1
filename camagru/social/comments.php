<?php

if (basename(__FILE__) == basename($_SERVER["SCRIPT_FILENAME"]))
{
	header("Location: ./gallery.php");
	exit ;
}

function display_comments($image_id)
{
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

	$image_id = htmlspecialchars($image_id, ENT_QUOTES);

	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query_result = $pdo->query("SELECT COUNT(*) AS TOTAL_COMMENTS FROM `comments` WHERE `image_id` = '$image_id';");
		$comments_array = $query_result->fetch(PDO::FETCH_ASSOC);
		$comments_total = $comments_array['TOTAL_COMMENTS'];
		echo '<label id="comments_counter_' . $image_id . '">';
		if ($comments_total == 0)
			 echo " - No comment";
		else if ($comments_total == 1)
			echo " - 1 comment";
		else
			echo " - " . $comments_total . " comments";
		echo "</label>";
	} catch (Exception $e) {
		echo "ERROR : " . $e->getMessage();
		die();
}
}

function display_full_comments($image_id)
{
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

	$image_id = htmlspecialchars($image_id, ENT_QUOTES);

	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

		$query_result = $pdo->query("SELECT * FROM `comments` WHERE `image_id` = '$image_id';");

		if ($query_result->rowCount() > 0)
		{
			echo '<article class=article_comment>';
			echo '<table>';
			while ($array = $query_result->fetch(PDO::FETCH_ASSOC))
			{
				$id = $array['id'];
				$owner_id = $array['owner_id'];
				$owner_string = $array['owner_string'];
				$image_id = $array['image_id'];
				$comment = $array['comment'];
				echo "<tr>";
				echo '<td style="vertical-align:top; font-weight: bold; text-align:right; padding-left:1rem;">' . $owner_string . "</td>";
				echo '<td style="vertical-align:top"> : </td>';
				echo '<td class="comment_content" style="width:100%; font-style:italic; text-align:left; top:0;">"' . $comment . "\"</td>";
				echo '<td class="comment_delete">';
				if ($_SESSION['id'] == $owner_id)
					echo '<a class=global_a style="color:red" href="./comments_delete.php?comment_id=' . $id . '&commented_image_id=' . $image_id . '" >X</a>';
				echo '</td>';
				echo "</tr>";
			}
			echo "</table>";
			echo "</article></div>";
		}
	} catch (Exception $e) {
		echo "ERROR : " . $e->getMessage();
		die();
	}
}

function display_input_comment($image_id)
{
	if (!isset($_SESSION['login']) || empty($_SESSION['login']) || !isset($_SESSION['password']) || empty($_SESSION['password']) || !is_numeric($_SESSION['id']))
	{
		return ;
	}

	echo <<<EOD
	<form name="update_comment_{$image_id}" action="./comments_add.php" method="POST">
		<input style="display:none; position:absolute" name="image_to_comment" value="{$image_id}">
		<input placeholder=Comment id="comment" name="comment" autocomplete="off" autofocus="autofocus" onkeyup="enableComment();">
		<button disabled="" id="button_add_comment" style="margin-top:10px">Add this comment</button>
	</form>
EOD;
}

?>
