<?php

//Error description from GET method via javascript alert()

if (!isset($_GET['error']))
	return ;

if ($_GET['error'] == 'EmptyCredentialsFields')
{
	echo "<script>alert('The input is incorrectly filled.');</script>";
}
if ($_GET['error'] == 'WrongCredentialsFields')
{
	echo "<script>alert('The password does not match its confirmation.');</script>";
}
if ($_GET['error'] == 'WrongConfirmationFields')
{
	echo "<script>alert('This confirmation link is unvalid.');</script>";
}
if ($_GET['error'] == 'WrongEmail')
{
	echo "<script>alert('Incorrect email format submited.');</script>";
}
if ($_GET['error'] == 'WrongPassword')
{
	echo "<script>alert('Incorrect password submited.');</script>";
}
if ($_GET['error'] == 'PasswordTooShort')
{
	echo "<script>alert('The submited password is too short. It requires at least 8 characters.');</script>";
}
if ($_GET['error'] == 'LoginTooLong')
{
	echo "<script>alert('The submited login is too long. It requires at maximum 12 characters.');</script>";
}
if ($_GET['error'] == 'LoginTaken')
{
	echo "<script>alert('This login has already been taken.');</script>";
}
if ($_GET['error'] == 'ModifiedMail')
{
	echo "<script>alert('Your email was successfully modified.');</script>";
}
if ($_GET['error'] == 'ModifiedPassword')
{
	echo "<script>alert('Your password was successfully modified.');</script>";
}
if ($_GET['error'] == 'UnvalidConfirmation')
{
	echo "<script>alert('This confirmation link is invalid.');</script>";
}
if ($_GET['error'] == 'ActiveAccount')
{
	echo "<script>alert('Congrats ! You have enabled your account. Your can now signin.');</script>";
}
if ($_GET['error'] == 'UserNotFound')
{
	echo "<script>alert('This user is not registered.');</script>";
}
if ($_GET['error'] == 'NotActive')
{
	echo "<script>alert('This account has not been activated.');</script>";
}
if ($_GET['error'] == 'ConfirmationSent')
{
	echo "<script>alert('An email has been sent to activate your account.');</script>";
}
if ($_GET['error'] == 'WrongCaptcha')
{
	echo "<script>alert('Please correctly fill the captcha.');</script>";
}
if ($_GET['error'] == 'WrongLoginPattern')
{
	echo "<script>alert('Invalid login characters. Allowed: alphanumerical[a-zA-Z0-9] characters only.');</script>";
}
if ($_GET['error'] == 'ResetUserNotFound')
{
	echo "<script>alert('Impossible to send reset link. User not found.');</script>";
}
if ($_GET['error'] == 'ResetSent')
{
	echo "<script>alert('Reset password link has been sent.');</script>";
}
if ($_GET['error'] == 'SuccessfullInstall')
{
	echo "<script>alert('The database was successfully initialised.');</script>";
}

?>