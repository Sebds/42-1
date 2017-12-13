<?php

if (!isset($_SESSION))
	session_start();
include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
include($_SERVER['DOCUMENT_ROOT'] . "/includes/redirect_to_signin.php");
include($_SERVER['DOCUMENT_ROOT'] . "/includes/time.php");
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

$id = htmlspecialchars($_SESSION['id'], ENT_QUOTES);

?>

<html lang="en">
<head>
	<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/common_config.php"); ?>
	<script type="text/javascript" src="like.js"></script>
	<title>My Photos</title>
</head>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/header.php");?>
<?php include($_SERVER['DOCUMENT_ROOT'] . "/social/likes.php");?>
<?php include($_SERVER['DOCUMENT_ROOT'] . "/social/comments.php");?>

<body>

	<section class="gallery">
		<?php

			try {
				$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
				$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

				$query_result = $pdo->query("SELECT * FROM `images` WHERE `owner_id` = '$id' ORDER BY `date` DESC;");

				if ($query_result->rowCount() > 0)
				{
					while ($array = $query_result->fetch(PDO::FETCH_ASSOC))
					{
						$id = $array['id'];
						$file = $array['file'];
						$owner = $array['owner_string'];
						$date = $array['date'];
						$date = time_elapsed_string($date);
						echo <<<EOD1
						<article class="article_gallery">
							<div class="image_header">
								Image added {$date}
							</div>
							<div class="image_gallery">
								<a target="_blank" href="view.php?image_id={$id}"><img class="image_gallery" src="{$file}"/></a>
							</div>
							<div class="image_info">
								By {$owner}
EOD1;
						display_likes($id, 0);
						display_comments($id);
						echo <<<EOD2
							</div>
						</article>
						<form action=image_delete.php? style="margin-bottom:4rem" method=GET>
								<input style="display:none" name=image_id value={$id}>
								<button class="button" id="button_delete">
									<span style="font-weight:bold">Delete this image</span>
								</button></center>
						</form>
EOD2;
					}
				}
				else
				{
					echo <<<EOD3
					<article class="article_gallery" style="padding:3rem">
						Take some pictures and find them back here !
					</article>
EOD3;
				}
			} catch (Exception $e) {
				echo "ERROR : " . $e->getMessage();
			}

			?>
	</section>

</body>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/footer.php"); ?>

</html>