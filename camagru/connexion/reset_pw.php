<?php

if ($_POST['action'] == "resetpw")
{
	if (!isset($_SESSION))
		session_start();
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/verify.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
	$captcha = isValid();
	if ($captcha == false || $captcha == 0)
	{
		header("Location: ./reset_pw.php?error=WrongCaptcha");
		return ;
	}
	if ($_SESSION['login'] != '' || !isset($_POST['login']) || $_POST['login'] == '')
	{
		header("Location: ./reset_pw.php?error=EmptyCredentialsFields");
		return ;
	}
	$login = htmlspecialchars($_POST['login'], ENT_QUOTES);
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query_result = $pdo->query("SELECT * FROM `user` WHERE `login` = '$login';");
		$query_row = $query_result->fetch(PDO::FETCH_ASSOC);
		if ($query_result->rowCount() != 1)
		{
			header("Location: ./reset_pw.php?error=ResetUserNotFound");
			return ;
		}
		date_default_timezone_set('Europe/Paris');
		$hash = hash("whirlpool", $login . "spicy" . date('m-d-Y-h-i-s-m', time()));
		$pdo->exec("UPDATE `user` SET `hash` = '$hash' WHERE `login` = '$login';");
		$to      = $query_row['mail'];
		$subject = 'The Camagru Project | Reset Request';
		$message = '

Someone requested your account to be reset, to set a new password, please click on the url below.<br><br>

<a href=http://localhost:8080/connexion/change_pw.php?login=' . $login . '&mail=' . $to . '&hash=' . $hash .'>Reset my password.</a><br><br>

The Camagru Team.
';
		$headers = 'From:camagru@42.fr' . "\r\n";
		$headers .= "Reply-To:camagru@42.fr\r\n";
		$headers .= "MIME-Version: 1.0\r\n";
		$headers .= "Content-Type: text/html; charset=utf-8\r\n";
		// mail($to, $subject, $message, $headers);
		echo $message;
		// header("Location: /index.php?error=ResetSent");
		return ;
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
	if ($_SESSION['login'] != '')
	{
		header("Location: /index.php");
		return ;
	}
}

?>

<script>
	function enableSignIn()
	{
		var login = document.getElementById('login_field').value;
		if (login != '')
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
</script>

<html lang="en">
<head>
	<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/common_config.php"); ?>
	<script src="https://www.google.com/recaptcha/api.js" async defer></script>
	<title>Sign In</title>
</head>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/header.php");?>

<body>
	<form action="./reset_pw.php" method="post">
		<table style="border:0px solid #000; margin-left: auto; margin-right: auto; position:relative; top: 2rem; text-align: center;">
			<tr>
				<td>
					<input placeholder="Login" id="login_field" type=text name="login" onkeyup="enableSignIn();" autocomplete="off">
				</td>
			</tr>
			<tr>
				<td>
					<center><br>
						<button class="button" id="button_sign_up" name="action" value="resetpw"><span>Send a reset link</span></button>
					</center>
				</td>
			</tr>
			<tr>
				<td style="padding: 10px"><div class="g-recaptcha" data-sitekey="6Lc0vykUAAAAAIqH5QWI_s4N3OHujbGbZTQd7Ekv"></div></td>
			</tr>
		</table>
	</form>
</body>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/footer.php"); ?>

</html>