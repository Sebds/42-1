<?php
session_start();
include 'function.php';
checkConnect();
?>

<html>
		<style>

			td {
				line-height: 1.4;
				border: 1px solid black;
				color: black;
				font-family: "helvetica";
			}
		</style>
		<?php
/* ************************************************************************** */
			include '../inc/lib_header.php';
		if (isset($_GET['clear']))
		{
			echo '<div class="banner valid" onclick="this.remove()" title="Clickez pour supprimer la banniere">Le panier a &eacute;t&eacute; vid&eacute; de son contenu !</div>';

			$j = json_decode($_SESSION['basket']);
			$i = 0;
			$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
			if ($j)
			{
				foreach ($j as $v)
				{
					$sql = "SELECT * FROM `articles` WHERE `id` = $v->id;";
					$res = mysqli_query($conn, $sql);
					$line = mysqli_fetch_assoc($res);
					$quantite = intval($line['stock']) + $v->quantite;
					$sql = "UPDATE `articles` SET `stock` = '$quantite' WHERE `id` = $v->id;";
					$res = mysqli_query($conn, $sql);
					//unset($j[$i]);
					$i++;
				}
			}

/* ************************************************************************** */

			unset($_SESSION['basket']);
			$myid = $_SESSION['id'];
			$sql = "UPDATE `client` SET `basket` = '' WHERE `client`.`id` = $myid";
			$res = mysqli_query($conn, $sql);
			mysqli_close($conn);
		}
		if (isset($_GET['backup']) && $_SESSION['id'] != '')
		{
			$id = $_SESSION['id'];
			$conn = mysqli_connect("localhost", "vthomas", "password", "rush");
			$sql = "SELECT * FROM `basket` WHERE `id` = '$id';";
			$res = mysqli_query($conn, $sql);
			$line = mysqli_fetch_assoc($res);
			$_SESSION['basket'] = $line['json'];
			echo '<div class="banner valid" onclick="this.remove()" title="Clickez pour supprimer la banniere">Panier restauré !</div>';
		}
		if ($_GET['error'] == "stock")
		{
			echo '<div class="banner error" onclick="this.remove()" title="Clickez pour supprimer la banniere">Le vendeur ne dispose pas d\'assez de stock pour repondre &agrave; votre demande !</div>';
		}
		if ($_GET['message'] == 'saved' && $_SESSION['id'] != '')
		{
			echo '<div class="banner valid" onclick="this.remove()" title="Clickez pour supprimer la banniere">Panier archivé dans la base de données pour la premier fois !</div>';
		}
		if ($_GET['message'] == 'updated' && $_SESSION['id'] != '')
		{
			echo '<div class="banner valid" onclick="this.remove()" title="Clickez pour supprimer la banniere">Panier mis a jour dans la base de données !</div>';
		}
		?>
	<section id="main">

		<article style="text-align:center; width:1000px; margin-right:auto; margin-left:auto;"><br><br>
			<table align="center" style="border-collapse:collapse">
				<?php

				$total = 0;

				$j = json_decode($_SESSION['basket']);
				if ($j)
				{
					//var_dump($j);
					foreach ($j as $value)
					{
						$total += intval($value->price) * $value->quantite;
						$id = $value->id;
						$name = $value->name;
						$price = $value->price;
						$img = $value->img;
						if (preg_match('@^http://@', $img) == false)
						{
							$img = "../res/article/" . $img;
						}
						$quantite = $value->quantite;

						echo <<< EOD
						<tr>
							<td style="width:50px; text-align: center;">
								{$id}
							</td>
							<td>
								<a href="./consult.php?id={$id}"><img style="width:200px" src="{$img}"></a>
							</td>
							<td style="width:250px; text-align:center;">
								{$name}
							</td>
							<td style="width:50px; text-align: center;">
								{$price} €
							</td>
							<td style="width:50px; text-align: center;">
								x {$quantite}
							</td>
							<td style="width:50px; text-align: center;">
								<a href="./basket_quantity.php?id={$id}&action=plus"><i class="fa fa-plus" aria-hidden="true"></i></a>
							</td>
							<td style="width:50px; text-align: center;">
								<a href="./basket_quantity.php?id={$id}&action=minus"><i class="fa fa-minus" aria-hidden="true"></i></a>
							</td>
						</tr>
EOD;
					}
				}
				else
				{
					echo "<tr><td style='text-align:center; margin-left:auto; margin-right:auto'>";
					echo "<br><br><h1>Votre panier est vide !</h1><br><br>";
					echo "</td></tr>";
				}

				?>
			</table>
			<br><br>
			<div style="font-size: x-large; font-family: 'helvetica';":>
				Total :	<?php	echo $total . "€"; ?>
			</div>
			<br>
			<br>
			<center>
				<form>
					<?php
						if ($_SESSION['id'] != '')
							echo <<<EOD
						<input type="button" onclick="location.href='./facture.php';" value="Archiver le panier" style="font-size:x-large;"/>
EOD
					?>
					<input type="button" onclick="location.href='./basket.php?clear';" value="Vider le panier" style="font-size:x-large;"/>
					<?php
						if ($_SESSION['id'] != '')
						echo <<<EOD
						<input type='button' onclick="location.href='./basket.php?backup';" value="Restaurer le dernier panier sauvegardé" style="font-size:x-large;"/>
EOD
					?>
				</form>
			</center>
			<br>
			<br>
		</article>
		<br>
		<br>
		<br>
		<br>
	</section>
	<footer>
		<p>
			&copy; vthomas &amp; nsampre - 2017
		</p>
	</footer>
</html>
