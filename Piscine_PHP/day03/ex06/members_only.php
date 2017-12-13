<?php

if (!$_SERVER['PHP_AUTH_USER'] || $_SERVER['PHP_AUTH_USER'] != 'zaz' || $_SERVER['PHP_AUTH_PW'] != 'jaimelespetitsponeys')
{
    header('WWW-Authenticate: Basic realm="Espace membres"');
	header('Content-Type: text/html');
	header('HTTP/1.0 401 Unauthorized');
	header('Content-Length: 72');
	echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>";
    exit;
}

if ($_SERVER['PHP_AUTH_USER'] == 'zaz' && $_SERVER['PHP_AUTH_PW'] == 'jaimelespetitsponeys')
{
	echo "<html><body>Bonjour Zaz<br />";
	$b64image = base64_encode(file_get_contents('./img/42.png'));
	echo "<img src='data:image/png;base64," . $b64image . "'></body></html>";
}
