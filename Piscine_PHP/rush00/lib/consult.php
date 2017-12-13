<?php
session_start();

if (!isset($_GET['id']) || empty($_GET['id']))
{
	echo "Erreur - Id non existant";
	exit;
}

$id = $_GET['id'];

$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
$sql = "UPDATE `articles` SET `last_change` = CURRENT_TIMESTAMP WHERE `id` = '$id';";
$res = mysqli_query($conn, $sql);
$sql = "SELECT * FROM `articles` WHERE `id` = '$id';";
$res = mysqli_query($conn, $sql);

if ($res == false)
{
	header("Location: ../index.php");
	return ;
}

$tab = mysqli_fetch_assoc($res);

$name = $tab['name'];
$description = $tab['description'];
$price = $tab['price'];
$stock = $tab['stock'];

$img = $tab['img'];
if (preg_match('@^http://@', $img) == false)
{	
	$img = "../res/article/" . $img;
}

$cat = $tab['categ'];

mysqli_close($conn);
?>
<html>
	<?php
		include '../inc/lib_header.php';
	?>
	<section id="main">
		<article style="text-align: center; width: 1000px; position:relative; margin-left: auto; margin-right: auto;">
			<h1><br><?php echo $name; ?></h1>
			<table style="position: relative; margin-left:auto; margin-right: auto; border-collapse: separate; border-spacing: 10px">
				<tr>
					<td style="text-align: center;" rowspan="10">
						<img src=<?php echo $img;?> style="width: 500px;">
					</td>
					<td style="text-align: center; width: 35vw;">
						<div class="legend">
							<u>Description</u> : <?php echo $description;?>
						</div>
					</td>
				</tr>
				<tr>
					<td style="text-align: center; width: 35vw;">
						<div class="legend">
							<u>Prix</u> : <?php echo $price . " €"?>
						</div>
					</td>
				</tr>
				<tr>
					<td style="text-align: center; width: 35vw;">
						<div class="legend">
							<u>En stock</u> : <?php echo $stock . " articles";?>
						</div>
					</td>
				</tr>
				<tr>
					<td style="text-align: center; width: 35vw;">
						<div class="legend">
							<u>Categories</u> :
							<?php
								$conn = mysqli_connect("localhost", "vthomas", "password", "rush");

								preg_match_all("/[\d*]/", $cat, $matches);
								foreach ($matches as $match)
								{
									$i = 0;
									foreach ($match as $value)
									{
										if ($i != 0)
											echo ", ";
										$sql = "SELECT * FROM `categorie` WHERE `id` = '$value';";
										$res = mysqli_query($conn, $sql);
										if ($res != false)
										{
											$line = mysqli_fetch_assoc($res);
											$txt = $line['name'];
											echo "<a href='../?categorie=$value'>$txt</a>";
											$i++;
										}
									}
								}
								mysqli_close($conn);
							?>
						</div>
					</td>
				</tr>
				<tr><td></td></tr>
				<tr><td></td></tr>
				<tr><td></td></tr>
				<tr><td></td></tr>
				<tr><td></td></tr>
				<tr><td></td></tr>
			</table>
			<center>
			<?php
			if ($stock)
			{
				?>
				<br>
				<form action="./add_basket.php" method="POST">
					<button class="button" id="send" name="basket_add" value="<?php echo $id; ?>">
						<span><i class="fa fa-sign-up"></i> Ajouter au panier</span>
					</button>
				</form>
				<?php
			}
			else
			{
				?>
				<h2>Cet article est en rupture de stock...</h2>
				<?php
			}
			?>
			</center>
			<br>
		</article>
	</section>
	<footer>
		<p>
			&copy; vthomas &amp; nsampre - 2017
		</p>
	</footer>
</html>
