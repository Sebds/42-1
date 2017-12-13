<?php

if (!isset($_SESSION))
	session_start();

include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

if (!isset($_GET['from']) || !is_numeric($_GET['from']) || $_GET['from'] <= 0)
	$range_from = 0;
else
	$range_from = htmlspecialchars($_GET['from'], ENT_QUOTES);

?>

<script>
	var index = 0;

	function loadNextPage()
	{
		var xhttp = new XMLHttpRequest();

		xhttp.onreadystatechange = function() {
			if (this.readyState == 4 && this.status == 200) {
				document.getElementById("button_load").insertAdjacentHTML('beforebegin', this.responseText);
	  		}
		};
		xhttp.open("GET", "./request_image.php?id=" + String(index), true);
		xhttp.send();
		index += 5;
	}
</script>

<html lang="en">
<head>
	<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/common_config.php"); ?>
	<script type="text/javascript" src="like.js"></script>
	<script type="text/javascript" src="comment.js"></script>
	<title>Gallery</title>
</head>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/header.php");?>
<?php include($_SERVER['DOCUMENT_ROOT'] . "/social/likes.php");?>
<?php include($_SERVER['DOCUMENT_ROOT'] . "/social/comments.php");?>

<body>
	<section class="gallery" id="main">
		<button class="button" id="button_load" onclick="loadNextPage();">
			<a class="global_a" disabled>Load more</a>
		</button>
	</section>

	<script type="text/javascript">
		loadNextPage();
	</script>

	<form id=formImagePreview target=iframeImageView method=GET>
		<input style="display:none; position:absolute" id="iframeInput" name="image_id" value="">
	</form>
</body>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/footer.php"); ?>

</html>