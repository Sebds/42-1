<head>
	<title>Chopper</title>
	<link href='./css/index.css' rel='stylesheet' type='text/css' />
	<link href='./css/menu.css' rel='stylesheet' type='text/css' />
	<link href='./lib/css/font-awesome.min.css' rel='stylesheet' type='text/css' />
</head>
<header>
	<nav>
		<ul>
			<a href="./"><li id="home"><img src="./res/banner.png" title="Home" style="height: 50px;" ></img></li></a>
			<div class="dropdown-1" style="width: 150px; text-align: middle; position:absolute; right:605">
				<button class="dropbutton-1" style="width: 150px; text-align: middle;">Categories</button>
				<div class="dropdown-content-1">
					<a href="./?sexe=0">Figurines masculines</a>
					<a href="./?sexe=1">Figurines féminines</a>
					<?php
						$conn = mysqli_connect("localhost", "vthomas", "password", 'rush');
						$sql = "SELECT * FROM `categorie`";
						$res = mysqli_query($conn, $sql);
						while (($line = mysqli_fetch_assoc($res)))
						{
							$mid = $line['id'];
							$mtxt = $line['name'];
							echo "<a href='./?categorie=$mid'>$mtxt</a>";
						}
						mysqli_close($conn);
					?>
				</div>
			</div>

			<?php
				if ((isset($_SESSION['login']) && !empty($_SESSION['login']) && isset($_SESSION['password']) && !empty($_SESSION['password'])))
				{
					echo '<li class="menu" style="width: 150px; text-align: middle; position:absolute; right:455"><br>Bienvenue ' . $_SESSION['login'] . ' !</li>';
					echo '<a href="./lib/basket.php" position:right><li class="menu" style="width: 150px; text-align: middle; position:absolute; right:305"><br><i class="fa fa-shopping-basket"></i> Mon panier</li></a>';
					echo '<a href="./lib/account.php"><li class="menu" style="width: 150px; text-align: middle; position:absolute; right:155"><br><i class="fa fa-user"></i> Mon Compte</li></a>';
					echo '<a href="./lib/disconnect.php"><li class="menu" style="width: 150px; text-align: middle; position:absolute; right:5"><br><i class="fa fa-sign-out"></i>Se deconnecter</li></a>';
				}
				else
				{
					echo '<a href="./lib/basket.php" position:right><li class="menu" style="width: 150px; text-align: middle; position:absolute; right:155"><br><i class="fa fa-shopping-basket"></i> Mon panier</li></a>';
					echo '<a href="./lib/connect.php"><li class="menu" style="width: 150px; text-align: middle; position:absolute; right:5"><br><i class="fa fa-sign-in"></i> Se connecter</li></a>';
				}
			?>
		</ul>
	</nav>
</header>
