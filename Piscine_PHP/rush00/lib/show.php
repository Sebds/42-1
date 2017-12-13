<?php
if (isset($_GET['categorie']))
	$categ = htmlspecialchars($_GET['categorie'], ENT_QUOTES);
else
	$categ = '';
if (isset($_GET['sexe']))
	$sex = htmlspecialchars($_GET['sexe'], ENT_QUOTES);
else
	$sex = '';
$sql = "SELECT * FROM `articles` WHERE `categ` LIKE '%$categ%' AND `sexe` LIKE '%$sex%' ORDER BY `last_change` DESC";
$conn = mysqli_connect("localhost", "vthomas", "password", "rush");

if (isset($_GET['categorie']))
{
	$txt = $_GET['categorie'];
	$txt = "?categorie=$txt";
}
else
	$txt = '?';
echo <<<EOD
<a href="./{$txt}&sexe=1"><div class="button" style="width: 40%;" ><i class="fa fa-venus"></i></div></a>
<a href="./{$txt}&sexe=0"><div class="button" style="width: 40%;" ><i class="fa fa-mars"></i></div></a>
<a href="./{$txt}"><div class="button" style="width: 40%;" ><i class="fa fa-venus-mars"></i></div></a>
EOD;


$res = mysqli_query($conn, $sql);
if ($res == true)
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
else {
	echo "Nothing...";
}
mysqli_close($conn);
?>
