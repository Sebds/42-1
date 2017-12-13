<?php

session_start();

if(!empty($_SESSION['login']))
	echo $_SESSION['login'];
else
	echo "UNCONNECTED";

?>