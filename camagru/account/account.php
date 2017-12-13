<?php

if ($_POST['action'] == 'modifpw')
{
	if (!isset($_SESSION))
		session_start();
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
	if (!isset($_POST['password']) || $_POST['password'] == '' || !isset($_POST['newpassword']) || $_POST['newpassword'] == '' || !isset($_POST['confirmation']) || $_POST['confirmation'] == '')
	{
		header("Location: ./account.php?error=EmptyCredentialsFields");
		return ;
	}
	if ($_POST['newpassword'] != $_POST['confirmation'])
	{
		header("Location: ./account.php?error=WrongCredentialsFields");
		return ;
	}
	if (strlen($_POST['newpassword']) < 8)
	{
		header("Location: ./account.php?error=PasswordTooShort");
		return ;
	}
	$login = htmlspecialchars($_SESSION['login'], ENT_QUOTES);
	$password = passwordify($login, $_POST['password']);
	$newpassword = passwordify($login, $_POST['newpassword']);
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query_result = $pdo->query("SELECT * FROM `user` WHERE `login` = '$login' AND `pass` = '$password';");
		if ($query_result->rowCount() != 1)
		{
			header("Location: ./account.php?error=WrongPassword");
			return ;
		}
		$pdo->exec("UPDATE `user` SET `pass` = '$newpassword' WHERE `login` = '$login';");
		$_SESSION['password'] = $newpassword;
		header("Location: ./account.php?error=ModifiedPassword");

	} catch (Exception $e) {
		echo "ERROR : " . $e->getMessage();
		die();
	}
}
else if ($_POST['action'] == 'modifmail')
{
	if (!isset($_SESSION))
		session_start();
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
	if (!isset($_POST['newmail']) || $_POST['newmail'] == '' || !isset($_POST['password_mail']) || $_POST['password_mail'] == '')
	{
		header("Location: ./account.php?error=EmptyCredentialsFields");
		return ;
	}
	if (!filter_var($_POST['newmail'], FILTER_VALIDATE_EMAIL))
	{
		header("Location: ./account.php?error=WrongEmail");
		return ;
	}
	$login = htmlspecialchars($_SESSION['login'], ENT_QUOTES);
	$password = passwordify($login, $_POST['password_mail']);
	$newmail = htmlspecialchars($_POST['newmail'], ENT_QUOTES);
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query_result = $pdo->query("SELECT * FROM `user` WHERE `login` = '$login' AND `pass` = '$password';");
		if ($query_result->rowCount() != 1)
		{
			header("Location: ./account.php?error=WrongPassword");
			return;
		}
		$pdo->query("UPDATE `user` SET `mail` = '$newmail' WHERE `login` = '$login';");
		header("Location: ./account.php?error=ModifiedMail");
	} catch (Exception $e) {
		echo "ERROR : " . $e->getMessage();
		die();
	}
}
else if ($_POST['action'] == 'deleteaccount')
{
	if (!isset($_SESSION))
		session_start();
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/redirect_to_signin.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
	$id = htmlspecialchars($_SESSION['id'], ENT_QUOTES);
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$pdo->exec("DELETE FROM `user` WHERE `id` = '$id';");
		$pdo->exec("DELETE FROM `images` WHERE `owner_id` = '$id';");
		$pdo->exec("DELETE FROM `likes` WHERE `owner_id` = '$id';");
		$pdo->exec("DELETE FROM `comments` WHERE `owner_id` = '$id';");
		header("Location: /index.php");
	} catch (Exception $e) {
		echo "ERROR : " . $e->getMessage();
		die();
	}
}
else
{
	if (!isset($_SESSION))
		session_start();
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/redirect_to_signin.php");
}

?>

