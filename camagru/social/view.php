<?php

if (!isset($_SESSION))
	session_start();
include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
include($_SERVER['DOCUMENT_ROOT'] . "/includes/time.php");
include($_SERVER['DOCUMENT_ROOT'] . "/social/likes.php");
include($_SERVER['DOCUMENT_ROOT'] . "/social/comments.php");

if (!$_GET['image_id'] || $_GET['image_id'] == '')
{
	header("Location: ./gallery.php");
	return ;
}

$image_id = htmlspecialchars($_GET['image_id'], ENT_QUOTES);

try {
	$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$query_result = $pdo->query("SELECT * FROM `images` WHERE `id` = '$image_id';");
	if ($query_result->rowCount() != 1)
	{
		header("Location: ./gallery.php");
		return ;
	}
	$array = $query_result->fetch(PDO::FETCH_ASSOC);
	$id = $array['id'];
	$file = $array['file'];
	$owner = $array['owner_string'];
	$date = $array['date'];
	$date = time_elapsed_string($date);
} catch (Exception $e) {
	echo "ERROR : " . $e->getMessage();
}

?>

	<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/common_config.php"); ?>

	<script type="text/javascript">

	function exitPreview()
	{
		window.close();
	}

	</script>

<html lang="en">
<head>
	<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/common_config.php"); ?>
	<script type="text/javascript" src="like.js"></script>
	<script type="text/javascript" src="comment.js"></script>
	<title>Gallery</title>
</head>

<body>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/header.php"); ?>

<section class="view">
	<script type="text/javascript" src="like.js"></script>
	<script type="text/javascript" src="comment.js"></script>

	<iframe style="display:none" name="hidden-form"></iframe>
	<section class="gallery">
	<?php
		echo <<<EOD1
		<article class="article_gallery">
			<button class="exit_preview" id="button_load" onclick="exitPreview();">
				<a class="global_a" disabled>Exit</a>
			</button>
			<div class="image_header">
				#$id Added {$date}
			</div>
			<div class="image_gallery">
				<img class="image_gallery" src="{$file}"/>
			</div>
			<div class="image_info">
				By {$owner}
EOD1;
		display_likes($id, 1);
		display_comments($id);
		echo <<<EOD2
			</div>
		</article>
EOD2;
		display_full_comments($id);
		display_input_comment($id);
		?>
	</section>
</section>

</body>
</html>