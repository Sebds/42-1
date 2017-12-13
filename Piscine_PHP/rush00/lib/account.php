<?php
session_start();

include 'function.php';
$type = getUserType();

if (!isset($_SESSION['login']))
{
	header("Location: ../index.php");
	return ;
}

$login = $_SESSION['login'];
$password = $_SESSION['password'];
$type = $_SESSION['type'];
$id = $_SESSION['id'];
?>
<html>
	<?php
		include '../inc/lib_header.php';
		if ($_GET['error'] == 'password')
			echo '<div class="banner error" onclick="this.remove()" title="Clickez pour supprimer la banniere">Mot de passe incorrect !</div>';
		if ($_GET['value'] == 'modified')
			echo '<div class="banner valid" onclick="this.remove()" title="Clickez pour supprimer la banniere">Mot de passe modifié !</div>';
	?>
	<section id="main">
		<article style="width:1000px; text-align:center; position:relative; margin-left:auto; margin-right:auto;">
			<h1><br><?php echo "Bonjour " . $login . " !"; ?></h1>
			<form action="modif.php" method="POST">
				<input placeholder="Ancien mot de passe" type=password name="oldpw" style="border:0px; text-align: center; width: 750px; height: 60px; font-size: 30px;" onkeyup="check();"><br><br>
				<input placeholder="Nouveau mot de passe" type=password id="newpass" name="newpw" style="border:0px; text-align: center; width: 750px; height: 60px; font-size: 30px;" onkeyup="check();"><br><br>
				<input placeholder="Confirmation" type=password id="newpasssec" name="newpwsec" style="border:0px; text-align: center; width: 750px; height: 60px; font-size: 30px;" onkeyup="check();"><br><br>
				<div id="state" style="text-align: center;"></div>
				<button class="button" id="send" name="submit" value="OK"><span><i class="fa fa-upload"></i> Valider</span></button>
			</form>
			<br>
			<br>
			<form id="dele" action="delete.php" method="POST">
				<button class="button" name="submit" value="delete" onclick="suppr();"><span><i class="fa fa-trash-o"></i> Supprimer definitivement mon compte </span></button>
			</form>
			<br>
		</article>
		<?php if ($type == 1) { ?>
		<article style="width:40vw; text-align:center; position:relative; margin-left:auto; margin-right:auto; top: 16px;">
			<a href="../admin">
				<div class="button" style="width: 40vw; font-size: 24px;">
					Acces au panel d'administration
				</div>
			</a>
		</article>
		<?php } ?>
		<?php if ( $type == 1 || $type == 2) { ?>
		<article style="width:40vw; text-align:center; position:relative; margin-left:auto; margin-right:auto; top: 16px;">
			<a href="../edit.php">
				<div class="button" style="width: 40vw; font-size: 24px;">
					Editions d'articles
				</div>
			</a>
		</article>
		<?php } ?>
	</section>
	<script>

	function check()
	{
		var pass1 = document.getElementById('newpass').value;
		var pass2 = document.getElementById('newpasssec').value;
		var output = document.getElementById("state");

		if (pass1 == '' || pass2 == '' || !pass1 || !pass2)
		{
			output.innerHTML = "Veuillez renseigner un mot de passe";
		}
		else if (pass1 != pass2)
		{
			output.innerHTML = "Les mots de passes ne correspondent pas !";
			output.style.color = "#c0392b";
		}
		else
		{
			output.innerHTML = '<i class="fa fa-check"></i>';
			output.style.color = "#27ae60";
		}
		enableSend();
	}

	function enableSend()
	{
		var pass1 = document.getElementById('newpass').value;
		var pass2 = document.getElementById('newpasssec').value;
		var send_button = document.getElementById('send').value;

		if (pass1 != '' && pass2 != '' && (pass1 == pass2))
		{
			send.removeAttribute("disabled");
		}
		else
		{
			send.setAttribute("disabled", "");
		}
	}

	function suppr_banner(banner)
	{
		banner.remove();
	}
	</script>
	<footer>
		<p>
			&copy; vthomas &amp; nsampre - 2017
		</p>
	</footer>
</html>
