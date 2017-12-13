<?php

if ($_POST['action'] == "signup")
{
	if (!isset($_SESSION))
		session_start();
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/connexion.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/includes/verify.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/config/database.php");
	$captcha = isValid();
	if ($captcha == false || $captcha == 0)
	{
		header("Location:" . $_SERVER['HTTP_REFERER'] . "?error=WrongCaptcha");
		return ;
	}
	if (!isset($_POST['login']) || $_POST['login'] == '' ||
		!isset($_POST['password']) || $_POST['password'] == '' ||
		!isset($_POST['confirmation']) || $_POST['confirmation'] == '' ||
		!isset($_POST['email']) || $_POST['email'] == '')
	{
		header("Location: ./signup.php?error=EmptyCredentialsFields");
		return ;
	}
	if ($_POST['password'] != $_POST['confirmation'])
	{
		header("Location: ./signup.php?error=WrongCredentialsFields");
		return ;
	}
	if (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL))
	{
		header("Location: ./signup.php?error=WrongEmail");
		return ;
	}
	if (preg_match("/^[a-zA-Z0-9]+$/", $_POST['login']) == 0)
	{
		header("Location: ./signup.php?error=WrongLoginPattern");
		return ;
	}
	if (strlen($_POST['login']) > 12)
	{
		header("Location: ./signup.php?error=LoginTooLong");
		return ;
	}
	if (strlen($_POST['password']) < 8)
	{
		header("Location: ./signup.php?error=PasswordTooShort");
		return ;
	}
	$login = htmlspecialchars($_POST['login'], ENT_QUOTES);
	$password = passwordify($login, $_POST['password']);
	$mail = htmlspecialchars($_POST['email'], ENT_QUOTES);
	date_default_timezone_set('Europe/Paris');
	$hash = hash("whirlpool", $login . "spicy" . date('m-d-Y-h-i-s-m', time()));
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query_result = $pdo->query("SELECT * FROM `user` WHERE `login` = '$login';");
		if ($query_result->rowCount() != 0)
		{
			header("Location: ./signup.php?error=LoginTaken");
			return;
		}
		$pdo->exec("INSERT INTO `user` (`id`, `login`, `pass`, `mail`, `hash`, `active`) VALUES (NULL, '$login', '$password', '$mail', '$hash', '0');");
		$to      = $mail;
		$subject = 'The Camagru Project | Sign Up Confirmation';
		$message = '

Thanks for signing up to The Camagru Project !<br><br>

Your account has been created, you can login after you have activated your account by clicking on the url below.<br><br>

<a href=http://localhost:8080/connexion/confirm.php?login=' . $login . '&mail=' . $mail . '&hash=' . $hash .'>Activate my account.</a><br><br>

	The Camagru Team.
';
		$headers = 'From:camagru@42.fr' . "\r\n";
		$headers .= "Reply-To:camagru@42.fr\r\n";
		$headers .= "MIME-Version: 1.0\r\n";
		$headers .= "Content-Type: text/html; charset=utf-8\r\n";
		// mail($to, $subject, $message, $headers);
		echo $message;
		// header("Location: ./signin.php?error=ConfirmationSent");
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
}

?>

<html lang="en">
<head>
	<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/common_config.php"); ?>
	<script src="https://www.google.com/recaptcha/api.js" async defer></script>
	<title>Sign Up</title>
</head>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/header.php"); ?>

<script>
	function enableSend()
	{
		var login = document.getElementById('login_field').value;
		var email = document.getElementById('email_field').value;
		var passwd = document.getElementById('passwd').value;
		var confirmation = document.getElementById('confirmation').value;
		var button = document.getElementById('button_sign_up').value;
		if (passwd != '' && passwd.length > 7 && confirmation != '' && login != '' && login.length < 12 && email != '' && (passwd == confirmation))
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
		var	login = document.getElementById('login_field').value;
		var passwd = document.getElementById('passwd').value;
		var confirmation = document.getElementById('confirmation').value;
		var checker = document.getElementById("check_user_input");
		if (login.length > 12)
		{
			checker.innerHTML =  'Login must be 12 character long at maximum.<br>';
			checker.style.color = "#c0392b";
		}
		else
		{
			checker.innerHTML = '';
			checker.style.color = "#000000";
		}
		if (passwd.length < 8 && passwd.length > 0)
		{
			checker.innerHTML += "Password must be at least 8 character long.<br>";
			checker.style.color = "#c0392b";
		}
		if (passwd == '' || confirmation == '' || !passwd || !confirmation)
		{
			checker.innerHTML += 'Please fill in a password and a confirmation.<br>';
			checker.style.color = "#c0392b";
		}
		else if (login && (passwd != confirmation))
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

<body>
	<form action="./signup.php" method="post" autocomplete="on">
		<table style="border:0px solid #000; margin-left: auto; margin-right: auto; position:relative; top: 2rem; text-align: center;">
			<tr>
				<td><input autofocus="autofocus" placeholder="Login" id="login_field" type=text name="login" onkeyup="check();" autocomplete="on"></td>
			</tr>
			<tr>
				<td><input type="email" placeholder="Email" id="email_field" type=text name="email" onkeyup="check();" autocomplete="on"></td>
			</tr>
			<tr>
				<td>

				</td>
			</tr>
			<tr>
				<td><input placeholder="Password" id="passwd" type=password name="password" onkeyup="check();"></td>
			</tr>
			<tr>
				<td><input placeholder="Confirm" id="confirmation" type="password" name="confirmation" onkeyup="check();"></td>
			</tr>
			<tr>
				<td>
					<center><br>
						<button class="button" disabled="" id="button_sign_up" name="action" value="signup"><span>Sign Up</span></button>
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