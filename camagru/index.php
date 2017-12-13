<?php

session_start();
include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php"); 

?>

<html lang="en">
<head>
	<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/common_config.php"); ?>
	<title>The Camagru Project</title>
	<link rel="stylesheet" media="screen" href="style.css">
</head>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/header.php");?>

<!-- <body background="/resources/wp.png"> -->
<body>

<div id="ft_particles"></div>
<script src="ft_particles.js"></script>
<script type="text/javascript">
	particlesJS('ft_particles');
</script>
	<table class="home_table">
		<tr>
			<td rowspan="3" class="home_cell" style="font-size:4vw; color:lightgrey;">
				<?php if ($_SESSION['login'] != '') echo $_SESSION['login'] . ", "; ?> Welcome to <br>The Camagru Project.
			</td>
			<td class="home_cell" width="100px">

			</td>
			<td class="home_cell">
				<a class="global_a" href="/social/gallery.php" style="color: white">Visit the Gallery !</a>
			</td>
		</tr>

		<tr>
			<td>	</td>
			<td class=home_cell>
				<?php

				if (!isset($_SESSION['login']) || !isset($_SESSION['password']) || !is_numeric($_SESSION['id']))
				{
					echo '<br><a class="global_a" href="/connexion/signup.php" style="color:white;">Register, like and comment !</a><br><br>';
				}
				else
				{
					echo "<br>";
				}

				?>
			</td>
			<td>	</td>
		</tr>

		<tr>
			<td>		</td>
			<td class="home_cell">
				<a class="global_a" href="/shoot/shoot_webcam.php" style="color:white;">Shoot & Share !</a>
			</td>
		</tr>
	</table>

</body>


<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/footer.php"); ?>

</html>