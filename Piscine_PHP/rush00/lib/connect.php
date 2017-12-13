<?php
	session_start();
?>
<html>
<?php
	include ("../inc/lib_header.php");
	if ($_GET['error'] == 'login')
		echo '<div class="banner error" onclick="this.remove()" title="Clickez pour supprimer la banniere">Cet identifiant existe deja</div>';
	if ($_GET['error'] == 'connect')
		echo '<div class="banner error" onclick="this.remove()" title="Clickez pour supprimer la banniere">Combinaison login/mdp invalide.</div>';
	if ($_GET['error'] == 'ban')
		echo '<div class="banner error" onclick="this.remove()" title="Clickez pour supprimer la banniere">Vous avez &eacute;t&eacute; banni. Veuillez contacter l\'administrateur</div>';
	?>
	<section id="main">
		<article style="text-align: center; width: 1000px; position:relative; margin-left: auto; margin-right: auto;">
			<h1><br>Connection:</h1>
			<form action="./try_connect.php" method="post">
			<table style="border:0px solid #000; margin-left: auto; margin-right: auto;">
				<tr>
					<td>
						<input placeholder="Login" type=text name="login" autocomplete="off" style="border:0px; text-align: center; width:750px; height: 60px; font-size: 30px;">
					</td>
				</tr>
				<tr>
					<td>
						<input placeholder="Mot de passe" type=password name="password" style="border:0px; text-align: center; width: 750px; height: 60px; font-size: 30px;">
					</td>
				</tr>
				<tr>
					<td colspan="2"><center><br>
						<button class="button">
							<span><i class="fa fa-sign-in"></i> Se connecter...</span>
						</button></center>
					</td>
				</tr>
			</table>
			</form>
			<br><br>
		</article>
		<article style="text-align:center; width: 1000px; position:relative; margin-left: auto; margin-right: auto;">
			<h1><br>Pas encore membre ? Inscrivez vous !</h1>
			<form action="./signup.php" method="post">
				<table style="border:0px solid #000; margin-left: auto; margin-right: auto;">
					<tr>
						<td><input placeholder="Login" id="login_new" type=text name="login" style="border:0px; text-align: center; width:750px; height: 60px; font-size: 30px;" onkeyup="check();"></td>
					</tr>
					<tr>
						<td><input placeholder="Mot de passe" id="firpass" type=password name="password" style="border:0px; text-align: center; width:750px; height: 60px; font-size: 30px;" onkeyup="check();"></td>
					</tr>
					<tr>
						<td><input id="secpass" placeholder="Confirmation" type="password" name="secpassword" style="border:0px; text-align: center; width:750px; height: 60px; font-size: 30px;" onkeyup="check();"></td>
					</tr>
					<tr>
						<td><center><br>Compte vendeur : <input type="checkbox" name="salesman" value=2 style="border:0px; text-align: center;"></center></td>
					</tr>
					<tr>
						<td id="state" colspan="2" style="text-align: center;"></td>
					</tr>
					<tr>
						<td colspan="2"><center><br>
							<button class="button" disabled="" id="send">
								<span><i class="fa fa-user-plus"></i> S'inscrire</span>
							</button></center>
						</td>
					</tr>
				</table>
			</form>
			<br>
			<br>
		</article>
	</section>
	<script>
	function check()
	{
		var pass1 = document.getElementById('firpass').value;
		var pass2 = document.getElementById('secpass').value;
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
		var pass1 = document.getElementById('firpass').value;
		var pass2 = document.getElementById('secpass').value;
		var log = document.getElementById('login_new').value;
		var send_button = document.getElementById('send').value;

		if (pass1 != '' && pass2 != '' && log != '' && (pass1 == pass2))
		{
			send.removeAttribute("disabled");
		}
		else
		{
			send.setAttribute("disabled", "");
		}
	}
	</script>
	<footer>
		<p>
			&copy; vthomas &amp; nsampre - 2017
		</p>
	</footer>
</html>
