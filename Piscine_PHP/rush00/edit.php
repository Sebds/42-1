<?php
session_start();

include 'lib/function.php';
$type = getUserType();
//checkConnect();
if ($type != 1 && $type != 2)//Ni admin ni vendeur
{
	header("Location: ./?error=badaccount");
}
?>
<html>
		<?php
			include 'inc/header.php';
			if (isset($_GET['deleted']))
				echo '<div class="banner valid" onclick="this.remove()" title="Clickez pour supprimer la banniere">Article supprim&eacute; avec succes !</div>';
			if ($_GET['error'] == 'modif')
				echo '<div class="banner error" onclick="this.remove()" title="Clickez pour supprimer la banniere">Article supprim&eacute; avec succes !</div>';
		?>
	<section id="main">
		<article style="text-align: center; width: 90%; position:relative; margin-left: auto; margin-right: auto;">
			<?php
				$mid = $_SESSION['id'];
				if (!isset($_GET['id']) || !isset($_GET['action']))
				{
					echo <<<EOD
					<table>
					<style>

					table	{
						border: 1px solid black;
						border-collapse: collapse;
						width: 100%;
						text-align: center;
					}

					td	{
						border: 1px solid black;
					}
					.pair
					{
						background-color: #E5E5E5;
					}
					.impair
					{
						background-color: #F9F9F9;
					}

					.pair:hover
					{
						background-color: #EAEAEA;
					}

					.impair:hover
					{
						background-color: #FEFEFE;
					}
					button
					{
						font-size: medium;
					}
					</style>
EOD;
					$conn = mysqli_connect("localhost", "vthomas", "password", "rush");
					if ($type == 1)
						$sql = "SELECT * FROM `articles`";
					else
						$sql = "SELECT * FROM `articles` WHERE `poss` = '$mid'";
					$res = mysqli_query($conn, $sql);

					$i = 0;
					while (($line = mysqli_fetch_assoc($res)))
					{
						if ($i % 2)
							$style = "class='pair'";
						else
							$style = "class='impair'";
						$img = $line['img'];
						if (preg_match('@^http://@', $img) == false)
						{	
							$img = "./res/article/" . $img;
						}
						echo <<<EOD
						<tr {$style}>
							<td>
								{$line['id']}
							</td>
							<td>
								<a href="./lib/consult.php?id={$line['id']}"><img style="width:200px" src={$img}></a>
							</td>
							<td>
								{$line['name']}
							</td>
							<td>
								{$line['description']}
							</td>
							<td>
								{$line['price']} €
							</td>
							<td>
								{$line['stock']}
							</td>
							<td>
								<button onclick="location.href='./edit.php?action=mod&id={$line['id']}';">Modifier</button>
								<button onclick="location.href='./edit.php?action=del&id={$line['id']}';">Supprimer</button>
							</td>
						</tr>
EOD;
					}
					echo "</table>";
					mysqli_close($conn);
					echo '<center><form action="./admin/add_product.php" ><button type="text" style="font-size: x-large;">AJOUTER UN PRODUIT</button></form></center>';
				}
				else
				{
					$conn = mysqli_connect("localhost", "vthomas", "password", "rush");
					$art_id = intval($_GET['id']);
					if ($_GET['action'] == "del")
					{
						$sql = "SELECT * FROM `articles` WHERE `poss` = '$mid' AND `id` = $art_id";
						if (mysqli_query($conn, $sql) != false)
						{
							$sql = "DELETE FROM `articles` WHERE `id` = $art_id";
							mysqli_query($conn, $sql);
							echo "<script>location.href='./edit.php?deleted';</script>";
						}
					}
					else
					{
						$sql = "SELECT * FROM `articles` WHERE `poss` = '$mid' AND `id` = $art_id";
						$res = mysqli_query($conn, $sql);
						if ($res == false)
							echo "<script>location.href='./edit.php?error=modif';</script>";
						$line = mysqli_fetch_assoc($res);
						//TODO: update output and style
						echo <<<EOD
						<form action="./admin/mod_product.php" method="post">
							<table align="center">
							<script>
								var dis_img = false;
								var dis_cat = false;
								function show_img()
								{
									dis_img = !dis_img;
									if (dis_img)
										document.getElementById('img_list').style.display = 'block';
									else
										document.getElementById('img_list').style.display = 'none';
								}

								function show_categ()
								{
									dis_cat = !dis_cat;
									console.log("Switch" + dis_cat);
									if (dis_cat)
										document.getElementById('categ_list').style.display = 'block';
									else
										document.getElementById('categ_list').style.display = 'none';
								}

								function change(str)
								{
									document.getElementById('img').value = str;
								}

								function changeCateg(id)
								{
									var x = document.getElementById('categ_' + id).getAttribute("class");
									if (x == "categ_elem sel")
										document.getElementById('categ_' + id).setAttribute("class", "categ_elem");
									else
										document.getElementById('categ_' + id).setAttribute("class", "categ_elem sel");
									var c = document.getElementsByClassName("sel");
									var fullstr = '';
									Array.prototype.forEach.call(c, function(el) {
									console.log(el.getAttribute("value"));
									fullstr += ':' + el.getAttribute("value");
									});
									document.getElementById('categ').value = fullstr.substr(1);
								}
							</script>
							<style>
								td	{
									width: 250px;
									height: 30px;
									border-collapse: separate;
								}
								table {
									border-spacing: 10px;
								}
								input {
									text-align:center;
									width:400px;
								}
							</style>
								<tr>
									<td style="text-align:right">Nom :</td>
									<td><input type="text" name="name" value="{$line['name']}"></td>
								</tr>
								<tr>
									<td style="text-align:right">Prix :</td>
									<td><input type="number" name="price" value="{$line['price']}"></td>
								</tr>
								<tr>
									<td style="text-align:right">Stock :</td>
									<td><input type="number" name="stock" value="{$line['stock']}"></td>
								</tr>
								<tr>
									<td style="text-align:right">Description :</td>
									<td><input style="height:100px;" type="text" name="description" value="{$line['description']}"></td>
								</tr>
								<tr>
									<td style="text-align:right">Image :</td>
									<td><input type="text" name="img" id="img" value="{$line['img']}"></td>
									<td><div class="button" onclick="show_img();" style="text-align: center;">Show img available</div></td>
								</tr>
								<tr>
									<td style="text-align:right">Sexe :</td>
									<td><input id="sexe" type="number" name="sexe" value="{$line['sexe']}" ></td>
									<td>
										<div class="button" style="width:100%; text-align: center;" onclick="document.getElementById('sexe').value = 0;"><i class="fa fa-venus"></i></div>
										<div class="button" style="width:100%; text-align: center;" onclick="document.getElementById('sexe').value = 1;"><i class="fa fa-mars"></i></div>
									</td>
								</tr>
								<tr>
									<td style="text-align:right">Categories :</td>
									<td><input type="text" id="categ" name="categorie" value="{$line['categ']}" ></td>
									<td><div class="button" onclick="show_categ();" style="text-align: center;">Show categorie available</div></td>
								</tr>

							</table>
							<button class="button" style="text-align:center" name="id" value="{$_GET['id']}"><i class="fa fa-upload"></i> Modifier</button><br><br>
						</form>
EOD;
					}
					$file = scandir("./res/article");
					echo '<div id="img_list" style="display: none;">';
					foreach ($file as $key)
					{
						if ($key[0] != '.')
						{
							echo "<img style='width: 8vw; cursor: pointer;' src='./res/article/{$key}' onclick='change(\"$key\")'></img>";
						}
					}
					echo '</div>';
					$sql = 'SELECT * FROM `categorie`';
					$res = mysqli_query($conn, $sql);
					echo '<div id="categ_list" style="display: none;">';
					echo <<<EOD
					<style>
					.sel
					{
						background-color: #AAAAAA;
					}
					</style>
EOD;
					while (($line = mysqli_fetch_assoc($res)))
					{
						$n = $line['name'];
						$i = $line['id'];
						echo "<div class='categ_elem' id='categ_$i' onclick='changeCateg($i)' value='$i'>$n</div>";
					}
					echo '</div>';
					mysqli_close($conn);
				}
			?>
		</article>
	</section>
	<footer style="height: 50px; font-size: 20px; vertical-align:middle;">
		&copy; vthomas &amp; nsampre - 2017
	</footer>
</html>
