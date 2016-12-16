<?php

$myFile="Command.txt";
$fh = fopen($myFile, 'w') or die ("Can not open the file");
fwrite($fh, "DISARM");
fclose($fh);
sleep(3);
$command = escapeshellcmd('python /var/www/html/disarm.py');
exec($command);
echo "System has been disarmed";

?>
