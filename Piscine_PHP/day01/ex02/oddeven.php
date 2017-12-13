#!/usr/bin/php
<?php
$stdin = fopen('php://stdin', 'r');
echo "Entrez un nombre: ";
while (($buffer = fgets($stdin, 4096)) !== false)
{
	$buffer = rtrim($buffer,"\n");
	if (is_numeric($buffer) == true)
	{
		if ($buffer[strlen($buffer) - 1] % 2 == 0)
			echo "Le chiffre " . $buffer . " est Pair\n";
		else
			echo "Le chiffre " . $buffer . " est Impair\n";
	}
	else
		echo "'" . $buffer . "' n'est pas un chiffre\n";
	echo "Entrez un nombre: ";
}
echo "\n";
?>