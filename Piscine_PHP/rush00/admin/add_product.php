<?php
session_start();

include '../lib/function.php';
$type = getUserType();

if ($type != 1 && $type != 2) //Ni admin ni vendeur
{
	header("Location: ./?error=badaccount");
}
?>
<html>
		<?php
			include '../inc/adm_header.php';
		?>
	<section id="main">
		<article style="text-align: center; width: 90%; position:relative; margin-left: auto; margin-right: auto;">
			<form action="./add_product_action.php" method="post">
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
						<td><input type="text" name="name"></td>
					</tr>
					<tr>
						<td style="text-align:right">Prix :</td>
						<td><input type="number" name="price"></td>
					</tr>
					<tr>
						<td style="text-align:right">Stock :</td>
						<td><input type="number" name="stock"></td>
					</tr>
					<tr>
						<td style="text-align:right">Description :</td>
						<td><input style="height:100px;" type="text" name="description""></td>
					</tr>
					<tr>
						<td style="text-align:right">Image :</td>
						<td><input type="text" name="img" id="img"></td>
						<td><div class="button" onclick="show_img();" style="text-align: center;">Voir la liste (Ou url http direct)</div></td>
						<?php

						$file = scandir("../res/article");
						echo '<div id="img_list" style="display: none;">';
						foreach ($file as $key)
						{
							if ($key[0] != '.')
							{
								echo "<img style='width: 8vw; cursor: pointer;' src='../res/article/{$key}' onclick='change(\"$key\")'></img>";
							}
						}
						echo '</div>';

						?>
					</tr>
					<tr>
						<td style="text-align:right">Sexe :</td>
						<td><input id="sexe" type="number" name="sexe" disabled=""></td>
						<td>
							<div class="button" style="width:100%; text-align: center;" onclick="document.getElementById('sexe').value = 0;"><i class="fa fa-venus"></i></div>
							<div class="button" style="width:100%; text-align: center;" onclick="document.getElementById('sexe').value = 1;"><i class="fa fa-mars"></i></div>
						</td>
					</tr>
					<tr>
						<td style="text-align:right">Categories :</td>
						<td><input type="text" id="categ" name="categorie" disabled=""></td>
						<td><div class="button" onclick="show_categ();" style="text-align: center;">Show categorie available</div>
						<?php
						$conn = mysqli_connect("localhost", "vthomas", "password", "rush");
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

						?>
						</td>
					</tr>

				</table>
				<button class="button" style="text-align:center" name="id"><i class="fa fa-upload"></i> Ajouter</button><br><br>
			</form>
		</article>
	</section>
</html>
