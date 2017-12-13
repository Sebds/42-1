<?php

include($_SERVER['DOCUMENT_ROOT'] . "/social/likes.php");
include($_SERVER['DOCUMENT_ROOT'] . "/social/comments.php");
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
include($_SERVER['DOCUMENT_ROOT'] . "/includes/time.php");

if (!isset($_GET['id']) || $_GET['id'] == '' || !is_numeric($_GET['id']))
	return ;

$range_from = $_GET['id'];

try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

		$query_result = $pdo->query("SELECT * FROM `images` ORDER BY `date` DESC LIMIT $range_from, 5;");
		$rows = $query_result->rowCount();
		if ($rows > 0)
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
						#$id Added {$date}
					</div>
					<div class="image_gallery">
						<a href="view.php?image_id={$id}" target="_blank"><img class="image_gallery" src="{$file}"/></a>
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
			}
		}
		$rows = 5 - $rows;
		while ($rows > 0)
		{
			echo '<tr><td style="height:97px; padding:0.25rem; border:1px solid grey; background: linear-gradient(to bottom right, #b4ffa0, #c8cbff);"></td></tr>';
			echo "\n";
			$rows--;
		}	
	} catch (Exception $e) {
		echo "ERROR : " . $e->getMessage();
	}
?>