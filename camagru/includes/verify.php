<?php

function isValid()
{
	return true;
	try {

		$url = 'https://www.google.com/recaptcha/api/siteverify';
		$data = ['secret'   => '6Lc0vykUAAAAACkvXCCkP0feFCy8JfdAbPXJGC-t',
				 'response' => $_POST['g-recaptcha-response'],
				 'remoteip' => $_SERVER['REMOTE_ADDR']];

		$options = [
			'http' => [
				'header'  => "Content-type: application/x-www-form-urlencoded\r\n",
				'method'  => 'POST',
				'content' => http_build_query($data) 
			]
		];

		$context  = stream_context_create($options);
		$result = file_get_contents($url, false, $context);
		return json_decode($result)->success;
	}
	catch (Exception $e) {
		echo ("The captcha verification went wrong.");
	}
}

?>