#!/usr/bin/php
<?php
if ($argc != 2)
	exit;

$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $argv[1]);
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
$html = curl_exec($ch);
$html = explode("\n", $html);
curl_close($ch);

$dir = $argv[1];

if (preg_match("@^http://@", $dir))
	$dir = preg_replace("@^http://@", '', $dir);

if (preg_match("@^https://@", $dir))
	$dir = preg_replace("@^https://@", '', $dir);

if (file_exists($dir))
	exit;

foreach($html as $line)
{
	if (preg_match("@<img.*?src=\"(.*?)\"@", $line, $matches))
	{
		if (file_exists($dir) == false)
			mkdir($dir);
		array_shift($matches);
		foreach($matches as $line)
		{
			if (preg_match("@^http://@", $line) == false && preg_match("@^https://@", $line) == false)
			{
				$line = "http://" . $dir . "/" . $line;
			}
			$match = preg_match('@([^/]+(?=[^/.]*$)|[^/.]+$)@', $line, $name);
            $name = $dir . "/" . $name[1];
			$fp = fopen($name, "x+");
			$ch = curl_init($line);
			curl_setopt($ch, CURLOPT_HEADER, 0);
			curl_setopt($ch, CURLOPT_FILE, $fp);
			curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
			curl_exec($ch);
			curl_close($ch);
			fclose($fp);
		}
	}
}
?>