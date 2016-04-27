<?php  

	$string = $_GET['string'];

	$file = fopen("lights.txt", "w") or die("can't open file");
	fwrite($file, $string);
	fclose($file);

?>