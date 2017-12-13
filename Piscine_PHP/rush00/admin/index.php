<?php

session_start();

include ("../lib/function.php");

if (getUserType() != 1)
{
	header("Location: ../?error=badaccount");
	return ;
}
?>

<html>
<head>
	<style>

	table	{
		border: 1px solid black;
		border-collapse: collapse;
		width: 90%;
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

	.long_list
	{
		overflow-y: scroll;
		height: 50vh;
		width: 100vw;
	}
	</style>
</head>
<body>
	Welcome, master.<br><br>
	<a href="../index.php">Retour au site</a>
	<div class="long_list">
		<table align="center">
			<tr>
				<td>ID</td>
				<td>Image</td>
				<td>Nom</td>
				<td>Description</td>
				<td>Prix</td>
				<td>Stock</td>
				<td>Actions</td>
			</tr>

			<?php
			$conn = mysqli_connect("localhost", "vthomas", "password", "rush");
			$sql = 'SELECT * FROM `articles`';
			$res = mysqli_query($conn, $sql);

			if (mysqli_num_rows($res) > 0)
			{
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
						$img = "../res/article/" . $img;
					}

					echo <<<EOD
					<tr {$style}>
						<td>
							{$line['id']}
						</td>
						<td>
							<a href="../lib/consult.php?id={$line['id']}"><img style="width:200px" src={$img}></a>
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
							<button onclick="location.href='../edit.php?action=mod&id={$line['id']}';">Modifier</button>
							<button onclick="location.href='../edit.php?action=del&id={$line['id']}';">Supprimer</button>
						</td>
					</tr>
EOD;
					$i++;
				}
			}
			mysqli_close($conn);
			?>
		</table>
	</div>

	<br><br><br><br>
	<center><form action="./add_product.php" ><button type="text" style="font-size: x-large;">AJOUTER UN PRODUIT</button></form></center>
	<br><br><br><br>


	<div class="long_list" style="height: 300px;">
		<a id="user"></a>
		<table align="center">
			<tr>
			<td style="text-align: center;">ID</td>
			<td style="text-align: center;">Nom</td>
			<td style="text-align: center;">Pass encrypté</td>
			<td>Status</td>
			<td>Actions</td>
			</tr>
			<?php
			$conn = mysqli_connect("localhost", "vthomas", "password", "rush");
			$sql = 'SELECT * FROM `client`';
			$res = mysqli_query($conn, $sql);

			if (mysqli_num_rows($res) > 0)
			{
				$i = 0;
				while (($line = mysqli_fetch_assoc($res)))
				{
					switch ($line['type'])
					{
						case 2:
							$type = "Vendeur";
							break;
						case 1:
							$type = "Admin";
							break;
						case -1:
							$type = "Banned";
							break;
						default:
							$type = "User";
							break;
					}
					if ($i % 2)
						$style = "class='pair'";
					else
						$style = "class='impair'";
					echo <<<EOD
					<tr {$style}>
						<td>
							{$line['id']}
						</td>
						<td>
							{$line['name']}
						</td>
						<td>
							{$line['pass']}
						</td>
						<td>
							{$type}
						</td>
						<td >
							<button onclick="location.href='./mod_user.php?action=vend&id={$line['id']}';">Transforme en vendeur</button>
							<button onclick="location.href='./mod_user.php?action=user&id={$line['id']}';">Transforme en client</button>
							<button onclick="location.href='./mod_user.php?action=suppr&id={$line['id']}';">Supprimer</button>
							<button onclick="location.href='./mod_user.php?action=ban&id={$line['id']}';">Ban</button>
							<button onclick="location.href='./mod_user.php?action=unban&id={$line['id']}';">Unban</button>
						</td>
					</tr>
EOD;
					$i++;
				}
			}
			mysqli_close($conn);

			?>
		</table>
	</div>

	<br><br><br><br>

	<div class="long_list" style="height: 300px;">
		<table align="center">
			<tr>
				<td>ID du client</td>
				<td>Panier archivé au format JSON</td>
			</tr>
		<?php

		$conn = mysqli_connect("localhost", "vthomas", "password", "rush");
		$sql = 'SELECT * FROM `basket`';
		$res = mysqli_query($conn, $sql);

		if (mysqli_num_rows($res) > 0)
		{
			while (($line = mysqli_fetch_assoc($res)))
			{
				echo <<<EOD
				<tr class="pair">
					<td>
						{$line['id']}
					</td>
					<td>
						{$line['json']}
					</td>
				</tr>
EOD;
			}
		}

		?>
		</table>
	</div>

	<div align="center">
		<button onclick="location.href='../install.php';" title="Reinitialise la BDD" style="font-size: xx-large; background-color: #e74c3c; margin-top: 64px; margin-bottom: 64px;">Bombe Hydrogene</button>
	</div>
</body>
</html>