<script>
	function enableSend()
	{
		var passwd = document.getElementById('passwd').value;
		var newpasswd = document.getElementById('newpasswd').value;
		var confirmation = document.getElementById('confirmation').value;
		var button = document.getElementById('button_sign_up').value;
		if (passwd != '' && newpasswd != '' && confirmation != '' && (newpasswd == confirmation))
		{
			button_sign_up.removeAttribute("disabled");
			button_sign_up.setAttribute("style", "background:white");
		}
		else
		{
			button_sign_up.setAttribute("disabled", "");
			button_sign_up.setAttribute("style", "color:greytext");	
		}
	}
	function check()
	{
		var passwd = document.getElementById('passwd').value;
		var newpasswd = document.getElementById('newpasswd').value;
		var confirmation = document.getElementById('confirmation').value;
		var checker = document.getElementById("check_user_input");
		if ((newpasswd != confirmation) && newpasswd)
		{
			checker.innerHTML = "Password and confirmation don't match.";
			checker.style.color = "#c0392b";
		}
		if (newpasswd == confirmation)
		{
			checker.innerHTML = '';
		}
		enableSend();
	}
	function check_mail()
	{
		var mail = document.getElementById('newmail').value;
		var pass = document.getElementById('password_mail').value;
		if (mail.length > 0 && pass.length > 0)
		{
			button_mail.removeAttribute('disabled');
			button_mail.setAttribute("style", "background:white");
		}
		else
		{
			button_mail.setAttribute('disabled', "");
			button_mail.setAttribute("style", "color:greytext");
		}
	}
	var CaptchaCallback = function() {
        grecaptcha.render('RecaptchaField1', {'sitekey' : '6Lc0vykUAAAAAIqH5QWI_s4N3OHujbGbZTQd7Ekv'});
        grecaptcha.render('RecaptchaField2', {'sitekey' : '6Lc0vykUAAAAAIqH5QWI_s4N3OHujbGbZTQd7Ekv'});
    };
</script>

<html lang="en">
<head>
	<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/common_config.php"); ?>
	<title>Account - The Camagru Project</title>
</head>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/header.php"); ?>
<body>
	<form action="./account.php" method="POST">
		<table style="border:0px solid #000; margin-left:auto; margin-right:auto; position:relative; top:2rem; text-align:center;">
			<tr>
				<td><input placeholder="Current password" id="passwd" type="password" name="password" onkeyup="check();"></td>
				<td id="check_user_input" colspan="2" style="text-align: center; position: absolute; margin-left: 50px"></td>
			</tr>
			<tr>
				<td><input placeholder="New password" id="newpasswd" type=password name="newpassword" onkeyup="check();"></td>
			</tr>
			<tr>
				<td><input placeholder="Confirm" id="confirmation" type="password" name="confirmation" onkeyup="check();"></td>
			</tr>
			<tr>
				<td colspan="2">
					<center><br>
						<button class="button" disabled id="button_sign_up" name="action" value="modifpw"><span>Change password</span></button>
					</center>
				</td>
			</tr>
		</table>
	</form>

	<form action="./account.php" method="POST">
		<table style="border:0px solid #000; margin-left:auto; margin-right:auto; position:relative; top:2rem; text-align:center;">
			<tr>
				<td><input type="email" placeholder="New mail" id="newmail" type="text" name="newmail" onkeyup="check_mail();"></td>
			</tr>
			<tr>
				<td><input placeholder="Password" id="password_mail" type="password" name="password_mail" onkeyup="check_mail();"></td>
			</tr>
			<tr>
				<td colspan="2">
					<center><br>
						<button class="button" disabled id="button_mail" name="action" value="modifmail"><span>Change email</span></button>
					</center>
				</td>
			</tr>
		</table>
	</form>

	<table style="text-align:center; margin-right:auto; margin-left:auto; margin-top:50px;">
		<tr>
			<td>
				<button class="button" disabled id="button_account">
					<a class="global_a" href="/social/my_photos.php">My Photos</a>
				</button>
			</td>
		</tr>
	</table>

	<div style="margin-top:30px; text-align:center; margin-right:auto; margin-left:auto;">
		<form action="./account.php" method="POST">
			<button class="button" id="button_delete" name="action" value="deleteaccount" onclick="return confirm('Are you sure ?');"><span>Delete my account</span></button>
		</form>
	</div>
</body>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/footer.php"); ?>

</html>