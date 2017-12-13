<?php

if ($_POST['action'] == "signin")
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
	if (!isset($_POST['login']) || $_POST['login'] == '' || !isset($_POST['password']) || $_POST['password'] == '')
	{
		header("Location: ./signin.php?error=EmptyCredentialsFields");
		return ;
	}
	$login = htmlspecialchars($_POST['login'], ENT_QUOTES);
	$password = passwordify($login, $_POST['password']);
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query_result = $pdo->query("SELECT * FROM `user` WHERE `login` = '$login' AND `pass` = '$password';");
		if ($query_result->rowCount() != 1)
		{
			$query_result = $pdo->query("SELECT * FROM `user` WHERE `login` = '$login';");
			if ($query_result->rowCount() != 1)
			{
				header("Location: ./signin.php?error=UserNotFound");
				return ;
			}
			else
			{
				header("Location: ./signin.php?error=WrongPassword");
				return ;
			}
		}
		$query_rows = $query_result->fetch(PDO::FETCH_ASSOC);
		if ($query_rows['active'] == 0)
		{
			header("Location: ./signin.php?error=NotActive");
			return ;
		}
		$_SESSION['login'] = $query_rows['login'];
		$_SESSION['password'] = $query_rows['pass'];
		$_SESSION['id'] = $query_rows['id'];
		$_SESSION['input'] = 'webcam';
		header("Location: /index.php");
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
	if (isset($_GET['error']))
		$error = $_GET['error'];
	else
		$error = '';
	if ($error == 'reset')
		echo '<script>alert(We sent you a reset link. Check your mail !);</script>';
}

?>

<script>
	function enableSignIn()
	{
		var login = document.getElementById('login_field').value;
		var passwd = document.getElementById('passwd').value;
		if (login != '' && passwd != '')
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
	<form action="./signin.php" method="post" autocomplete="on">
		<table style="border:0px solid #000; margin-left: auto; margin-right: auto; position:relative; top: 2rem; text-align: center;">
			<tr>
				<td>
					<input autofocus="autofocus" placeholder="Login" id="login_field" type=text name="login" onkeyup="enableSignIn();">
				</td>
			</tr>
			<tr>
				<td>

				</td>
			</tr>
			<tr>
				<td>
					<input placeholder="Password" id="passwd" type=password name="password" onkeyup="enableSignIn();">
				</td>
			</tr>
			<tr>
				<td>
					<center><br>
						<button class="button" disabled="" id="button_sign_up" name="action" value="signin"><span>Sign in</span></button>
					</center>
				</td>
			</tr>
			<tr>
				<td style="padding: 10px"><div class="g-recaptcha" data-sitekey="6Lc0vykUAAAAAIqH5QWI_s4N3OHujbGbZTQd7Ekv"></div></td>
			</tr>
			<tr>
				<td><a class="global_a" href="./reset_pw.php">iForgotMyPassword</a></td>
			</tr>
		</table>
	</form>
</body>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/includes/footer.php"); ?>

</html>