<?php
session_start();

include 'lib/function.php';
checkConnect();
?>
<html>
		<?php
			include 'inc/header.php';
			if ($_GET['error'] == 'badaccount')
				echo '<div class="banner error" onclick="this.remove()" title="Clickez pour supprimer la banniere">Vous ne disposez pas des droits necessaire.</div>';
			if ($_GET['value'] == 'deleted')
				echo '<div class="banner valid" onclick="this.remove()" title="Clickez pour supprimer la banniere">Votre compte a &eacute;t&eacute; supprimé avec succes</div>';
			if ($_GET['value'] == 'created')
				echo <<<EOD
				<div class="banner valid" onclick="this.remove()" title="Clickez pour supprimer la banniere">Compte créé avec succes ! Vous pouvez vous connecter. Redirection vers la page de connection dans <span id="delay">5</span>s</div>
				<script>
					var d = 3;
					setTimeout(function()
					{
						window.location = "./lib/connect.php";
					}, d * 1000);
					setInterval(function()
					{
						d--;
						document.getElementById("delay").innerHTML = d;
					}, 1000);
					document.getElementById("delay").innerHTML = d;
				</script>
EOD;
			if ($_GET['error'] == 'add')
				echo '<div class="banner error" onclick="this.remove()" title="Clickez pour supprimer la banniere">Le produit n\'a pas pu &ecirc;tre ajouter</div>';
		?>
	<section id="main">
		<article id="pres" style="text-align: center; width: 1000px; position:relative; margin-left: auto; margin-right: auto;">
			<br><div style="position: relative; bottom: 4px; font-size: 1.5vw; font-family:helvetica;"> Derniers articles:</div>
			<div align="center">
				<ul class="presentation">
				<?php
				$conn = mysqli_connect("localhost", "vthomas", "password", "rush");
				$sql = 'SELECT * FROM `articles` ORDER BY `last_change` DESC LIMIT 6';

				$res = mysqli_query($conn, $sql);
				if (mysqli_num_rows($res) > 0)
				{
					while (($line = mysqli_fetch_assoc($res)))
					{
						$img = $line['img'];
						if (preg_match('@^http://@', $img) == false)
						{	
							$img = "./res/article/" . $img;
						}
						echo <<<EOD
						<li>
							<a href="./lib/consult.php?id={$line['id']}">
								<img src="{$img}" style="width:250px"/><br></br>
								<span style="font-family:'helvetica'; font-size:20px">{$line['name']}</span>
							</a>
						</li>
EOD;
					}
				}
				mysqli_close($conn);
				?>
				</ul>
			</div>
		</article>
		<article id="viewer" style="text-align: center; width: 1000px; position:relative; margin-left: auto; margin-right: auto;">
			<br><div style="position: relative; bottom: 4px; font-size: 1.5vw; font-family:helvetica;"> Tous les articles:</div>
			<div align="center">
				<ul class="presentation">
				<?php
				include './lib/show.php';
				?>
				</ul>
			</div>
		</article>
	</section>
	<footer style="height: 50px; font-size: 20px; vertical-align:middle;">
		&copy; vthomas &amp; nsampre - 2017
	</footer>
</html>
