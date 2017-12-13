<?php

if ($_POST['action'] == 'changepw')
{
	if (!isset($_SESSION))
		session_start();
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/verify.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
	if ($_SESSION['login'] != '' || !isset($_POST['login']) || !isset($_POST['mail']) || !isset($_POST['hash']) || !isset($_POST['password']) || !isset($_POST['confirmation']) || $_POST['login'] == '' || $_POST['mail'] == '' || $_POST['hash'] == '' || $_POST['password'] == '' || $_POST['confirmation'] == '')
	{
		header("Location: /index.php");
		return ;
	}
	$login = htmlspecialchars($_POST['login'], ENT_QUOTES);
	$hash = htmlspecialchars($_POST['hash'], ENT_QUOTES);
	$mail = htmlspecialchars($_POST['mail'], ENT_QUOTES);
	$password = passwordify($login, $_POST['password']);
	$confirmation = passwordify($login, $_POST['confirmation']);
	$captcha = isValid();
	if ($captcha == false || $captcha == 0)
	{
		header("Location: ./change_pw.php?login=" . $login . '&mail=' . $mail . '&hash=' . $hash . "&error=WrongCaptcha");
		return ;
	}
	if ($password != $confirmation)
	{
		header("Location: ./change_pw.php?login=" . $login . '&mail=' . $mail . '&hash=' . $hash . "&error=WrongCredentialsFields");
		return ;
	}
	if (strlen($password) < 8)
	{
		header("Location: ./change_pw.php?login=" . $login . '&mail=' . $mail . '&hash=' . $hash . "&error=PasswordTooShort");
		return ;
	}
	if (!filter_var($mail, FILTER_VALIDATE_EMAIL))
	{
		header("Location: ./change_pw.php?login=" . $login . '&mail=' . $mail . '&hash=' . $hash . "&error=WrongConfirmationFields");
		return ;
	}
	date_default_timezone_set('Europe/Paris');
	$new_hash = hash("whirlpool", $login . "spicy" . date('m-d-Y-h-i-s-m', time()));
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query_result = $pdo->query("SELECT * FROM `user` WHERE `login` = '$login' AND `mail` = '$mail' AND `hash` = '$hash';");
		if ($query_result->rowCount() != 1)
		{
			header("Location: ./change_pw.php?login=" . $login . '&mail=' . $mail . '&hash=' . $hash . "&error=WrongConfirmationFields");
			return ;
		}
		$pdo->exec("UPDATE `user` SET `pass` = '$password' WHERE `login` = '$login' AND `mail` = '$mail' AND `hash` = '$hash';");
		$pdo->exec("UPDATE `user` SET `hash` = '$new_hash' WHERE `login` = '$login' AND `mail` = '$mail' AND `pass` = '$password';");
		header("Location: ./signin.php?error=ModifiedPassword");
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
	if ($_SESSION['login'] != '' || !isset($_GET['login']) || !isset($_GET['mail']) || !isset($_GET['hash']) || $_GET['login'] == '' || $_GET['mail'] == '' || $_GET['hash'] == '')
	{
		header("Location: /index.php");
		return ;
	}
}

?>

<script type="text/javascript">
	function enableSend()
	{
		var passwd = document.getElementById('passwd').value;
		var confirmation = document.getElementById('confirmation').value;
		var button = document.getElementById('button_sign_up').value;
		if (passwd != '' && passwd.length > 7 && confirmation != '' && (passwd == confirmation))
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
		var confirmation = document.getElementById('confirmation').value;
		var checker = document.getElementById("check_user_input");
		if (passwd.length < 8 && passwd.length > 0)
		{
			checker.innerHTML = "Password must be at least 8 character long.<br>";
			checker.style.color = "#c0392b";
		}
		else
		{
			checker.innerHTML = '';
		}
		if (passwd == '' || confirmation == '' || !passwd || !confirmation)
		{
			checker.innerHTML += 'Please fill in a password and a confirmation.<br>';
			checker.style.color = "#c0392b";
		}
		else if (passwd != confirmation)
		{
			checker.innerHTML += "Password and confirmation don't match.<br>";
			checker.style.color = "#c0392b";
		}
		else
		{
			checker.innerHTML += '';
		}
		enableSend();
	}
</script>

<html lang="en">
<head>
	<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/common_config.php"); ?>
	<script src="https://www.google.com/recaptcha/api.js" async defer></script>
	<title>Change Password</title>
</head>

<script type="text/javascript" src="change_pw.js"></script>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/header.php");?>

<body>
	<form action="./change_pw.php" method="POST">
		<table style="border:0px solid #000; margin-left: auto; margin-right: auto; position:relative; top: 2rem; text-align: center;">
			<tr>
				<td>
					<input style="display: none" type="text" name='login' value="<?php echo $_GET['login'];?>">
					<input style="display: none" type="text" name='mail' value="<?php echo $_GET['mail'];?>">
					<input style="display: none" type="text" name='hash' value="<?php echo $_GET['hash'];?>">
					<input placeholder="New password" id="passwd" type=password name="password" onkeyup="check();">
				</td>
			</tr>
			<tr>
				<td><input placeholder="Confirm" id="confirmation" type="password" name="confirmation" onkeyup="check();"></td>
			</tr>
			<tr>
				<td>
					<center><br>
						<button class="button" disabled="" id="button_sign_up" name="action" value="changepw"><span>Sign Up</span></button>
					</center>
				</td>
			</tr>
			<tr>
				<td style="padding: 10px"><div class="g-recaptcha" data-sitekey="6Lc0vykUAAAAAIqH5QWI_s4N3OHujbGbZTQd7Ekv"></div></td>
			</tr>
			<tr>
				<td id="check_user_input" style="text-align: center;"></td>
			</tr>
		</table>
	</form>
</body>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/footer.php"); ?>

</html>