<?php

session_start();
include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
include($_SERVER['DOCUMENT_ROOT'] . "/includes/redirect_to_signin.php");
include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");

if ($_SESSION['input'] == 'webcam')
{
	header("Location: ./shoot_webcam.php");
	return ;
}

?>

<html lang="en">
<head>
	<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/common_config.php"); ?>
	<title>Shoot</title>
	<script type="text/javascript" src="./shoot.js"></script>
</head>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/header.php"); ?>

<body>
	<section class="shoot" style="position: relative; width: 1400px; margin: 0 auto;">
	<table style="margin: 0 auto">
		<tr>
			<td>
				<form enctype="multipart/form-data" action="save_img.php" method="POST">
				<table class="shoot_table">
					<tr>
						<td class="shoot_cell">
							<div class=filter style="padding: 1rem">Load file</div>
								<input id=my_input_file type=file accept="image/jpeg" onchange="enableUpload();" name="shoot_file">
							</div>
						</td>
						<td class="shoot_cell">
							<label class=filter><input type="radio" name="filter" value="/filters/cat.png" onchange="selectFilter();" checked ><img src="/filters/cat.png" width="70px" height="70px"></input></label>
							<label class=filter><input type="radio" name="filter" value="/filters/dog.png" onchange="selectFilter();" ><img src="/filters/dog.png" width="70px" height="70px"></input></label>
							<label class=filter><input type="radio" name="filter" value="/filters/bull.png" onchange="selectFilter();"><img src="/filters/bull.png" width="70px" height="70px"></input></label>
							<label class=filter><input type="radio" name="filter" value="/filters/rabbit.png" onchange="selectFilter();" ><img src="/filters/rabbit.png" width="70px" height="70px"></input></label>
							<label class=filter><input type="radio" name="filter" value="/filters/rabbit2.png" onchange="selectFilter();" ><img src="/filters/rabbit2.png" width="70px" height="70px"></input></label>
							<label class=filter><input type="radio" name="filter" value="/filters/unicorn.png" onchange="selectFilter();"><img src="/filters/unicorn.png" width="70px" height="70px"></input></label>
							<label class=filter><input type="radio" name="filter" value="/filters/frame.png" onchange="selectFilter();"><img src="/filters/frame.png" width="70px" height="70px"></input></label>
							<label class=filter><input type="radio" name="filter" value="/filters/empty.png" onchange="selectFilter();"><img src="/filters/empty.png" width="70px" height="70px" style="border:1px solid black"></input></label>
						</td>
						<td class="button_shoot_cell" style="width:200px; width:200px; min-width:200px; background: linear-gradient(to bottom right, #a4ffa0, #b8cbff);">
							<input style="display: none" name="action" value="file">
							<input name="upload_snapshot_button" id="button_shoot" type="submit" value="Upload file" disabled="">
						</td>
					</tr>
				</table>
				</form>
			</td>
			<td>
				<table class="latest_shoot" style="opacity: 75%; background: lightgrey">
					<tr>
						<td class=filter>Your last shoots</td>
					</tr>
					<?php
						$id = htmlspecialchars($_SESSION['id'], ENT_QUOTES);

						try {
							$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
							$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

							$query_result = $pdo->query("SELECT * FROM `images` WHERE `owner_id` = '$id' ORDER BY `date` DESC LIMIT 5;");
							$rows = $query_result->rowCount();
							if ($rows > 0)
							{
								while ($array = $query_result->fetch(PDO::FETCH_ASSOC))
								{
									$id = $array['id'];
									$file = $array['file'];
								echo <<<EOD
<tr>
	<td style="max-height:97px; padding:0.25rem; border:1px solid grey;"><a class=global_a href=/social/view.php?image_id={$id}><img src={$file} width="130px"></a></td>
</tr>
EOD;
								}
							}
							$rows = 5 - $rows;
							while ($rows > 0)
							{
								echo '<tr><td style="height:97px; padding:0.25rem; border:1px solid grey; background:linear-gradient(to bottom right, #b4ffa0, #c8cbff);"></td></tr>';
								echo "\n";
								$rows--;
							}
						} catch (Exception $e) {
							echo "ERROR : " . $e->getMessage();
						}
					?>
				</table>
			</td>
		</tr>
	</table>
	<div style="text-align:center; margin-right:auto; margin-left:auto; margin-top:30px;">
		<button disabled id="button_account">
			<a class="global_a" href="./switch_input.php"><?php if ($_SESSION['input'] == 'webcam') echo "Enable File input"; else echo "Enable Webcam"; ?></a>
		</button>
	</div>
	</section>
		<div id="hidden_form_container" style="display:none;"></div>
	</section>
</body>
<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/footer.php"); ?>
</html>