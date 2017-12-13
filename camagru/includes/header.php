<?php

if (basename(__FILE__) == basename($_SERVER["SCRIPT_FILENAME"]))
{
	header("Location: /index.php");
	exit ;
}

?>

<div class="main_header">
	<a class="global_a" style="margin-left:25px;" href="/index.php">Home </a>
	<a class="global_a" style="margin-left:25px;" href="/social/gallery.php">Gallery </a>
	<?php
		if (isset($_SESSION['login']) && !empty($_SESSION['login']) && isset($_SESSION['password']) && !empty($_SESSION['password']) && is_numeric($_SESSION['id']))
		{
			echo '<a class="global_a" style="margin-left:25px;" href="/shoot/shoot_webcam.php">Shoot </a>';
			echo '<a class="global_a" style="margin-left:25px;" href="/account/account.php">Account </a>';
			echo '<a class="global_a" style="margin-left:25px;" href="/connexion/signout.php">Sign Out </a>';
		}
		else
		{
			echo '<a class="global_a" style="margin-left:25px;" href="/connexion/signin.php">Sign In </a>';
			echo '<a class="global_a" style="margin-left:25px;" href="/connexion/signup.php">Sign Up </a>';
		}
	?>
</div>